#include "tomasulo.h"
#include <cstdlib>

using namespace std;

string itoa(int n)
{
	int tmp;
	char r[4];
	
	int i = 0;
	if (n > 100) {
		tmp = n / 100;
		r[i] = tmp + '0';
		i ++;
		n = n % 100;
	}
	tmp = n / 10;
	n = n % 10;
	if (tmp > 0) {
		r[i] = tmp + '0';
		i ++;
	}
	r[i] = n + '0';
	i ++;
	r[i] = '\0';
	return string(r);
}

Tomasulo::Tomasulo(int na, int nm, int nl, int ns, int nr,
                   int ea, int ecs, int em, int ed, int el, int es)
            : numberOfAdd(na), numberOfMul(nm), numberOfLB(nl), numberOfSB(ns), numberOfRegister(nr),
              exeCycleAdd(ea), exeCycleSub(ecs), exeCycleMul(em), exeCycleDiv(ed), exeCycleLD(el), exeCycleST(es)
{
	insToIssue = 0;
	headIndex = 0;
	numberOfInstruction = 0;
    currentTime = 0;
    numberOfRS = numberOfAdd + numberOfMul;
    init();
}

void Tomasulo::init()
{   
    RS = new ReservationStation[numberOfRS];
    LB = new LoadBuffer[numberOfLB];
    SB = new StoreBuffer[numberOfSB];
    RSFlag = new bool[numberOfRS];
    LBFlag = new bool[numberOfLB];
    SBFlag = new bool[numberOfSB];

    RegisterStat = new Register[numberOfRegister];

    for (int i = 0; i != numberOfAdd; i ++) {
        RS[i].name = string("Add" + itoa(i));
        RS[i].vrStatus = VR_FREE;
        RS[i].fuType = FU_ADDER;
        RS[i].Qj = BLANK;
        RS[i].Qk = BLANK;
    }
    for (int i = 0; i != numberOfMul; i ++) {
        RS[numberOfAdd + i].name = string("Mult" + itoa(i));
        RS[numberOfAdd + i].fuType = FU_MULTER;
        RS[numberOfAdd + i].vrStatus = VR_FREE;
        RS[numberOfAdd + i].Qj = BLANK;
        RS[numberOfAdd + i].Qk = BLANK;
    }

    for (int i = 0; i != numberOfLB; i ++) {
        LB[i].name = string("Load" + itoa(i));
        LB[i].vrStatus = VR_FREE;
        LB[i].Qj = BLANK;
    }
    for (int i = 0; i != numberOfSB; i ++) {
        SB[i].name = string("Store" + itoa(i));
        SB[i].vrStatus = VR_FREE;
        SB[i].Qk = BLANK;
		SB[i].Qj = BLANK;
    }

    for (int i = 0; i != numberOfRegister; i ++) {
        RegisterStat[i].name = string("F" + itoa(2 * i));
        RegisterStat[i].Qi = BLANK;
    }
}

void Tomasulo::singleStep()
{
    if (isFinished()) {
        return;
    }
    currentTime ++;
    
    clearFlag();
    cdb.setFree();

    issue();
    execute();
    writeResult();
}

bool Tomasulo::isFinished()
{
    int sz = insQueue.size();
    bool result = true;
    if (insToIssue == sz) {
        for (int i = 0; i != numberOfRS; i ++) {
            if (RS[i].vrStatus != VR_FREE) {
                result = false;
                break;
            }
        }
        if (result) {
            for (int i = 0; i != numberOfLB; i ++) {
                if (LB[i].vrStatus != VR_FREE) {
                    result = false;
                    break;
                }
            }
        }
        if (result) {
            for (int i = 0; i != numberOfSB; i ++) {
                if (SB[i].vrStatus != VR_FREE) {
                    result = false;
                    break;
                }
            }
        }
    }
    else {
        result = false;
    }
    return result;
}

void Tomasulo::clearFlag()
{
    for (int i = 0; i != numberOfRS; i ++) 
        RSFlag[i] = false;
    for (int i = 0; i != numberOfLB; i ++) 
        LBFlag[i] = false;
    for (int i = 0; i != numberOfSB; i ++) 
        SBFlag[i] = false;
}

