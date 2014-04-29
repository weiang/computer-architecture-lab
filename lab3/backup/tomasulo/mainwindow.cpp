#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//	scrollArea = new QScrollArea;
//	scrollArea -> setWidget(ui -> centralWidget);
//	scrollArea -> setWidgetResizable(true);
//
//	QHBoxLayout *mainLayout = new QHBoxLayout(scrollArea);
//	mainLayout -> addWidget(scrollArea);
//	ui -> centralWidget -> setLayout(mainLayout);
//		scrollArea = new QScrollArea;
//		scrollArea -> setWidget(ui -> centralWidget);
//		scrollArea -> show();
    tom = NULL;
	reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::readIns()
{
    Instruction in;
    ins.clear();
    for (int k = 0; k != 10; k ++) {
        switch ((ui -> i)[k][0] -> currentIndex()) {
        case 1:     // ADD
            in.opType = OP_ADD;
            in.rd = ui -> i[k][1] -> currentIndex();
            in.rs = ui -> i[k][2] -> currentIndex();
            in.rt = ui -> i[k][3] -> currentIndex();
            in.exeCycle =  exeCycleAdd;
            break;

        case 2:     // SUB
            in.opType = OP_SUB;
            in.rd = ui -> i[k][1] -> currentIndex();
            in.rs = ui -> i[k][2] -> currentIndex();
            in.rt = ui -> i[k][3] -> currentIndex();
            in.exeCycle = exeCycleSub;
            break;

        case 3:     // MUL
            in.opType = OP_MUL;
            in.rd = ui -> i[k][1] -> currentIndex();
            in.rs = ui -> i[k][2] -> currentIndex();
            in.rt = ui -> i[k][3] -> currentIndex();
            in.exeCycle = exeCycleMul;
            break;

        case 4:     // DIV
            in.opType = OP_DIV;
            in.rd = ui -> i[k][1] -> currentIndex();
            in.rs = ui -> i[k][2] -> currentIndex();
            in.rt = ui -> i[k][3] -> currentIndex();
            in.exeCycle = exeCycleDiv;
            break;

        case 5:     // LD
            in.opType = OP_LD;
            in.rt = ui -> i[k][1] -> currentIndex();
            in.imm = ui -> i[k][2] -> currentIndex();
//            cout << "LD " << in.imm << endl;
            in.rs = ui -> i[k][3] -> currentIndex();
            break;

        case 6:     // ST
            in.opType = OP_ST;
            in.rs = ui -> i[k][1] -> currentIndex();
            in.imm = ui ->  i[k][2] -> currentIndex();
            in.rt = ui -> i[k][3] -> currentIndex();
            break;

        case 0:     // NOP
                break;
        }
        if ((ui -> i)[k][0] -> currentIndex() != 0) {
            ins.push_back(in);
        }
    }
//    std::cout << "read from readIns(): "<< ins.size() << std::endl;
}

void MainWindow::oneCycle()
{
    tom->singleStep();
    showResult();
}

void MainWindow::mulCycle(int n)
{
    for (int i = 0; i < n; i ++)
        tom->singleStep();
    showResult();
}

void MainWindow::readInsCycle()
{
    exeCycleAdd = (ui -> exeCycle->item(0, 0))->text().toInt();
    exeCycleSub = (ui -> exeCycle->item(1, 0))->text().toInt();
    exeCycleMul = (ui -> exeCycle->item(2, 0))->text().toInt();
    exeCycleDiv = (ui -> exeCycle->item(3, 0))->text().toInt();
    exeCycleLD = (ui -> exeCycle->item(4, 0))->text().toInt();
    exeCycleST = (ui -> exeCycle->item(5, 0))->text().toInt();
//    std::cout << exeCycleAdd << std::endl;
//    std::cout << exeCycleSub << std::endl;
//    std::cout << exeCycleMul << std::endl;
//    std::cout << exeCycleDiv << std::endl;
//    std::cout << exeCycleLD << std::endl;
//    std::cout << exeCycleST << std::endl;
}

