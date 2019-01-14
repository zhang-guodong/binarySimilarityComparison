//
// Created by mufengjun260 on 18-1-28.
//

#include "FunctionCutter.h"

string
FunctionCutter::cutBinaryFunction(string binaryFilePath, string funcName, string funcAddr, string funcSize,
                                  string sectionAddr,
                                  string sectionOffset) {
	string outputFilePath = FUNCPath + funcName + ".FUNC";
	cout << outputFilePath << endl;

	long intOfBinaryOffset = MIPSResolverUtil::HexToInt(funcAddr) - MIPSResolverUtil::HexToInt(sectionAddr) +
	                         MIPSResolverUtil::HexToInt(sectionOffset);
	long intOfBinarySize = MIPSResolverUtil::HexToInt(funcSize);

	cutByByte(binaryFilePath, outputFilePath, intOfBinaryOffset, intOfBinarySize);

	return outputFilePath;
}


string FunctionCutter::cutByByte(string binaryFilePath, string outputPath, long offset, int size) {
	ifstream binaryInputFile(binaryFilePath, ios::binary);
	ofstream outputFile(outputPath, ios::binary);

	binaryInputFile.seekg(binaryInputFile.end);
	int tellg = binaryInputFile.tellg();
	//if (binaryInputFile.tellg() < offset + size)return "not enough long to cut";

	binaryInputFile.seekg(offset);
	char *buffer = new char[size];
	binaryInputFile.read(buffer, size);
	outputFile.write(buffer, size);
	binaryInputFile.close();
	outputFile.close();
}