void Tomasulo::multipleSteps(int step)
{
    for (int i = 0; i != step && !isFinished(); i ++)
        singleStep();
}

void Tomasulo::issue()
{
    if (insQueue.empty() || insToIssue == numberOfInstruction)
        return;
    if (insQueue[insToIssue].opType == OP_NOP) {   // Ignore NOP instruction
        insToIssue ++;
        return;
    }
    int r = findFree(insQueue[insToIssue].opType);
    if (r < 0)  //  Can't find free virtual regiter to issue the instruction
        return;
    issueInstruciton(r, insQueue[insToIssue]);
//    cout << "Issue " << r << endl;
}

int Tomasulo::findFree(OP_TYPE ot)
{
	int i;
	switch (ot) {
		case OP_ADD:
		case OP_SUB:
			for(i = 0; i != numberOfRS; i ++) {
				if (RS[i].vrStatus == VR_FREE && RS[i].fuType == FU_ADDER)
					return i;
			}
			return -1;
			break;

		case OP_MUL:
		case OP_DIV:
			for (i = 0; i != numberOfRS; i ++) {
				if (RS[i].vrStatus == VR_FREE && RS[i].fuType == FU_MULTER)
					return i;
			}
			return -1;
			break;
		
		case OP_LD:
			for (i = 0; i != numberOfLB; i ++) {
				if (LB[i].vrStatus == VR_FREE)
					return i;
			}
			return -1;
			break;

		case OP_ST:
			for (i = 0; i != numberOfSB; i ++) {
				if (SB[i].vrStatus == VR_FREE)
					return i;
			}
			return -1;
			break;
		default:
			return -1;
	}
	return -1;
}

void Tomasulo::issueInstruciton(int r, const Instruction& ins)
{
    int rs = ins.rs;
    int rt = ins.rt;
    int rd = ins.rd;
    int imm = ins.imm;

    switch(ins.opType) {
    case OP_ADD:
    case OP_SUB:
    case OP_MUL:
    case OP_DIV:
//          RS[r].restCycle = insQueue[insToIssue].exeCycle;
		RS[r].insNum = insToIssue;	// Record the instruction number in instruction array
        insQueue[insToIssue].issueTime = currentTime;

        RS[r].opType = ins.opType;
        RS[r].restCycle = ins.exeCycle;
        RS[r].vrStatus = VR_ISSUE;
        if (RegisterStat[rs].Qi != BLANK) {
            RS[r].Qj = RegisterStat[rs].Qi;
			RS[r].Rj = RegisterStat[rs].Ri;
        }
        else {
            if (RegisterStat[rs].value == string())
                RS[r].Vj = "R[F" + itoa(rs * 2) + "]";
            else
                RS[r].Vj = RegisterStat[rs].value;
            RS[r].Qj = BLANK;
        }
        if (RegisterStat[rt].Qi != BLANK) {
            RS[r].Qk = RegisterStat[rt].Qi;
			RS[r].Rk = RegisterStat[rt].Ri;
        }
        else {
            if (RegisterStat[rt].value == string())
                RS[r].Vk = "R[F" + itoa(rt * 2) + "]";
            else
                RS[r].Vk = RegisterStat[rt].value;
            RS[r].Qk = BLANK;
        }
        RegisterStat[rd].Qi = r;
		RegisterStat[rd].Ri = R;
        RSFlag[r] = true;
        break;
    
    case OP_LD:
		LB[r].insNum = insToIssue;
		LB[r].restCycle = insQueue[insToIssue].exeCycle;
		loadStoreArr.push_back(insToIssue);	// Push load instruction's index into load-store array
		insQueue[insToIssue].issueTime = currentTime;
        LB[r].restCycle = ins.exeCycle;
        LB[r].vrStatus = VR_ISSUE;
        LB[r].A = itoa(imm);
   //     if (RegisterStat[rs].Qi != BLANK) {
   //         LB[r].Qj = RegisterStat[rs].Qi;
   //			LB[r].Rj = RegisterStat[rs].Ri;
   //     }
   //     else {
        LB[r].Vj = "R" + itoa(rs);
        LB[r].Qj = BLANK;
   //     }
        RegisterStat[rt].Qi = r;
		RegisterStat[rt].Ri = L;
        LBFlag[r] = true;
      //  LB[r].name = itoa(LB[r].A);
      //  cout << "Issue LD " << endl;
        break;
    
    case OP_ST:
		loadStoreArr.push_back(insToIssue);	// Push store instruction's index into laod-store array
		SB[r].restCycle = insQueue[insToIssue].exeCycle;
		SB[r].insNum = insToIssue;
		insQueue[insToIssue].issueTime = currentTime;
        SB[r].restCycle = ins.exeCycle;
        SB[r].vrStatus = VR_ISSUE;
        SB[r].A = itoa(imm);
  //      if (RegisterStat[rs].Qi != BLANK) {
  //          SB[r].Qj = RegisterStat[rs].Qi;
 //			SB[r].Rj = RegisterStat[rs].Ri;
  //      }
   //     else {
            SB[r].Vk = "R" + itoa(rt);
            SB[r].Qk = BLANK;
   //     }
        if (RegisterStat[rs].Qi != BLANK) {
            SB[r].Qj = RegisterStat[rs].Qi;
            SB[r].Rj = RegisterStat[rs].Ri;
        }
        else {
            if (RegisterStat[rs].value == string())
                RS[r].Vj = "R[F" + itoa(rs * 2) + "]";
            else
                SB[r].Vj = RegisterStat[rs].value;
            SB[r].Qj = BLANK;
        }
        SBFlag[r] = true;
        break;
    case OP_NOP:
        break;
    }
	insToIssue ++;
}