void MainWindow::on_execute_pressed()
{
    readInsCycle(); // Read instruction's execution cycles

    readIns();      // Initialize instruction queue

//    if (tom != NULL)
//        delete tom;
    tom = new Tomasulo(3, 2, 3, 3, 17, exeCycleAdd, exeCycleSub,
                       exeCycleMul, exeCycleDiv, exeCycleLD, exeCycleST);
//    for (int i = 0; i != tom->numberOfRS; i ++)
//        cout << tom->RS[i].vrStatus << endl;

    tom->start(ins);
//    guiShowInstruction();
    ui -> stackedWidget -> setCurrentIndex(1);

    oneCycle();

}

void MainWindow::changeToALUSelection(int k)
{
	for (int l = 1; l != 4; l ++) {
	    ui -> i[k][l]->clear();
        ui -> i[k][l]->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "F0", 0)
         << QApplication::translate("MainWindow", "F2", 0)
         << QApplication::translate("MainWindow", "F4", 0)
         << QApplication::translate("MainWindow", "F6", 0)
         << QApplication::translate("MainWindow", "F8", 0)
         << QApplication::translate("MainWindow", "F10",0)
         << QApplication::translate("MainWindow", "F12",0)
         << QApplication::translate("MainWindow", "F14", 0)
         << QApplication::translate("MainWindow", "F16", 0)
         << QApplication::translate("MainWindow", "F18", 0)
         << QApplication::translate("MainWindow", "F20",0)
         << QApplication::translate("MainWindow", "F22",0)
         << QApplication::translate("MainWindow", "F24", 0)
         << QApplication::translate("MainWindow", "F26", 0)
         << QApplication::translate("MainWindow", "F28", 0)
         << QApplication::translate("MainWindow", "F30",0)
         << QApplication::translate("MainWindow", "F32",0)
        );
	}
}

