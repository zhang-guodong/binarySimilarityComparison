//
// Created by mufengjun260 on 18-1-31.
//

#include "FunctionAnalyzer.h"

vector<string> FunctionAnalyzer::analyzeFunction(string binaryFilePath) {
	MIPSPretreatment mipsPretreatment;
	string sectionPath = mipsPretreatment.getSection(binaryFilePath);
	string tablePath = mipsPretreatment.getTable(binaryFilePath);

	SectionAnalyzer sectionAnalyzer(sectionPath);

	string sectionAddr = sectionAnalyzer.getValue(".text", "Addr");
	string sectionOffset = sectionAnalyzer.getValue(".text", "Off");

	TableAnalyzer tableAnalyzer(tablePath);
	FunctionCutter functionCutter;
	vector<string> resultVector;
	string line;
	int lineNum = 0;
	ifstream tableFile(tablePath);
	while (getline(tableFile, line)) {
		lineNum++;
		if (lineNum < 5)continue;
		if (line == "")return resultVector;
		if (tableAnalyzer.getSectionName(line) == ".text") {
			string funcAddr = tableAnalyzer.getAddr(line);
			string funcSize = tableAnalyzer.getSize(line);
			string funcName = tableAnalyzer.getSymbolName(line);

			string outputPath = functionCutter.cutBinaryFunction(binaryFilePath, funcName, funcAddr, funcSize,
			                                                     sectionAddr, sectionOffset);
			resultVector.push_back(outputPath);
		}
	}
	return resultVector;
}
