//
// Created by mufengjun260 on 4/5/18.
//

#include <fstream>
#include "MIPSOperationResolver.h"
#include "MIPSPretreatment.h"
#include "MIPSCommandFinder.h"

extern string OPERATIONPath;

vector<string> MIPSOperationResolver::resolveAllOperation(string binFile) {
	MIPSPretreatment mipsPretreatment;
	string dumpFile = mipsPretreatment.getDump(binFile);

	string tmpLine;
	vector<string> outputFiles;
	ifstream inputFile(dumpFile);
	ofstream outputFile;
	int totalLineNum = 0;
	bool isWriting = false;
	bool gotOffset = false;
	int commandOffset = 0;
	MIPSCommandFinder mipsCommandFinder;
	//int dirStatus = mkdir((textPath).data(), 0666);

	if (inputFile) {
		while (getline(inputFile, tmpLine)) {
			totalLineNum++;


			if (totalLineNum > 8 && tmpLine == "") {
				isWriting = false;
				gotOffset = false;
				outputFile.close();
			}

			if (isWriting) {
				tmpLine += ' ';

				if (!gotOffset) {
					commandOffset = tmpLine.find(" \t");
					gotOffset = true;
				}
				if (tmpLine.length() >= commandOffset) {
					tmpLine = tmpLine.substr(commandOffset + 2, tmpLine.length());

					string command = tmpLine.substr(0, tmpLine.find('\t'));
					outputFile << command + " ";
				}
			}

			if (tmpLine.find(">:") != string::npos) {
				isWriting = true;
				string outputFilePath =
						OPERATIONPath + tmpLine.substr(tmpLine.find('<') + 1, tmpLine.size() - 3 - tmpLine.find('<'));
				outputFilePath += ".dump";

//                if (outputFilePatlh ==
//                    "/home/mufengjun260/githubRepo/ICESHAVER/testOfLinuxKernel/vmlinux-4.9.10.o.dump.intel_cqm_cpu_exit>:") {
//                    //for debug
//                    cout << "bingo!!!";
//                }
				outputFile.open(outputFilePath, std::ios::out | std::ios::app);
				outputFiles.push_back(outputFilePath);
			}
		}
		return outputFiles;
	}
}

vector<int> MIPSOperationResolver::readOperationFromFile(string operationFile) {
	ifstream opFile(operationFile);
	vector<int> result;
	string tmpString;
	while (opFile.good()) {
		opFile >> tmpString;
		result.push_back(instructionSet[tmpString]);
	}
	return result;
}

MIPSOperationResolver::MIPSOperationResolver() {
	map<int, vector<string>> tmpISA;
	tmpISA[0] = {"ll", "sc"};
	tmpISA[1] = {"add", "addi", "addiu", "addu", "clo", "clz", "la", "li", "lui", "move", "negu", "seb", "seh",
	             "sub", "subu"};
	tmpISA[2] = {"rotr", "rotrv", "sll", "sllv", "sra", "srav", "srl", "srlv"};
	tmpISA[3] = {"and", "andi", "ext", "ins", "nop", "nor", "not", "or", "ori", "wsbh", "xor", "xori"};
	tmpISA[4] = {"movn", "movz", "slt", "slti", "sltiu", "sltu"};
	tmpISA[5] = {"div", "divu", "madd", "maddu", "msub", "msubu", "mul", "mult", "multu"};
	tmpISA[6] = {"mfhi", "mflo", "mthi", "mtlo"};
	tmpISA[7] = {"b", "bal", "beq", "beqz", "bgez", "bgezal", "bgtz", "blez", "bltz", "bltzal", "bne", "bnez", "j",
	             "jal", "jalr", "jr"};
	tmpISA[8] = {"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr", "sb", "sh", "sw", "swl", "swr", "ulw", "usw"};
	for (int outInt = 0; outInt <= 8; outInt++) {
		for (int inInt = 0; inInt <= tmpISA[outInt].size() - 1; inInt++) {
			instructionSet[tmpISA[outInt][inInt]] = outInt;
		}
	}
}