void MainWindow::changeToLDST(int k)
{
    ui -> i[k][1] -> clear();
    ui -> i[k][1]->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "F0", 0)
     << QApplication::translate("MainWindow", "F2", 0)
     << QApplication::translate("MainWindow", "F4", 0)
     << QApplication::translate("MainWindow", "F6", 0)
     << QApplication::translate("MainWindow", "F8", 0)
     << QApplication::translate("MainWindow", "F10",0)
     << QApplication::translate("MainWindow", "F12",0)
     << QApplication::translate("MainWindow", "F14", 0)
     << QApplication::translate("MainWindow", "F16", 0)
     << QApplication::translate("MainWindow", "F18", 0)
     << QApplication::translate("MainWindow", "F20",0)
     << QApplication::translate("MainWindow", "F22",0)
     << QApplication::translate("MainWindow", "F24", 0)
     << QApplication::translate("MainWindow", "F26", 0)
     << QApplication::translate("MainWindow", "F28", 0)
     << QApplication::translate("MainWindow", "F30",0)
     << QApplication::translate("MainWindow", "F32",0)
    );

    ui -> i[k][2] -> clear();
    ui -> i[k][2]->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "0", 0)
     << QApplication::translate("MainWindow", "1", 0)
     << QApplication::translate("MainWindow", "2", 0)
     << QApplication::translate("MainWindow", "3", 0)
     << QApplication::translate("MainWindow", "4", 0)
     << QApplication::translate("MainWindow", "5",0)
     << QApplication::translate("MainWindow", "6",0)
     << QApplication::translate("MainWindow", "7", 0)
     << QApplication::translate("MainWindow", "8", 0)
     << QApplication::translate("MainWindow", "9", 0)
     << QApplication::translate("MainWindow", "10",0)
     << QApplication::translate("MainWindow", "11",0)
     << QApplication::translate("MainWindow", "12", 0)
     << QApplication::translate("MainWindow", "13", 0)
     << QApplication::translate("MainWindow", "14", 0)
     << QApplication::translate("MainWindow", "15",0)
     << QApplication::translate("MainWindow", "16",0)
     << QApplication::translate("MainWindow", "17", 0)
     << QApplication::translate("MainWindow", "18", 0)
     << QApplication::translate("MainWindow", "19", 0)
     << QApplication::translate("MainWindow", "20",0)
     << QApplication::translate("MainWindow", "21", 0)
     << QApplication::translate("MainWindow", "22",0)
     << QApplication::translate("MainWindow", "23", 0)
     << QApplication::translate("MainWindow", "24", 0)
     << QApplication::translate("MainWindow", "25", 0)
     << QApplication::translate("MainWindow", "26", 0)
     << QApplication::translate("MainWindow", "27", 0)
     << QApplication::translate("MainWindow", "28", 0)
     << QApplication::translate("MainWindow", "29", 0)
     << QApplication::translate("MainWindow", "30",0)
     << QApplication::translate("MainWindow", "31", 0)
);

    ui -> i[k][3] -> clear();
    ui -> i[k][3]->insertItems(0, QStringList()
     << QApplication::translate("MainWindow", "R0", 0)
     << QApplication::translate("MainWindow", "R1", 0)
     << QApplication::translate("MainWindow", "R2", 0)
     << QApplication::translate("MainWindow", "R3", 0)
     << QApplication::translate("MainWindow", "R4", 0)
     << QApplication::translate("MainWindow", "R5",0)
     << QApplication::translate("MainWindow", "R6",0)
     << QApplication::translate("MainWindow", "R7", 0)
     << QApplication::translate("MainWindow", "R8", 0)
     << QApplication::translate("MainWindow", "R9", 0)
     << QApplication::translate("MainWindow", "R10",0)
     << QApplication::translate("MainWindow", "R11",0)
     << QApplication::translate("MainWindow", "R12", 0)
     << QApplication::translate("MainWindow", "R13", 0)
     << QApplication::translate("MainWindow", "R14", 0)
     << QApplication::translate("MainWindow", "R15",0)
     << QApplication::translate("MainWindow", "R16",0)
	 << QApplication::translate("MainWindow", "R17", 0)
	 << QApplication::translate("MainWindow", "R18", 0)
     << QApplication::translate("MainWindow", "R19", 0)
     << QApplication::translate("MainWindow", "R20",0)
     << QApplication::translate("MainWindow", "R21", 0)
     << QApplication::translate("MainWindow", "R22",0)
     << QApplication::translate("MainWindow", "R23", 0)
     << QApplication::translate("MainWindow", "R    24", 0)
     << QApplication::translate("MainWindow", "R25", 0)
     << QApplication::translate("MainWindow", "R26", 0)
     << QApplication::translate("MainWindow", "R27", 0)
     << QApplication::translate("MainWindow", "R28", 0)
     << QApplication::translate("MainWindow", "R29", 0)
     << QApplication::translate("MainWindow", "R30",0)
     << QApplication::translate("MainWindow", "R31", 0)
	);

}

void MainWindow::changeToNull(int k)
{
    for (int l = 1; l != 4; l ++) {
        ui -> i[k][l] -> clear();
        ui -> i[k][l] -> insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Null", 0));
    }
}

void MainWindow::changeAux(int index, int k)
{
    switch (index) {
    case 0:
        changeToNull(k);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        changeToALUSelection(k);
        break;
    case 5:
    case 6:
        changeToLDST(k);
        break;
    }
}

void MainWindow::on_i00_currentIndexChanged(int index)
{
    changeAux(index, 0);
}

 void MainWindow::on_i10_currentIndexChanged(int index)
 {
     changeAux(index, 1);
 }

void MainWindow::on_i20_currentIndexChanged(int index)
{
  changeAux(index, 2);
}

void MainWindow::on_i30_currentIndexChanged(int index)
{
      changeAux(index, 3);
}

void MainWindow::on_i40_currentIndexChanged(int index)
{
      changeAux(index, 4);
}

void MainWindow::on_i50_currentIndexChanged(int index)
{
  changeAux(index, 5);
}

