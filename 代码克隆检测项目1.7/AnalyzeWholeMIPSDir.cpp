//
// Created by mufengjun260 on 17-10-27.
//

#include "AnalyzeWholeMIPSDir.h"
#include "MIPSResolver/MIPSResolver.h"

using namespace std;

/**
 * 对目录进行遍历检索，其中的binary文件预处理后，对预处理的结果（command文件）进行迭代，比对相似度
 * @param dirPath  输入目录
 * @param gramSize N-Gram中N
 * @return map，key为一个vector<string>，其中vector[0]为被测样本，vector[1]为样本库中某样本，value为1相对于2的相似度
 */
map<vector<string>, double>
AnalyzeWholeMIPSDir::analyzeMIPSDir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath) {
	map<vector<string>, double> resultMap, minResultMap;
	double similarity;
	DirParser dirParser;
	FileNameGenerator fileNameGenerator;
	AnalyzeBetweenMIPSFiles analyzeBetweenFiles;
	analyzeBetweenFiles.setSandRatio(this->getSandRatio());
	vector<string> binaryFiles = dirParser.getFiles(dirPath);
	vector<string> MIPSTokenFiles;

	//对结果添加CSV Head
	ofstream ofstream1(resultPath);
	string headString = "matchFilePath,targetFilePath,startMatchLine,endMatchLine,startTargetLine,endTargetLine,blockNum,usage,totalUsage";
	ofstream1 << headString;
	ofstream1.close();

	//进行二进制文件的预处理
	for (int i = 0; i <= binaryFiles.size() - 1; i++) {
		MIPSResolver mipsResolver;
		vector<string> tmpMIPSTokenFiles = mipsResolver.resolveMIPSBinFile(binaryFiles[i]);
		MIPSTokenFiles.insert(MIPSTokenFiles.end(), tmpMIPSTokenFiles.begin(), tmpMIPSTokenFiles.end());
	}

	//对处理后的二进制文件
	for (int i = 0; i <= MIPSTokenFiles.size() - 1; i++) {
		bool foundWholeFileCopy = false;
		vector<string> minVector;
		string matchFileName = MIPSTokenFiles[i];

		vector<string> fileNameVector = fileNameGenerator.getCorrespondFileName(matchFileName, binaryFiles);
		for (int k = 0; k <= fileNameVector.size() - 1; k++) {
			vector<string>::iterator iterator1 = find(MIPSTokenFiles.begin(), MIPSTokenFiles.end(),
			                                          fileNameVector[k]);
			if (iterator1 != MIPSTokenFiles.end()) {
				vector<string> tmpVector;
				tmpVector.push_back(MIPSTokenFiles[i]);
				tmpVector.push_back(fileNameVector[k]);

				if (tmpVector[0] == tmpVector[1]) break;

				similarity = analyzeBetweenFiles.analyzeBetweenMIPSFiles(tmpVector[0], tmpVector[1], gramSize,
				                                                         windowStep,
				                                                         windowLength, resultPath);
				if (similarity == 1) {
					foundWholeFileCopy = true;
					break;
				}
			}
		}

		if (!foundWholeFileCopy) {
			for (int j = 0; j <= MIPSTokenFiles.size() - 1; j++) {
				if (i != j) {
					vector<string> tmpVector;
					tmpVector.push_back(MIPSTokenFiles[i]);
					tmpVector.push_back(MIPSTokenFiles[j]);

					if (tmpVector[0] == tmpVector[1]) break;

					similarity = analyzeBetweenFiles.analyzeBetweenMIPSFiles(MIPSTokenFiles[i], MIPSTokenFiles[j],
					                                                         gramSize, windowStep, windowLength,
					                                                         resultPath);

					if (similarity == 1) break;
				}
			}
		}
	}


	return resultMap;
}

float AnalyzeWholeMIPSDir::getSandRatio() const {
	return sandRatio;
}

void AnalyzeWholeMIPSDir::setSandRatio(float sandRatio) {
	AnalyzeWholeMIPSDir::sandRatio = sandRatio;
}
