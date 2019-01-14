//
// Created by mufengjun260 on 4/8/18.
//

#include <vector>
#include "MIPSCommandFinder.h"

int MIPSCommandFinder::getCommandOffset(string tmpLine) {
	return contentCommand(tmpLine);
}

int MIPSCommandFinder::contentCommand(string tmpLine) {
	vector<string> commands{
			"add", "addi", "addiu", "addu", "clo", "clz", "la", "li", "lui", "move", "negu", "seb", "seh", "sub",
			"subu",         //arithmetic operations
			"rotr", "rotrv", "sll", "sllv", "sra", "srav", "srl",
			"srlv",                                                  //shift and r otate operations
			"and", "andi", "ext", "ins", "nop", "nor", "not", "or", "ori", "wsbh", "xor",
			"xori",                              //logical and bit-field operations
			"movn", "movz", "slt", "slti", "sltiu",
			"sltu",                                                              //condition testing and conditional move operations
			"div", "divu", "madd", "maddu", "msub", "msubu", "mul", "mult",
			"multu",                                        //multiply and divide operations
			"mfhi", "mflo", "mthi",
			"mtlo",                                                                            //accumulator access operations
			"b", "bal", "beq", "beqz", "bgez", "bgezal", "bgtz", "blez", "bltz", "bltzal", "bne", "bnez", "j", "jal",
			"jalr", "jr",//jumps and branches(note: one delay slot)
			"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr", "sb", "sh", "sw", "swl", "swr", "ulw",
			"usw",                          //load andstore operations
			"ll",
			"sc"                                                                                               //ATOMIC READ-MODIFY -WRITE OPERATIONS

	};
	for (int i = 0; i <= commands.size() - 1; i++) {
		if (tmpLine.find(commands[i]) != string::npos) {
			return static_cast<int>(tmpLine.find(commands[i] + ' '));
		}
	}
	return -1;
}