//
// Created by mufengjun260 on 18-2-1.
//

#ifndef ICESHAVER_MIPSCOMMAND_H
#define ICESHAVER_MIPSCOMMAND_H

#include <bitset>

using namespace std;

class MIPSCommand {
public:
	MIPSCommand(bitset<32> commandBitset);

	bool isRcommand();
private:
	bitset<32> originCommand;
	bitset<6> opCode;
	bitset<6> funcCode;
public:
	const bitset<6> &getOpCode() const;

	const bitset<6> &getFuncCode() const;
};


#endif //ICESHAVER_MIPSCOMMAND_H
