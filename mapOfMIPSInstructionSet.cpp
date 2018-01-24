//
// Created by zhanggd on 18-1-24.
//

#include "mapOfMIPSInstructionSet.h"

map<string, int> MIPSMnemonic =
	{
		//R型
		{"add",   0x020},
		{"addu",  0x021},
		{"sub",   0x022},
		{"subu",  0x023},
		{"and",   0x024},
		{"or",    0x025},
		{"xor",   0x026},
		{"nor",   0x027},
		{"slt",   0x02a},
		{"sltu",  0x02b},
		{"sll",   0x000},
		{"srl",   0x002},
		{"sra",   0x003},
		{"sllv",  0x004},
		{"srlv",  0x006},
		{"srav",  0x007},
		{"jr",    0x008},
		//I型
		{"addi",  0x200},
		{"addiu", 0x240},
		{"andi",  0x300},
		{"ori",   0x340},
		{"xori",  0x380},
		{"lui",   0x3c0},
		{"lw",    0x8c0},
		{"sw",    0xac0},
		{"beq",   0x100},
		{"bne",   0x140},
		{"slti",  0x280},
		{"sltiu", 0x2c0},
		//J型
		{"j",     0x080},
		{"jal",   0x0c0}
	};

int mnemonic2Num(string mnemonic)
{
	return MIPSMnemonic[mnemonic];
}