void Tomasulo::execute()
{
    // Reservation Station
    for (int i = 0; i != numberOfRS; i ++) {
        if (!RSFlag[i] && RS[i].vrStatus == VR_ISSUE && (RS[i].Qj == BLANK && RS[i].Qk == BLANK)) {
			insQueue[RS[i].insNum].exeStartTime = currentTime;
			RS[i].vrStatus = VR_EXE;
            RS[i].restCycle --;
            RSFlag[i] = true;
        }
        else if (!RSFlag[i] && RS[i].vrStatus == VR_EXE && RS[i].restCycle > 0) {
            RS[i].restCycle --;
            RSFlag[i] = true;
        }
        else {
            if (RS[i].vrStatus != VR_FREE && RS[i].restCycle == 0) {
                // Add, Sub, Mul, Div here to get result
                RS[i].vrStatus = VR_WR;
                insQueue[RS[i].insNum].exeEndTime = currentTime - 1;
            }
        }
    }

    int sz = loadStoreArr.size();
    if (!loadStoreArr.empty() && headIndex < sz ) {	// Load-store array is not emtpy and instruction in it has not been run out
    //    cout << "size = " << sz << " HeadIndex = " << headIndex << endl;
        int i = loadStoreArr[headIndex];
        if (insQueue[i].opType == OP_LD) {
            for (int k = 0; k != numberOfLB; k ++) { // Find Load buffer that stores header of load-store instruction queue
                if (LB[k].vrStatus == VR_ISSUE && LB[k].insNum == i) {
                   i = k;
                   break;
                }
            }
            if (!LBFlag[i] && LB[i].Qj == BLANK && LB[i].vrStatus == VR_ISSUE) {
                LB[i].A = LB[i].Vj + " + " + LB[i].A;
            //    LB[i].name = "R" + itoa(LB[i].Vj) + "+" + LB[i].name;
                LB[i].vrStatus = VR_EXE;
                LB[i].restCycle --;
                insQueue[LB[i].insNum].exeStartTime = currentTime;
                LBFlag[i] = true;
                headIndex ++;
      //          cout << "in head(LD)" << "time = " << currentTime << endl;
            }
        }
        else if (insQueue[i].opType == OP_ST) {
            for (int k = 0; k != numberOfSB; k ++) {
                if (SB[k].vrStatus == VR_ISSUE && SB[k].insNum == i) {
                    i = k;
                    break;
                }
            }
            if (!SBFlag[i] && SB[i].Qj == BLANK && SB[i].vrStatus == VR_ISSUE) {
                SB[i].A = SB[i].Vj + " + " + SB[i].A;
             //   SB[i].name = "R"+itoa(SB[i].Vj) + "+" + SB[i].name;
                SB[i].vrStatus = VR_EXE;
                SB[i].restCycle --;
                insQueue[SB[i].insNum].exeStartTime = currentTime;
                SBFlag[i] = true;
        //        cout << "in head(ST) " << "time = " << currentTime << endl;
                headIndex ++;
            }
        }
        else {
          //  cout <<"ELSE" << endl;
        }

    }

    // Load Buffer
    for (int i = 0; i != numberOfLB; i ++) {
        if (!LBFlag[i] && LB[i].vrStatus == VR_EXE && LB[i].restCycle > 0) {
            LB[i].restCycle --;
            LBFlag[i] = true;
         //   cout << "tim = " << currentTime << endl;
        }
        else {
            if (LB[i].vrStatus == VR_EXE && LB[i].restCycle == 0) {
                insQueue[LB[i].insNum].exeEndTime = currentTime - 1;
                LB[i].result = "M[" + LB[i].A + "]";
                LB[i].vrStatus = VR_WR;
          //      cout << "In load buffer" << "time = " << currentTime << endl;
            }
        }
    }
    // Store Buffer
    for (int i = 0; i != numberOfSB; i ++) {
      //  cout << "SBFlag[ << i" << "]= " << SBFlag[i]  <<endl;
      //  cout << "status " << SB[i].vrStatus << endl;
        // cout << "Restcycle " <<
        if (!SBFlag[i] && SB[i].vrStatus == VR_EXE && SB[i].restCycle > 0) {
            SB[i].restCycle --;
            SBFlag[i] = true;
        //    cout <<"EXE (SB) " << SB[i].restCycle << endl;
        }
        else {
            if (SB[i].vrStatus == VR_EXE && SB[i].restCycle == 0) {
                insQueue[SB[i].insNum].exeEndTime = currentTime - 1;
                SB[i].vrStatus = VR_WR;
          //      cout << "In store buffer " << "time = " << currentTime << endl;
            }
        }
    }
}

