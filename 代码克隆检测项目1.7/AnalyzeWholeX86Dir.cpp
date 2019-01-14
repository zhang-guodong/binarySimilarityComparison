//
// Created by mufengjun260 on 18-2-28.
//

#include "AnalyzeWholeX86Dir.h"

map<vector<string>, double>
AnalyzeWholeX86Dir::analyzeX86Dir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath) {
	map<vector<string>, double> resultMap, minResultMap;
	double similarity;
	DirParser dirParser;
	FileNameGenerator fileNameGenerator;
	AnalyzeBetweenX86Files analyzeBetweenX86Files;
	analyzeBetweenX86Files.setSandRatio(this->getSandRatio());
	vector<string> binaryFiles = dirParser.getFiles(dirPath);
	vector<string> pretreatedFiles;
	Pretreatment pretreatment;

	//对结果添加CSV Head
	ofstream ofstream1(resultPath);
	string headString = "matchFilePath,targetFilePath,startMatchLine,endMatchLine,startTargetLine,endTargetLine,blockNum,usage,totalUsage\n";
	ofstream1 << headString;
	ofstream1.close();

	//进行二进制文件的预处理
	for (int i = 0; i <= binaryFiles.size() - 1; i++) {
		vector<string> tmpVector = pretreatment.pretreatX86BinaryFile(binaryFiles[i]);
		pretreatedFiles.insert(pretreatedFiles.end(), tmpVector.begin(), tmpVector.end());
	}

	//对处理后的二进制文件
	for (int i = 0; i <= pretreatedFiles.size() - 1; i++) {
		double maxSimilarity;
		bool foundMini = false;
		vector<string> minVector;
		string matchFileName = pretreatedFiles[i];

		vector<string> fileNameVector = fileNameGenerator.getCorrespondFileName(matchFileName, binaryFiles);
		for (int k = 0; k <= fileNameVector.size() - 1; k++) {
			vector<string>::iterator iterator1 = find(pretreatedFiles.begin(), pretreatedFiles.end(),
			                                          fileNameVector[k]);
			if (iterator1 != pretreatedFiles.end()) {
				vector<string> tmpVector;
				tmpVector.push_back(pretreatedFiles[i]);
				tmpVector.push_back(fileNameVector[k]);

//                if (tmpVector[0] ==
//                    "/home/mufengjun260/githubRepo/SimilarityComparisonEngine/testOfLinuxKernel/vmlinux-4.10.10/vmlinux-4.10.10.o.dump.sha_transform>:") {
//                    if (tmpVector[1] ==
//                        "/home/mufengjun260/githubRepo/SimilarityComparisonEngine/testOfLinuxKernel/vmlinux-4.10.11/vmlinux-4.10.11.o.dump.sha_transform>:") {
//                        cout << "bingo!!!";
//                    }
//                }

				similarity = analyzeBetweenX86Files.analyzeBetweenX86Files(tmpVector[0], tmpVector[1], gramSize,
				                                                           windowStep,
				                                                           windowLength, resultPath);
				//cout << endl << tmpVector[0] << ' ' << tmpVector[1] << endl << similarity << endl;
/*
                if (k == 0) {
                    maxSimilarity = similarity;
                    minVector.push_back(tmpVector[0]);
                    minVector.push_back(tmpVector[1]);
                }*/
//
//                resultMap.insert(pair<vector<string>, double>(tmpVector, similarity));
/*for total data
                if ((similarity >= maxSimilarity) && (similarity != -1)) {
                    minVector.clear();
                    maxSimilarity = similarity;
                    minVector.push_back(tmpVector[0]);
                    minVector.push_back(tmpVector[1]);
                }
*/
				if (similarity == 1) {
					foundMini = true;
					break;
				}
			}
		}

		if (!foundMini) {
			for (int j = 0; j <= pretreatedFiles.size() - 1; j++) {
				if (i != j) {
					vector<string> tmpVector;
					tmpVector.push_back(pretreatedFiles[i]);
					tmpVector.push_back(pretreatedFiles[j]);

					//for debug
//                    if (tmpVector[0] ==
//                        "/home/mufengjun260/githubRepo/SimilarityComparisonEngine/testOfLinuxKernel/vmlinux-4.10.10/vmlinux-4.10.10.o.dump.sha_transform>:") {
//                        if (tmpVector[1] ==
//                            "/home/mufengjun260/githubRepo/SimilarityComparisonEngine/testOfLinuxKernel/vmlinux-4.10.11/vmlinux-4.10.11.o.dump.sha_transform>:") {
//                            cout << "bingo!!!";
//                        }
//                    }

					//for debug


					similarity = analyzeBetweenX86Files.analyzeBetweenX86Files(pretreatedFiles[i], pretreatedFiles[j],
					                                                           gramSize, windowStep, windowLength,
					                                                           resultPath);

					//cout << endl << tmpVector[0] << ' ' << tmpVector[1] << endl << similarity << endl;
/*
                    if (j == 0 || (i == 0 && j == 1)) {
                        maxSimilarity = similarity;
                        minVector.push_back((pretreatedFiles[i]));
                        minVector.push_back(pretreatedFiles[j]);
                    }
*/
//                    resultMap.insert(pair<vector<string>, double>(tmpVector, similarity));
					/*
					if ((similarity <= maxSimilarity) && (similarity != -1)) {
						minVector.clear();
						maxSimilarity = similarity;
						minVector.push_back(pretreatedFiles[i]);
						minVector.push_back(pretreatedFiles[j]);
					}
					*/

					if (similarity == 1) break;
				}
			}
		}

		//minResultMap.insert(pair<vector<string>, double>(minVector, maxSimilarity));
	}


	//输出最小结果
//    ofstream minOutput(dirPath + "/minResult.txt");
//    map<vector<string>, double>::iterator iterator1;
//    iterator1 = minResultMap.begin();
//    while (iterator1 != minResultMap.end()) {
//        minOutput << iterator1->first[0] << "    " << iterator1->first[1] << "   " << iterator1->second
//                  << endl;
//        iterator1++;
//    }

	return resultMap;
}

float AnalyzeWholeX86Dir::getSandRatio() const {
	return sandRatio;
}

void AnalyzeWholeX86Dir::setSandRatio(float sandRatio) {
	AnalyzeWholeX86Dir::sandRatio = sandRatio;
}
