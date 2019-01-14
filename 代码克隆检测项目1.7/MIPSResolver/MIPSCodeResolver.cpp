//
// Created by mufengjun260 on 18-2-3.
//

#include <bitset>
#include <algorithm>
#include "MIPSCodeResolver.h"
#include "FunctionAnalyzer.h"
#include "MIPSCommand.h"

string MIPSCodeResolver::resolveMIPSCode(string dumpFilePath) {
	ifstream dumpFile(dumpFilePath);
	string outputPath = dumpFilePath.replace(dumpFilePath.find(DUMPPath), DUMPPath.length(), TOKENPath);
	outputPath = outputPath.substr(0, outputPath.find(".DUMP")) + ".TOKEN";
	cout << outputPath << endl;
	dumpFile.seekg(0, ios::beg);
	ofstream tokenFile(outputPath);
	string command;
	while (getline(dumpFile, command)) {
		reverse(command.begin(), command.end());
		bitset<32> commandBitset(command);
		MIPSCommand mipsCommand(commandBitset);
		if (mipsCommand.isRcommand()) {
			tokenFile << "000000" << mipsCommand.getFuncCode() << endl;
		} else tokenFile << mipsCommand.getOpCode() << "000000" << endl;
	}
	dumpFile.close();
	tokenFile.close();
	return outputPath;
}

vector<string> MIPSCodeResolver::resolveAllMIPSCode(vector<string> dumpFilePaths) {
	vector<string> tokenFilePaths;
	for (int tmpInt = 0; tmpInt <= dumpFilePaths.size() - 1; tmpInt++) {
		tokenFilePaths.push_back(resolveMIPSCode(dumpFilePaths[tmpInt]));
	}
	return tokenFilePaths;
}

vector<bitset<12>> MIPSCodeResolver::readCodeFromFile(string filePath) {
	ifstream codeFile(filePath);
	vector<bitset<12>> result;
	string tmpString;
	while (getline(codeFile,tmpString)){
		bitset<12> tmpBitset(tmpString);
		result.push_back(tmpBitset);
	}
	return result;
}