void MainWindow::on_i60_currentIndexChanged(int index)
{
  changeAux(index, 6);
}

void MainWindow::on_i70_currentIndexChanged(int index)
{
  changeAux(index, 7);
}

void MainWindow::on_i80_currentIndexChanged(int index)
{
  changeAux(index, 8);
}

void MainWindow::on_i90_currentIndexChanged(int index)
{
  changeAux(index, 9);
}

void MainWindow::on_stepFiveFront_pressed()
{
    mulCycle(5);
}

void MainWindow::on_stepOneFront_pressed()
{
	oneCycle();
}

void MainWindow::on_stepOneBack_pressed()
{
    int ct = tom->currentTime - 1;
    delete tom;
    tom = new Tomasulo(3, 2, 3, 3, 17, exeCycleAdd, exeCycleSub,
                       exeCycleMul, exeCycleDiv, exeCycleLD, exeCycleST);
    tom->start(ins);
    mulCycle(ct);
}

void MainWindow::on_stepFiveBack_pressed()
{
    int ct = tom->currentTime - 5;
    delete tom;
    tom = new Tomasulo(3, 2, 3, 3, 17, exeCycleAdd, exeCycleSub,
                       exeCycleMul, exeCycleDiv, exeCycleLD, exeCycleST);
    tom->start(ins);
    mulCycle(ct);
}

void MainWindow::on_allToOne_pressed()
{
    while (!(tom->isFinished())) {
        oneCycle();
    }
    showResult();
}

void MainWindow::on_exit_pressed()
{
    for (int i = 0; i != 10; i ++) {
        for (int j = 0; j != 4; j ++) {
            ui->is->setItem(i, j, new QTableWidgetItem(QString()));
        }
    }
    ui->stackedWidget->setCurrentIndex(0);
//    if (tom)
//        delete tom;
    ui->currentTime->setText(QString("0"));
    ui->jumpTo->setText(QString());
    reset();
}

void MainWindow::on_go_pressed()
{
    int ct = ui->jumpTo->text().toInt();
//    cout << "Go to" <<  ct << endl;
    delete tom;
    tom = new Tomasulo(3, 2, 3, 3, 17, exeCycleAdd, exeCycleSub,
                       exeCycleMul, exeCycleDiv, exeCycleLD, exeCycleST);
    tom->start(ins);
    mulCycle(ct);
}
void MainWindow::on_reset_pressed()
{
	reset();
}

void MainWindow::initInsQueue()
{
    // Ins1
    ui->i[0][0]->setCurrentIndex(5);
    ui->i[0][1]->setCurrentIndex(4);
    ui->i[0][2]->setCurrentIndex(21);
    ui->i[0][3]->setCurrentIndex(3);

    // Ins2
    ui->i[1][0]->setCurrentIndex(5);
    ui->i[1][1]->setCurrentIndex(2);
    ui->i[1][2]->setCurrentIndex(16);
    ui->i[1][3]->setCurrentIndex(4);

    // Ins3
    ui->i[2][0]->setCurrentIndex(3);
    ui->i[2][1]->setCurrentIndex(1);
    ui->i[2][2]->setCurrentIndex(2);
    ui->i[2][3]->setCurrentIndex(3);

    // Ins4
    ui->i[3][0]->setCurrentIndex(2);
    ui->i[3][1]->setCurrentIndex(5);
    ui->i[3][2]->setCurrentIndex(4);
    ui->i[3][3]->setCurrentIndex(2);

    // Ins5
    ui->i[4][0]->setCurrentIndex(4);
    ui->i[4][1]->setCurrentIndex(6);
    ui->i[4][2]->setCurrentIndex(1);
    ui->i[4][3]->setCurrentIndex(4);

    // Ins6
    ui->i[5][0]->setCurrentIndex(1);
    ui->i[5][1]->setCurrentIndex(4);
    ui->i[5][2]->setCurrentIndex(5);
    ui->i[5][3]->setCurrentIndex(2);

    for (int j = 6; j != 10; j ++) {
        for (int k = 0; k != 4; k ++)
            ui->i[j][k]->setCurrentIndex(0);
    }
}

