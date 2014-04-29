#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tomasulo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_i00_currentIndexChanged(int index);

    void on_i10_currentIndexChanged(int index);

    void on_i20_currentIndexChanged(int index);

    void on_i30_currentIndexChanged(int index);

    void on_i40_currentIndexChanged(int index);

    void on_i50_currentIndexChanged(int index);

    void on_i60_currentIndexChanged(int index);

    void on_i70_currentIndexChanged(int index);

    void on_i80_currentIndexChanged(int index);

    void on_i90_currentIndexChanged(int index);

    void on_reset_pressed();

    void on_execute_pressed();

    void on_stepOneFront_pressed();

    void on_stepOneBack_pressed();

    void on_stepFiveFront_pressed();

    void on_stepFiveBack_pressed();

    void on_allToOne_pressed();

    void on_exit_pressed();

    void on_go_pressed();

private:
    Ui::MainWindow *ui;

    Tomasulo *tom;
    std::vector<Instruction> ins;

    int exeCycleAdd;
    int exeCycleSub;
    int exeCycleMul;
    int exeCycleDiv;
    int exeCycleLD;
    int exeCycleST;

    void readIns();
    void oneCycle();
    void mulCycle(int);
    void readInsCycle();
    void changeToALUSelection(int);
    void changeToLDST(int);
    void changeToNull(int);
    void changeAux(int, int);
    void showResult();
    void guiShowInstruction();
    void guiShowRS();
    void guiShowLB();
    void guiShowSB();
    void guiShowRegister();
	void reset();
    void initInsQueue();
    QString getName(R_TYPE, int);
};

#endif // MAINWINDOW_H
