#include <iostream>
#include <sstream>
#include "AnalyzeWholeMIPSDir.h"
#include "AnalyzeWholeX86Dir.h"
#include "AnalyzeWholeJavaDir.h"

using namespace std;

int main(int argc, char *argv[]) {
	//参数分析
	if (argc < 2) {
		return -1;
	}
	int gramSize, ISM,windowStep, windowLength, sandRatio;
	string runType = argv[1];

	if (runType == "JAVAdir") {
		stringstream tmpStringStream;
		tmpStringStream << argv[3] << ' ' << argv[4] << ' ' << argv[5] << ' ' << argv[7];
		tmpStringStream >> gramSize >> ISM >> windowLength >> sandRatio;
		string resultPath = argv[6];

		AnalyzeWholeJavaDir analyzeWholeJavaDir;
		analyzeWholeJavaDir.setSandRatio(sandRatio);
		map<vector<string>, double> map1 = analyzeWholeJavaDir.analyzeJavaDir(argv[2], gramSize, ISM, windowLength,
		                                                                  resultPath);
	}

	if (runType == "MIPSdir") {
		stringstream tmpStringStream;
		tmpStringStream << argv[3] << ' ' << argv[4] << ' ' << argv[5] << ' ' << argv[7];
		tmpStringStream >> gramSize >> windowStep >> windowLength >> sandRatio;
		string resultPath = argv[6];

		AnalyzeWholeMIPSDir analyzeWholeDir;
		analyzeWholeDir.setSandRatio(sandRatio);
		map<vector<string>, double> map1 = analyzeWholeDir.analyzeMIPSDir(argv[2], gramSize, windowStep, windowLength,
		                                                                  resultPath);
	}

	if (runType == "MIPSfile") {
		stringstream tmpStringStream;
		tmpStringStream << argv[4] << ' ' << argv[5] << ' ' << argv[6] << ' ' << argv[8];
		tmpStringStream >> gramSize >> windowStep >> windowLength;
		string resultPath = argv[7];

		//对结果添加CSV Head
		ofstream ofstream1(resultPath);
		string headString = "matchFilePath,targetFilePath,startMatchLine,endMatchLine,startTargetLine,endTargetLine,blockNum,usage,totalUsage";
		ofstream1 << headString;

		AnalyzeBetweenMIPSFiles analyzeBetweenFiles;
		analyzeBetweenFiles.setSandRatio(sandRatio);
		analyzeBetweenFiles.analyzeBetweenMIPSFiles(argv[2], argv[3], gramSize, windowStep, windowLength, resultPath);
	}

	if (runType == "x86dir") {
		stringstream tmpStringStream;
		tmpStringStream << argv[3] << ' ' << argv[4] << ' ' << argv[5] << ' ' << argv[7];
		tmpStringStream >> gramSize >> windowStep >> windowLength;
		string resultPath = argv[6];

		AnalyzeWholeX86Dir analyzeWholeDir;
		analyzeWholeDir.setSandRatio(sandRatio);
		map<vector<string>, double> map1 = analyzeWholeDir.analyzeX86Dir(argv[2], gramSize, windowStep, windowLength,
		                                                                 resultPath);
	}

	if (runType == "x86file") {
		stringstream tmpStringStream;
		tmpStringStream << argv[4] << ' ' << argv[5] << ' ' << argv[6] << ' ' << argv[8];
		tmpStringStream >> gramSize >> windowStep >> windowLength >> sandRatio;
		string resultPath = argv[7];

		//对结果添加CSV Head
		ofstream ofstream1(resultPath);
		string headString = "matchFilePath,targetFilePath,startMatchLine,endMatchLine,startTargetLine,endTargetLine,blockNum,usage,totalUsage";
		ofstream1 << headString;

		AnalyzeBetweenX86Files analyzeBetweenFiles;
		analyzeBetweenFiles.setSandRatio(sandRatio);
		analyzeBetweenFiles.analyzeBetweenX86Files(argv[2], argv[3], gramSize, windowStep, windowLength, resultPath);
	}
//    map<vector<string>, double>::iterator iterator1;
//    iterator1 = map1.begin();3


	//输出结果到输出流与文件result.txt

//    string outputPath = argv[1];
//    outputPath.append("/result.txt");
//    ofstream fileOutput(outputPath);
//    while (iterator1 != map1.end()) {
//        fileOutput << iterator1->first[0] << "    " << iterator1->first[1] << "   " << iterator1->second
//                   << endl;
//        //cout << iterator1->first[0] << "    " << iterator1->first[1] << "   " << iterator1->second << endl;
//        iterator1++;
//    }


	return 0;
}

