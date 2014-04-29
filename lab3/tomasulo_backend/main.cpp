#include "tomasulo.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	Tomasulo tom;
	tom.showStatus();	

	vector<Instruction> iq;
//	Instruction i1(OP_LD, 1, 2, 0); 
//	Instruction i2(OP_LD, 2, 44, 
	Instruction i3(OP_MUL, 0, 1, 2);
	Instruction i4(OP_SUB, 4, 2, 3);
	Instruction i5(OP_DIV, 5, 0, 3);
	Instruction i6(OP_ADD, 3, 4, 1);
	
//	iq.push_back(i1);
//	iq.push_back(i2);
	iq.push_back(i3);
	iq.push_back(i4);
	iq.push_back(i5);
	iq.push_back(i6);
	tom.start(iq);
	for (int i = 0; i != 2; i ++) 
		tom.singleStep();
	tom.showStatus();
//	tom.singleStep();
//	tom.showStatus();
	return 0;
}