void Tomasulo::writeResult()
{
    for (int i = 0; i != numberOfRS; i ++) {
        if (!RSFlag[i] && RS[i].vrStatus == VR_WR && cdb.getCDB()) {
            insQueue[RS[i].insNum].writeTime = currentTime;
            sendData(R, i, RS[i].result);
            RSFlag[i] = true;
            RS[i].vrStatus = VR_FREE;
            RS[i].Qj = BLANK;
            RS[i].Qk = BLANK;
        }
    }
    for (int i = 0; i != numberOfLB; i ++) {
        if (!LBFlag[i] && LB[i].vrStatus == VR_WR && cdb.getCDB()) {
            insQueue[LB[i].insNum].writeTime = currentTime;
            //cout << "InsNum = " << LB[i].vrStatus << endl;
            sendData(L, i, LB[i].result);
            LBFlag[i] = true;
            LB[i].vrStatus = VR_FREE;
            LB[i].Qj = BLANK;
        }
    }

    for (int i = 0; i != numberOfSB; i ++) {
        if (!SBFlag[i] && SB[i].vrStatus == VR_WR && SB[i].Qk == BLANK) {
            insQueue[SB[i].insNum].writeTime = currentTime;
      //      cout << "In SB" << endl;
            SB[i].vrStatus = VR_FREE;
            SB[i].Qj = BLANK;
            SB[i].Qk = BLANK;
            SBFlag[i] = true;
        }
    }
}

