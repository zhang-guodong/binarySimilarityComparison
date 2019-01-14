//
// Created by mufengjun260 on 17-10-26.
//

#include "AnalyzeBetweenMIPSFiles.h"
#include "TokenGenerater.h"
#include "ToNGramToken.h"
#include "MatrixSaver.h"
#include "TokenAnalyzer.h"
#include "SimilarPortion.h"
#include "WindowMatch.h"
#include <vector>
#include <iostream>
#include <sstream>
#include "MIPSOperationResolver.h"

/**
 * 对两个command文件（或二进制文件（实验性内容））进行N-Gram化的token比对，得到文件1相对于文件2的相似度
 * @param filePath1 文件1,为被测样本
 * @param filePath2 文件2,为样本库中的某一样本
 * @param gramSize N-Gram中的N，体现生成token的粒度（但N的增大不会降低复杂度，仅会对结果产生影响）
 * @param ISM 窗口滑块的步进
 * @param windowLength 窗口滑块的基准Length
 * @return 文件1相对于文件2的相似度
 */
double
AnalyzeBetweenMIPSFiles::analyzeBetweenMIPSFiles(std::string filePath1, std::string filePath2, int gramSize,
                                                 int ISM,
                                                 int windowLength, string resultPath) {

	//generator token
	vector<int> fileVectorOfToken1, fileVectorOfToken2;

	cout << "analyzing file " << filePath1 << " and " << filePath2 << endl;

	MIPSOperationResolver mipsOperationResolver = MIPSOperationResolver();
	fileVectorOfToken1 = mipsOperationResolver.readOperationFromFile(filePath1);
	fileVectorOfToken2 = mipsOperationResolver.readOperationFromFile(filePath2);


	if (fileVectorOfToken1.size() == 0 | fileVectorOfToken2.size() == 0) return -1;
	WindowMatch windowMatch;
	SuffixTreeResolver suffixTreeResolver;
	//windowMatch.setSandRatio(this->getSandRatio());

	vector<MatchSaver> resultVector = suffixTreeResolver.getCompareResult(fileVectorOfToken1, fileVectorOfToken2,
	                                                                      filePath1, filePath2, windowLength, ISM);

	double ratioOfMatch = resultVector.size() == 0 ? -1 : windowMatch.getRatio(resultVector);


	//输出
	ofstream ofstream1(resultPath, ios::app);
	vector<MatchSaver>::iterator iterator1 = resultVector.begin();
	while (!ofstream1.good()) {
		cout << "waiting";
	}
	string lastMatchFilePath = "";
	double totalLine = 0;
	while (iterator1 != resultVector.end()) {
		if (lastMatchFilePath != iterator1->getMatchFile()) {
			lastMatchFilePath = iterator1->getMatchFile();
			totalLine = iterator1->getEndMatchLine() - iterator1->getStartMatchLine() + 1;
		} else {
			totalLine += iterator1->getEndMatchLine() - iterator1->getStartMatchLine() + 1;
		}

		string foutString;
		foutString += iterator1->getMatchFile() + ","
		              + iterator1->getTargetFile() + ","
		              + intToString(iterator1->getStartMatchLine()) + ","
		              + intToString(iterator1->getEndMatchLine()) + ","
		              + intToString(iterator1->getStartTargetLine()) + ","
		              + intToString(iterator1->getEndTargetLine()) + ","
		              + intToString(iterator1->getBlockNum()) + ","
		              + doubleToString(ratioOfMatch * 100)
		              + doubleToString(100 * totalLine / (1 + iterator1->getTotalMatchLine()))
		              + "\n";
		ofstream1 << foutString;
		ofstream1 << endl;
		cout << foutString << endl;
		iterator1++;
	}
	ofstream1.close();


	//生成N-Gram序列
	//fileVectorOfNGram1 = toNGramToken1.toNGramToken(fileVectorOfToken1, correspondenceOfNGram, gramSize);
	//fileVectorOfNGram2 = toNGramToken1.toNGramToken(fileVectorOfToken2, correspondenceOfNGram, gramSize);

	//获取分析结果，生成矩阵
	//MatrixSaver resultSaver;
	//TokenAnalyzer tokenAnalyzer;
	//resultSaver = tokenAnalyzer.tokenAnalyzer(fileVectorOfNGram1, fileVectorOfNGram2);
	//行，列
	//resultSaver.output(fileVectorOfNGram1.size() - 1, fileVectorOfNGram2.size() - 1);

	//利用Levenshtein算法获取编辑距离
	//Levenshtein levenshtein;
	//double distance=levenshtein.levenshtein(fileVectorOfNGram1,fileVectorOfNGram2);

	//获取相似度
	//SimilarPortion similarPortion;
	/*
	cout << fixed << setprecision(4)
		 << 100 *
			similarPortion.similarPortion(&resultSaver, fileVectorOfNGram1.size() - 1, fileVectorOfNGram2.size() - 1)
		 << '%';
		 */
	//return similarPortion.similarPortion(&resultSaver, fileVectorOfNGram1.size() - 1, fileVectorOfNGram2.size() - 1);
	return ratioOfMatch;
}

string AnalyzeBetweenMIPSFiles::intToString(int tmpInt) {
	stringstream ss;
	ss << tmpInt;
	string result;
	ss >> result;
	return result;
}

string AnalyzeBetweenMIPSFiles::doubleToString(double tmpDouble) {
	stringstream ss;
	ss << tmpDouble;
	string result;
	ss >> setprecision(4) >> result;
	return result;
}

float AnalyzeBetweenMIPSFiles::getSandRatio() const {
	return sandRatio;
}

void AnalyzeBetweenMIPSFiles::setSandRatio(float sandRatio) {
	AnalyzeBetweenMIPSFiles::sandRatio = sandRatio;
}