void MainWindow::reset()
{
    // Set instruction execute cycle
    ui->exeCycle->setItem(0, 0, new QTableWidgetItem(QString::number(2)));
    ui->exeCycle->setItem(0, 1, new QTableWidgetItem(QString::number(2)));
    ui->exeCycle->setItem(0, 2, new QTableWidgetItem(QString::number(10)));
    ui->exeCycle->setItem(0, 3, new QTableWidgetItem(QString::number(40)));
    ui->exeCycle->setItem(0, 4, new QTableWidgetItem(QString::number(2)));
    ui->exeCycle->setItem(0, 5, new QTableWidgetItem(QString::number(2)));

    // Instruction queue
    initInsQueue();

    //reservation station
    for (int i = 0; i != 5; i ++) {
        for (int j = 0; j != 8; j ++) {
            if (j == 1)
                continue;
            else if (j == 2)
                ui->rs->setItem(i, j, new QTableWidgetItem(QString("No")));
            else
                ui->rs->setItem(i, j, new QTableWidgetItem(QString()));
        }
    }

    //Load buffer
    for (int i = 0; i != 3; i ++) {
        for (int j = 1; j != 6; j ++) {
            if (j == 1)
                ui->lb->setItem(i, j, new QTableWidgetItem(QString("No")));
            else
                ui->lb->setItem(i, j, new QTableWidgetItem(QString()));
        }
     }

    // Store buffer
    for (int i = 0; i != 3; i ++) {
        for (int j= 1; j != 7; j ++) {
            if (j == 1)
                ui->sb->setItem(i, j, new QTableWidgetItem(QString("No")));
            else
                ui->sb->setItem(i, j, new QTableWidgetItem(QString()));
         }
    }

    for (int i = 0; i != 17; i ++) {
        for (int j = 0; j != 2; j ++) {
            ui->r->setItem(j, i, new QTableWidgetItem(QString()));
        }
    }
}

void MainWindow::showResult()
{
    ui->currentTime->setText(QString::number(tom->currentTime));
    guiShowInstruction();
    guiShowRS();
    guiShowLB();
    guiShowSB();
    guiShowRegister();
}

void MainWindow::guiShowInstruction()
{
//    std::cout << tom->insQueue.size() << std::endl;

    vector<Instruction>::size_type i;
    for (i = 0; i != tom->insQueue.size(); i ++) {
		QString ins;
        switch (tom->insQueue[i].opType) {
			case OP_ADD:
				ins += "ADD.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rd * 2));
                ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rs * 2));
                ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rt * 2));
                ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
                break;
			case OP_SUB:
				ins += "SUB.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rd * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rs * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rt * 2));
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
				break;

			case OP_MUL:
				ins += "MUL.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rd * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rs * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rt * 2));
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
				break;

            case OP_DIV:
				ins += "DIV.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rd * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rs * 2));
				ins += ",";
                ins += ("F" + QString::number(tom->insQueue[i].rt * 2));
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
				break;

            case OP_LD:
				ins += "L.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rt * 2));
				ins += ",";
                ins += QString::number(tom->insQueue[i].imm);
				ins += "(";
                ins += ("R" + QString::number(tom->insQueue[i].rs));
				ins += ")";
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
				break;
			
			case OP_ST:
				ins += "S.D ";
                ins += ("F" + QString::number(tom->insQueue[i].rs * 2));
				ins += ",";
                ins += QString::number(tom->insQueue[i].imm);
				ins += "(";
                ins += ("R" + QString::number(tom->insQueue[i].rt));
				ins += ")";
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
				break;

			default:
				ins += "NOP";
				ui -> is->setItem(i, 0, new QTableWidgetItem(ins));
			}
        if (tom->insQueue[i].issueTime != BLANK) {
            ui -> is->setItem(i, 1, new QTableWidgetItem(QString::number(tom->insQueue[i].issueTime)));
        }
        else {
            ui -> is->setItem(i, 1, new QTableWidgetItem(QString()));
        }
        if (tom->insQueue[i].exeStartTime != BLANK) {
            if (tom->insQueue[i].exeEndTime != BLANK) {
                ui -> is->setItem(i, 2, new QTableWidgetItem(QString::number(tom->insQueue[i].exeStartTime) + QString("~") + QString::number(tom->insQueue[i].exeEndTime)));
            }
            else {
                if (tom->insQueue[i].exeStartTime == tom->currentTime)
                    ui -> is->setItem(i, 2, new QTableWidgetItem(QString::number(tom->insQueue[i].exeStartTime) + QString("~")));
                else
                    ui -> is->setItem(i, 2, new QTableWidgetItem(QString::number(tom->insQueue[i].exeStartTime) + QString("~") + QString::number(tom->currentTime)));
            }
        }
        else {
            ui -> is->setItem(i, 2, new QTableWidgetItem(QString()));

        }
        if (tom->insQueue[i].writeTime != BLANK) {
            ui -> is->setItem(i, 3, new QTableWidgetItem(QString::number(tom->insQueue[i].writeTime)));
        }
        else {
            ui -> is->setItem(i, 3, new QTableWidgetItem(QString()));

        }
	}
}

