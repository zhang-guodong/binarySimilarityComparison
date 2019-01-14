//
// Created by mufengjun260 on 5/6/18.
//

#include "AnalyzeBetweenJavaFiles.h"

double
AnalyzeBetweenJavaFiles::analyzeBetweenJavaFiles(std::string filePath1, std::string filePath2, int gramSize,
                                                 int ISM,
                                                 int windowLength, string resultPath) {
	//generator token
	vector<int> fileVectorOfToken1, fileVectorOfToken2;

	WindowMatch windowMatch;
	JavaResolver javaResolver;

	fileVectorOfToken1 = javaResolver.resolveJavaBinFile(filePath1);
	fileVectorOfToken2 = javaResolver.resolveJavaBinFile(filePath2);

	cout << "analyzing file " << filePath1 << " and " << filePath2 << endl;

	if (fileVectorOfToken1.size() == 0 | fileVectorOfToken2.size() == 0) return -1;
	SuffixTreeResolver suffixTreeResolver;
	//windowMatch.setSandRatio(this->getSandRatio());

	//vector<MatchSaver> resultVector = suffixTreeResolver.getCompareResult(fileVectorOfToken1, fileVectorOfToken2,
	//                                                                      filePath1, filePath2, windowLength, ISM);

	vector<MatchSaver> resultVector=windowMatch.getMatchJavaResult(fileVectorOfToken1,fileVectorOfToken2,filePath1,filePath2,gramSize,windowLength);
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
		              + doubleToString(ratioOfMatch * 100)+","
		              + doubleToString(100 * totalLine / (1 + iterator1->getTotalMatchLine()))
		              + "\n";
		ofstream1 << foutString;
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

string AnalyzeBetweenJavaFiles::intToString(int tmpInt) {
	stringstream ss;
	ss << tmpInt;
	string result;
	ss >> result;
	return result;
}

string AnalyzeBetweenJavaFiles::doubleToString(double tmpDouble) {
	stringstream ss;
	ss << tmpDouble;
	string result;
	ss >> setprecision(4) >> result;
	return result;
}
