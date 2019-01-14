//
// Created by mufengjun260 on 18-2-1.
//

#include "MIPSCommand.h"

MIPSCommand::MIPSCommand(bitset<32> commandBitset) {
	opCode.reset();
	funcCode.reset();
	originCommand = commandBitset;
	originCommand = commandBitset;
	for (int i = 24; i <= 29; i++) {
		if (commandBitset[i])opCode.set(i - 24);
	}
	for (int i = 2; i <= 7; i++) {
		if (commandBitset[i])funcCode.set(i - 2);
	}
}

bool MIPSCommand::isRcommand() {
	if (opCode.none())return true;
	return false;
}

const bitset<6> &MIPSCommand::getOpCode() const {
	return opCode;
}

const bitset<6> &MIPSCommand::getFuncCode() const {
	return funcCode;
}