QString MainWindow::getName(R_TYPE r, int l)
{
    QString result;
    switch(r) {
    case L:
        result = QString("Load");
        result += QString(QString::number(l + 1));
        break;
    case R:
        if (l == 3)
            result = QString("Mul1");
        else if (l == 4)
            result = QString("Mul2");
        else {
            result = QString("Add");
            result += QString(QString::number(l + 1));
        }
        break;
    case S:
        result = QString("R" + QString::number(2 * l));
        break;
    default:
        ;
    }
    return result;
}

void MainWindow::guiShowRS()
{
    for (int i = 0; i != tom->numberOfRS; i ++) {
        if (tom->RS[i].vrStatus == VR_FREE) {
            for (int k = 0; k != 8; k ++) {
                if (k == 1)
                    continue;
                ui -> rs->setItem(i, k, new QTableWidgetItem(QString()));
            }
            ui -> rs->setItem(i, 2, new QTableWidgetItem(QString("No")));   //  Busy
        }
        else {
            if (tom->RS[i].vrStatus == VR_EXE) {
                ui->rs->setItem(i, 0, new QTableWidgetItem(QString::number(tom->RS[i].restCycle)));
            }
            ui -> rs->setItem(i, 2, new QTableWidgetItem(QString("Yes")));
            switch(tom->RS[i].opType) {  // Op
            case OP_ADD:
                ui -> rs->setItem(i, 3, new QTableWidgetItem(QString("ADD")));
                break;
            case OP_SUB:
                ui -> rs->setItem(i, 3, new QTableWidgetItem(QString("SUB")));
                break;
            case OP_MUL:
                ui -> rs->setItem(i, 3, new QTableWidgetItem(QString("MUL")));
                break;
            case OP_DIV:
                ui -> rs->setItem(i, 3, new QTableWidgetItem(QString("DIV")));
                break;

            case OP_LD:
            case OP_ST:
            default:
                ui -> rs->setItem(i, 3, new QTableWidgetItem(QString()));

            }
            if (tom->RS[i].Qj != BLANK) {
                ui -> rs->setItem(i, 4, new QTableWidgetItem(QString()));
                ui -> rs->setItem(i, 6, new QTableWidgetItem(getName(tom->RS[i].Rj, tom->RS[i].Qj)));
            }
            else {
                ui -> rs->setItem(i, 6, new QTableWidgetItem(QString()));
                ui -> rs->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(tom->RS[i].Vj)));
            }
            if (tom->RS[i].Qk != BLANK) {
                ui -> rs->setItem(i, 5, new QTableWidgetItem(QString()));
                ui -> rs->setItem(i, 7, new QTableWidgetItem(getName(tom->RS[i].Rk, tom->RS[i].Qk)));
            }
            else {
                ui -> rs->setItem(i, 7, new QTableWidgetItem(QString()));
                ui -> rs->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(tom->RS[i].Vk)));
            }
         }
     }
}

