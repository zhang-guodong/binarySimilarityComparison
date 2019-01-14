#include <iostream>
#include "FunctionAnalyzer.h"
#include "MIPSCommandResolver.h"
#include "MIPSCodeResolver.h"
#include "MIPSResolver.h"
#include "MIPSOperationResolver.h"

string FUNCPath, DUMPPath, TOKENPath, binaryFilePath, OPERATIONPath;

vector<string> MIPSResolver::resolveMIPSBinFile(string binFilePath) {
	binaryFilePath = binFilePath;
	FUNCPath = binaryFilePath + ".dir/FUNC/";
	DUMPPath = binaryFilePath + ".dir/DUMP/";
	TOKENPath = binaryFilePath + ".dir/TOKEN/";
	OPERATIONPath = binaryFilePath + ".dir/OPERATION/";


	MIPSResolverUtil::mkdir(binFilePath + ".dir");
	MIPSResolverUtil::mkdir(FUNCPath);
	MIPSResolverUtil::mkdir(DUMPPath);
	MIPSResolverUtil::mkdir(TOKENPath);
	MIPSResolverUtil::mkdir(OPERATIONPath);

	FunctionAnalyzer functionAnalyzer;
	vector<string> vectorOfBinFunc = functionAnalyzer.analyzeFunction(binaryFilePath);

	MIPSCommandResolver mipsCommandAnalyzer;
	vector<string> vectorOfCommand = mipsCommandAnalyzer.resolveAllMIPSCommand(vectorOfBinFunc);

	MIPSCodeResolver mipsCodeGenerater;
	vector<string> vectorOfToken = mipsCodeGenerater.resolveAllMIPSCode(vectorOfCommand);

	MIPSOperationResolver mipsOperationResolver;
	vector<string> vectorOfOperation = mipsOperationResolver.resolveAllOperation(binaryFilePath);
	return vectorOfOperation;
}