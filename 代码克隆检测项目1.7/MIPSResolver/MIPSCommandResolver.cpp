//
// Created by mufengjun260 on 18-1-31.
//

#include "MIPSCommandResolver.h"
#include "FunctionAnalyzer.h"

string MIPSCommandResolver::resolveMIPSCommand(string functionFilePath) {
	ifstream binFileStream(functionFilePath, ios::binary);
	string outputPath = functionFilePath.replace(functionFilePath.find(FUNCPath), FUNCPath.length(), DUMPPath);
	outputPath = outputPath.substr(0, outputPath.find(".FUNC")) + ".DUMP";
	ofstream outputFileStream(outputPath);

	//get binary file length
	cout << outputPath << endl;
	binFileStream.seekg(0, binFileStream.end);
	int commandNum = binFileStream.tellg() / 4;
	binFileStream.seekg(0, binFileStream.beg);


	while (commandNum--) {
		bitset<32> command;
		binFileStream.read((char *) &command, command.size() / 8);
		outputFileStream << command << endl;
	}
	binFileStream.close();
	outputFileStream.close();
	return outputPath;
}

vector<string> MIPSCommandResolver::resolveAllMIPSCommand(vector<string> functionFilePaths) {
	vector<string> commandFilePaths;
	for (int i = 0; i <= functionFilePaths.size() - 1; i++) {
		commandFilePaths.push_back(resolveMIPSCommand(functionFilePaths[i]));
	}
	return commandFilePaths;
}