void MainWindow::guiShowLB()
{
    for (int i = 0; i != tom->numberOfLB; i ++) {
        if (tom->LB[i].vrStatus == VR_FREE) {
            ui -> lb->setItem(i, 1, new QTableWidgetItem(QString("No")));
            ui -> lb->setItem(i, 2, new QTableWidgetItem(QString()));
            ui -> lb->setItem(i, 3, new QTableWidgetItem(QString()));
            ui -> lb->setItem(i, 4, new QTableWidgetItem(QString()));
            ui -> lb->setItem(i, 5, new QTableWidgetItem(QString()));
        }
        else {
            ui -> lb->setItem(i, 1, new QTableWidgetItem(QString("Yes")));
            if (tom->LB[i].Qj != BLANK) {
                ui -> lb->setItem(i, 5, new QTableWidgetItem(getName(tom->LB[i].Rj, tom->LB[i].Qj)));
                ui -> lb->setItem(i, 4, new QTableWidgetItem(QString()));

            }
            else {
                ui -> lb->setItem(i, 5, new QTableWidgetItem(QString()));
                ui -> lb->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(tom->LB[i].Vj)));
                ui -> lb->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tom->LB[i].A)));

            }
        }
    }
}

void MainWindow::guiShowSB()
{
    for (int i = 0; i != tom->numberOfSB; i ++) {
        if (tom->SB[i].vrStatus == VR_FREE) {
            ui -> sb->setItem(i, 1, new QTableWidgetItem(QString("No")));
            ui -> sb->setItem(i, 2, new QTableWidgetItem(QString()));
            ui -> sb->setItem(i, 3, new QTableWidgetItem(QString()));
            ui -> sb->setItem(i, 4, new QTableWidgetItem(QString()));
            ui -> sb->setItem(i, 5, new QTableWidgetItem(QString()));
            ui -> sb->setItem(i, 6, new QTableWidgetItem(QString()));

        }
        else {
            ui -> sb -> setItem(i, 1, new QTableWidgetItem(QString("Yes")));
            ui->sb->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(tom->SB[i].A)));
            if (tom->SB[i].Qj != BLANK) {
                ui -> sb->setItem(i, 5, new QTableWidgetItem(getName(tom->SB[i].Rj, tom->SB[i].Qj)));
                ui -> sb->setItem(i, 3, new QTableWidgetItem(QString()));
            }
            else {
                ui -> sb->setItem(i, 5, new QTableWidgetItem(QString()));
                ui -> sb->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(tom->SB[i].Vj)));

            }
            if (tom->SB[i].Qk != BLANK) {
                ui -> sb->setItem(i, 6, new QTableWidgetItem(getName(tom->SB[i].Rk, tom->SB[i].Qk)));
                ui -> sb->setItem(i, 4, new QTableWidgetItem(QString()));

            }
            else {
                ui -> sb->setItem(i, 6, new QTableWidgetItem(QString()));
                ui -> sb->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(tom->SB[i].Vk)));

            }
        }
    }
}
void MainWindow::guiShowRegister()
{
    for (int i =0; i != tom->numberOfRegister; i ++) {
        if (tom->RegisterStat[i].Qi != BLANK) {
            ui -> r -> setItem(0, i, new QTableWidgetItem(getName(tom->RegisterStat[i].Ri, tom->RegisterStat[i].Qi)));
            ui -> r -> setItem(1, i, new QTableWidgetItem(QString::fromStdString(tom->RegisterStat[i].value)));

        }
        else {
            ui -> r -> setItem(0, i, new QTableWidgetItem(QString()));
            ui -> r -> setItem(1, i, new QTableWidgetItem(QString::fromStdString(tom->RegisterStat[i].value)));

        }
    }
}

