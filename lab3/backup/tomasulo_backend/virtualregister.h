#ifndef VIRTUALREGISTER_H
#define VIRTUALREGISTER_H

#include <string>
#include <iostream>

typedef long AddressType;
const int BLANK = -1;

/**
 * Operation type
 */
enum OP_TYPE {
    OP_NOP,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_LD,
    OP_ST
};

/**
 * The type of function unit connected with reservation station
 */
enum FU_TYPE {
    FU_ADDER,
    FU_MULTER
};

/**
 * The status of reservation station, load buffer, store buffer
 */
enum VR_STATUS {
    VR_FREE,
    VR_ISSUE,
    VR_EXE,
    VR_WR,
	VR_FINISH
};

/**
 * Instruction format
 */
class Instruction
{
public:
    Instruction() : issueTime(BLANK), exeStartTime(BLANK), exeEndTime(BLANK), writeTime(BLANK) {}
    Instruction(OP_TYPE ot, int rd, int rs, int rt, int imm = 0, int ec = 1)
        : opType(ot), rs(rs), rt(rt), rd(rd), imm(imm), exeCycle(ec)
    {
		issueTime = BLANK;
		exeStartTime = BLANK;
		exeEndTime = BLANK;
		writeTime = BLANK;
	}
	Instruction(const Instruction& ins) 
	{
		clone(ins);
	}

//	Instruction(const std::string& ct) { }

    OP_TYPE opType;
    int rs, rt, rd;
    int imm;
    int exeCycle;

	/* Status information */
	int issueTime;
	int exeStartTime;
	int exeEndTime;
	int writeTime;

	std::string content;
	void showInstruction() const
	{
		switch (opType) {
			case OP_ADD:
				std::cout << "ADD.D  ";
				std::cout << rs << "," << rt << "," << rd << std::endl;
				break;
			case OP_SUB:
				std::cout << "SUB.D  ";
				std::cout << rs << "," << rt << "," << rd << std::endl;
				break;
			case OP_MUL:
				std::cout << "MUL.D  ";
				std::cout << rs << "," << rt << "," << rd << std::endl;
				break;
			case OP_DIV:
				std::cout << "DIV.D  ";
				std::cout << rs << "," << rt << "," << rd << std::endl;
				break;
			case OP_LD:
				std::cout << "L.D    ";
				std::cout << rs << "," << imm << "(" << rt << ")" << std::endl;
				break;
			case OP_ST:
				std::cout << "S.D    ";
				std::cout << rs << "," << imm << "(" << rt << ")" << std::endl;
				break;
			default:
				std::cout << "NOP" << std::endl;;
		}
	}
private:
	void clone(const Instruction& ins)
	{
		if (this != &ins) {
			opType = ins.opType;
			rs = ins.rs;
			rt = ins.rt;
			rd = ins.rd;
            imm = ins.imm;
			exeCycle = ins.exeCycle;
            issueTime = ins.issueTime;
            exeStartTime = ins.exeStartTime;
            exeEndTime = ins.exeEndTime;
            writeTime = ins.writeTime;
		}
	}
};

enum R_TYPE {
	R,
	S,
	L
};

class Register
{
public:
    Register(std::string name = std::string(), std::string v = std::string())
        :name(name), Qi(BLANK), value(v) { }

	void showRegister() const
	{
		std::cout << name << " ";
		std::cout << Qi << std::endl;
	}
    std::string name;
    int Qi;
	R_TYPE Ri;	
    std::string value;
};


class ReservationStation
{
public:
    ReservationStation(std::string name = std::string(), FU_TYPE ft = FU_ADDER)
        : name(name), fuType(ft), Qj(BLANK), Qk(BLANK) {}


	void showReservationStation() const
	{
		std::cout << name << " ";
		if (vrStatus == VR_FREE) 
			std::cout << "Free ";
		else if (vrStatus == VR_ISSUE)
            std::cout << "ISSUE ";
		else if (vrStatus == VR_EXE)
			std::cout << "Exe ";
		else 
			std::cout << "WR ";
		switch (opType) {
			case OP_ADD:
				std::cout << "ADD ";
				break;
			case OP_SUB:
				std::cout << "SUB ";
				break;
			case OP_MUL:
				std::cout << "MUL ";
				break;
			case OP_DIV:
				std::cout << "DIV ";
				break;
			default:
				;			
		}
		std::cout << Vj << " " << Vk << " "  << Qj << " " << Qk << std::endl;
	}

    std::string name;
    FU_TYPE fuType;
    
    int Qj, Qk;
	R_TYPE Rj, Rk;
//    double Vj, Vk;
    std::string Vj, Vk;
    std::string result;
    int exeCycle;
    int restCycle;
    VR_STATUS vrStatus;
    OP_TYPE opType;

	int insNum;
};

class StoreBuffer
{
public:
    StoreBuffer(std::string name = std::string()) : name(name), Qj(BLANK), Qk(BLANK) {}


	void showStoreBuffer() const
	{
		std::cout << name << " ";
		std::cout << Vj << " " << Vk << " " << Qj << " " << Qk << " " << A << std::endl;
	}

    std::string name;
    int restCycle;
    std::string Vj, Vk;
    int Qj, Qk;
	R_TYPE Rj, Rk;
    std::string A;
    VR_STATUS vrStatus;
    OP_TYPE opType;
   
	int insNum;
};


class LoadBuffer 
{
public:
    LoadBuffer(std::string name = std::string()) : name(name), Qj(BLANK) {}

	void showLoadBuffer() const
	{
		std::cout << name << " ";
		std::cout << Vj << " " << Qj << " " << A << std::endl; 
	}

    std::string name;
    int restCycle;
    std::string  Vj;
    std::string result;
    std::string A;
    int Qj;   
	R_TYPE Rj;
    VR_STATUS vrStatus;
    OP_TYPE opType;

	int insNum;
};
#endif // VIRTUALREGISTER_H