void Tomasulo::sendData(R_TYPE rType, int r, string result)
{
    for (int i = 0; i != numberOfRegister; i ++) {
        if (RegisterStat[i].Qi == r && RegisterStat[i].Ri == rType) {
            RegisterStat[i].Qi = BLANK;
            RegisterStat[i].value = result;
        }
    }
    for (int i = 0; i != numberOfRS; i ++) {
        if (RS[i].Qj == r && RS[i].Rj == rType) {
            RS[i].Vj = result;
            RS[i].Qj = BLANK;
        }
        if (RS[i].Qk == r && RS[i].Rk == rType) {
            RS[i].Vk = result;
            RS[i].Qk = BLANK;
        }
    }
    for (int i = 0; i != numberOfLB; i ++) {
        if (LB[i].Qj == r && LB[i].Rj == rType) {
            LB[i].Vj = result;
            LB[i].Qj = BLANK;
        }
    }
    for (int i = 0; i != numberOfSB; i ++) {
        if (SB[i].Qj == r && SB[i].Rj == rType) {
            SB[i].Vj = result;
            SB[i].Qj = BLANK;
        }
        if (SB[i].Qk == r && SB[i].Rk == rType) {
            SB[i].Vk = result;
            SB[i].Qk = BLANK;
        }
    }
}

/**
 * Destructor
 */
Tomasulo::~Tomasulo() 
{
  //  cout << "Delete Tom" << endl;
    delete[] RS;
    delete[] LB;
    delete[] SB;
    delete[] RSFlag;
    delete[] LBFlag;
    delete[] SBFlag;
    delete[] RegisterStat;
}

void Tomasulo::start(vector<Instruction> &iq)
{
    for (vector<Instruction>::size_type i = 0; i != iq.size(); i ++) {
		switch(iq[i].opType) {
			case OP_ADD:
				iq[i].exeCycle = exeCycleAdd;
				break;
			case OP_SUB:
				iq[i].exeCycle = exeCycleSub;
				break;
			case OP_MUL:
				iq[i].exeCycle = exeCycleMul;
				break;
			case OP_DIV:
				iq[i].exeCycle = exeCycleDiv;
				break;
			case OP_LD:
				iq[i].exeCycle = exeCycleLD;
				break;
			case OP_ST:
				iq[i].exeCycle = exeCycleST;
				break;
			default:
				iq[i].exeCycle = 0;
		}
		if (iq[i].opType != OP_NOP)
			insQueue.push_back(iq[i]);
       // if (iq[i].opType == OP_LD || iq[i].opType == OP_ST) {
          //  cout << "imm = " << iq[i].imm << endl;
       // }
	}

	numberOfInstruction = insQueue.size();
}

void Tomasulo::showStatus() const
{
    cliShowInstructionStatus();
	cout << endl;
    cliShowReservationStatus();
	cout << endl;
    cliShowLoadBufferStatus();
	cout << endl;
    cliShowStoreBufferStatus();
	cout << endl;
    cliShowRegisterStatus();
}

void Tomasulo::cliShowInstructionStatus() const
{
	cout << "**********Instruction Status**********" << endl;
	cout << "*****Instruction*****Issue**Execute**WriteResult****" << endl;
	for (int i = 0; i != numberOfInstruction; i ++) {
		insQueue[i].showInstruction();
	}
}

void Tomasulo::cliShowReservationStatus() const
{
	cout << "**********Reservation Station**********" << endl;
	cout << "**Name**Busy**Op**Vj**Vk**Qj**Qk**A**" << endl;

	for (int i = 0; i != numberOfRS; i ++) {
		RS[i].showReservationStation();
	}
}

void Tomasulo::cliShowLoadBufferStatus() const
{
	cout << "**********Load Buffer**********" << endl;
	cout << "**Name**Busy**Op**Vj**Qj**A****" << endl;
	for (int i = 0; i != numberOfLB; i ++) {
		LB[i].showLoadBuffer();
	}
}

void Tomasulo::cliShowStoreBufferStatus() const
{
	cout << "**********Store Buffer**********" << endl;
	cout << "**Name**Busy**Op**Vj**Vk**Qj**Qk**A**" << endl;
	for (int i = 0; i != numberOfSB; i ++) {
		SB[i].showStoreBuffer();
	}
}

void Tomasulo::cliShowRegisterStatus() const
{
	cout << "***********Register Status***********" << endl;
	for (int i = 0; i != numberOfRegister; i ++)
		RegisterStat[i].showRegister();
}
