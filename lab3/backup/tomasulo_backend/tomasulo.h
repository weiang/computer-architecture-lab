#ifndef TOMASULO_H
#define TOMASULO_H

#include <vector>
#include <iostream>
#include "virtualregister.h"
#include "cdb.h"

class Tomasulo
{
public:
    Tomasulo(int na = 3, int nm = 2, int nl = 3, int ns = 3, int nr = 17,
             int ea = 2, int ecs = 2, int em = 5, int ed = 12, int el = 2, int es = 5);

    void singleStep();
    void multipleSteps(int step);

    ~Tomasulo();
	
	/**
     * Start Tomasulo and instructions into instruction queue
     */
    void start(std::vector<Instruction> &iq);
	void showStatus() const;

 //   void addInstruction(const Instruction& i);
	    
    /**
     * Issue an instruction in instruction queue if the queue is not empty
     * and there exists a virtual register to recrive it
     */
    void issue();

    /**
     * Execute instructions that is already in virtual registers
     */
    void execute();

    /**
     * If CDB is available, sending  result in virtual register into others who need it.
     */
    void writeResult();

public:
    int currentTime;
    int numberOfAdd;
    int numberOfMul;
    int numberOfLB;
    int numberOfSB;
    int numberOfRegister;
    int numberOfRS;

    int exeCycleAdd;
    int exeCycleSub;
    int exeCycleMul;
    int exeCycleDiv;
    int exeCycleLD;
    int exeCycleST;

    CDB cdb;
	
	/* 
	 * Index of instruction in insQueue to be issued
	 */
    int insToIssue;

	/**
	 * Get head index of load-store instrution array to be executed
	 */
    int headIndex;
    std::vector<int> loadStoreArr;

	int numberOfInstruction;

    /**
     * Reservation stations 
     */
    ReservationStation *RS;

	/**
	 * Load Buffer
	 */
	LoadBuffer *LB;

	/**
	 * Store Buffer
	 */
	StoreBuffer *SB;

    /**
     * Real register file which also contains information about status
     */
    Register *RegisterStat;

    /**
      * Instruction queue
      */
    std::vector<Instruction> insQueue;

    /**
     * Instruction in one reservation station or load buffer or store buffer
     * can't be executed twice, so this array is used to flag the instruction
     * the has been executed in one single cycle.
     * True means having executed, otherwise not execute yet.
     */
    bool *RSFlag;
    bool *LBFlag;
    bool *SBFlag;

    /**
     * Allocating resources for Tomasulo according to configuration
     */
    void init();

    void clearFlag();
	int findFree(OP_TYPE ot);
    void issueInstruciton(int r, const Instruction& ins);
    void sendData(R_TYPE rType, int r, std::string result);
    bool isFinished();
    void cliShowInstructionStatus() const;
    void cliShowReservationStatus() const;
    void cliShowLoadBufferStatus() const;
    void cliShowStoreBufferStatus() const;
    void cliShowRegisterStatus() const;
};



#endif // TOMASULO_H
