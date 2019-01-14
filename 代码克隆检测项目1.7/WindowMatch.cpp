//
// Created by mufengjun260 on 17-12-22.
//

#include "WindowMatch.h"

vector<MatchSaver>
WindowMatch::getMatchMIPSResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
                                string targetFilePath, int windowStep, int windowLength) {
	vector<MatchSaver> result;
	if (matchVector.size() < windowLength || targetVector.size() < windowLength) {
		return result;
	}
	int startMatchLine = -1, endMatchLine = -1, startTargetLine = -1, endTargetLine = -1;
	//int lastStartMatchLine = -1, lastEndMatchLine = -1, lastStartTargetLine = -1, lastEndTargetLine = -1;

	//对matchVector进行窗口滑块比对
	int matchInt = 0;

	while (matchInt <= matchVector.size() - 1 - windowLength) {

		//抽取第一个token串中的部分串
		vector<int> tmpVector;
		for (int tmpMatchInt = matchInt;
		     (tmpMatchInt <= matchInt + windowLength - 1) && (tmpMatchInt <= matchVector.size() - 1); tmpMatchInt++) {
			tmpVector.push_back(matchVector[tmpMatchInt]);
		}
		//对targetVector遍历(使用匹配-扩展的方法)
		int targetInt = 0;
		while (targetInt <= targetVector.size() - 1) {
			if (tmpVector[0] == targetVector[targetInt]) {
				bool isMatch = true;
				for (int tmpFindInt = 1; (tmpFindInt <= tmpVector.size() - 1); tmpFindInt++) {
					//段内匹配
					if (tmpVector[tmpFindInt] != targetVector[targetInt + tmpFindInt]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) {
					//设定标定点
					startMatchLine = matchInt;
					endMatchLine = (matchInt + windowLength - 1 < matchVector.size() - 1) ? matchInt + windowLength - 1 :
					               matchVector.size() - 1;
					startTargetLine = targetInt;
					endTargetLine = (targetInt + windowLength - 1 < targetVector.size() - 1) ? targetInt +
					                                                                           windowLength - 1 :
					                targetVector.size() - 1;
					//向后扩展检索
					while (endMatchLine + 1 <= matchVector.size() - 1 & endTargetLine + 1 <= targetVector.size() - 1 &
					       (matchVector[endMatchLine + 1] == targetVector[endTargetLine + 1])) {
						endMatchLine++;
						endTargetLine++;
					}
					//向前扩展检索
					while (startMatchLine - 1 >= 0 & startTargetLine - 1 >= 0 &
					       (matchVector[startMatchLine - 1] == targetVector[startTargetLine - 1])) {
						startMatchLine--;
						startTargetLine--;
					}
					//添加结果进Vector
					if ((endMatchLine - startMatchLine + 1 >= windowLength) &&
					    (endTargetLine - startTargetLine + 1 >= windowLength)) {

						MatchSaver matchSaver(matchFilePath, targetFilePath, startMatchLine, endMatchLine,
						                      startTargetLine,
						                      endTargetLine, matchVector.size() - 1, targetVector.size() - 1,0);
						result.push_back(matchSaver);
						matchInt = endMatchLine + 1;
						targetInt = endTargetLine + 1;
						startMatchLine = 0;
						endMatchLine = 0;
						startTargetLine = 0;
						endTargetLine = 0;
						continue;
					}
				}
			}
			targetInt++;
		}
		matchInt += windowStep;
		if (matchInt >= matchVector.size()) break;
	}

	return result;
}

double WindowMatch::getRatio(vector<MatchSaver> vectorOfMatchSaver) {
	double result;
	int countOfLine = 0;
	vector<MatchSaver>::iterator iterator1 = vectorOfMatchSaver.begin();
	while (iterator1 != vectorOfMatchSaver.end()) {
		countOfLine += iterator1->getEndMatchLine() - iterator1->getStartMatchLine() + 1;
		iterator1++;
	}
	result = 1.0 * countOfLine / (vectorOfMatchSaver[0].getTotalMatchLine() + 1);
	return result;
}

vector<MatchSaver>
WindowMatch::getMatchX86Result(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
                               string targetFilePath, int windowStep, int windowLength) {
	vector<MatchSaver> result;
	if (matchVector.size() < windowLength || targetVector.size() < windowLength) {
		return result;
	}
	int startMatchLine = -1, endMatchLine = -1, startTargetLine = -1, endTargetLine = -1;
	int lastStartMatchLine = -1, lastEndMatchLine = -1, lastStartTargetLine = -1, lastEndTargetLine = -1;
	//对matchVector进行窗口滑块比对
	int matchInt = 0;

	while (matchInt <= matchVector.size() - 1 - windowLength) {

		//对targetVector遍历(使用匹配-扩展的方法)
		int targetInt = 0;
		while (targetInt <= targetVector.size() - 1) {
			if (matchVector[matchInt] == targetVector[targetInt]) {
				bool isMatch = true;

				if (isMatch) {
					//设定标定点
					startMatchLine = matchInt;
					endMatchLine = startMatchLine;
					startTargetLine = targetInt;
					endTargetLine = startTargetLine;
					//向后扩展检索
					while (endMatchLine + 1 <= matchVector.size() - 1 & endTargetLine + 1 <= targetVector.size() - 1 &
					       (matchVector[endMatchLine + 1] == targetVector[endTargetLine + 1])) {
						endMatchLine++;
						endTargetLine++;
					}
					//向前扩展检索
					while (startMatchLine - 1 >= 0 & startTargetLine - 1 >= 0 &
					       (matchVector[startMatchLine - 1] == targetVector[startTargetLine - 1])) {
						startMatchLine--;
						startTargetLine--;
					}

					bool blockIsSand = false;
					//添加结果进Vector
					if ((endMatchLine - startMatchLine + 1 >= windowLength) &
					    (endTargetLine - startTargetLine + 1 >= windowLength)) {

						//test if have sand between this block and the last block,if have,merge them
						if (lastStartMatchLine != -1 && lastEndMatchLine != -1 && lastStartTargetLine != -1 &&
						    lastEndTargetLine) {
							blockIsSand = isSand(lastStartMatchLine, lastEndMatchLine, startMatchLine, endMatchLine,
							                     lastStartTargetLine, lastEndTargetLine, startTargetLine, endTargetLine,
							                     sandRatio);
							if (blockIsSand) {
								//connect the two blocks
								result[result.size() - 1].setEndMatchLine(endMatchLine);
								result[result.size() - 1].setEndTargetLine(endTargetLine);
							}
						}

						if (!blockIsSand) {
							MatchSaver matchSaver(matchFilePath, targetFilePath, startMatchLine, endMatchLine,
							                      startTargetLine,
							                      endTargetLine, matchVector.size() - 1, targetVector.size() - 1,
							                      result.size() + 1);
							result.push_back(matchSaver);
						}
						matchInt = endMatchLine + 1;
						targetInt = endTargetLine + 1;

						//define last Nums;
						lastStartMatchLine = startMatchLine;
						lastEndMatchLine = endMatchLine;
						lastStartTargetLine = startTargetLine;
						lastEndTargetLine = endTargetLine;

						//reset line Nums;
						startMatchLine = 0;
						endMatchLine = 0;
						startTargetLine = 0;
						endTargetLine = 0;
						continue;
					}
				}
			}
			targetInt++;
		}
		matchInt += windowStep;
		if (matchInt >= matchVector.size()) break;
	}

	return result;
}

bool WindowMatch::isSand(int matchStartLine1, int matchEndLine1, int matchStartLine2, int matchEndLine2,
                         int targetStartLine1, int targetEndLine1, int targetStartLine2, int targetEndLine2,
                         float sandRatio) {
	float acceptableSandSize = ((matchEndLine1 - matchStartLine1) + (matchEndLine2 - matchStartLine2)) * sandRatio;
	return ((matchStartLine2 - matchEndLine1 <= acceptableSandSize) &&
	        (matchStartLine2 - matchEndLine1 > 0) &&
	        (targetStartLine2 - targetEndLine1 > 0) &&
	        (targetStartLine2 - targetEndLine1 <= acceptableSandSize))
	       || ((matchStartLine1 - matchEndLine2 <= acceptableSandSize) &&
	           (matchStartLine1 - matchEndLine2 > 0) &&
	           (targetStartLine1 - targetEndLine2 > 0) &&
	           (targetStartLine1 - targetEndLine2 <= acceptableSandSize));
}

float WindowMatch::getSandRatio() const {
	return sandRatio;
}

void WindowMatch::setSandRatio(float sandRatio) {
	WindowMatch::sandRatio = sandRatio;
}

vector<MatchSaver>
WindowMatch::getMatchJavaResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
                                string targetFilePath, int windowStep, int windowLength) {
	vector<MatchSaver> result;
	if (matchVector.size() < windowLength || targetVector.size() < windowLength) {
		return result;
	}
	int startMatchLine = -1, endMatchLine = -1, startTargetLine = -1, endTargetLine = -1;
	int lastStartMatchLine = -1, lastEndMatchLine = -1, lastStartTargetLine = -1, lastEndTargetLine = -1;

	//对matchVector进行窗口滑块比对
	int matchInt = 0;

	while (matchInt <= matchVector.size() - 1 - windowLength) {

		//对targetVector遍历(使用匹配-扩展-校验长度的方法)
		int targetInt = 0;
		while (targetInt <= targetVector.size() - 1) {
			if (matchVector[matchInt] == targetVector[targetInt]) {
				bool isMatch = true;

				if (isMatch) {
					//设定标定点
					startMatchLine = matchInt;
					endMatchLine = startMatchLine;
					startTargetLine = targetInt;
					endTargetLine = startTargetLine;
					//向后扩展检索
					while (endMatchLine + 1 <= matchVector.size() - 1 & endTargetLine + 1 <= targetVector.size() - 1 &
					       (matchVector[endMatchLine + 1] == targetVector[endTargetLine + 1])) {
						endMatchLine++;
						endTargetLine++;
					}
					//向前扩展检索
					while (startMatchLine - 1 >= 0 & startTargetLine - 1 >= 0 &
					       (matchVector[startMatchLine - 1] == targetVector[startTargetLine - 1])) {
						startMatchLine--;
						startTargetLine--;
					}
					bool blockIsSand = false;
					//添加结果进Vector
					if ((endMatchLine - startMatchLine + 1 >= windowLength) &
					    (endTargetLine - startTargetLine + 1 >= windowLength)) {

						if (lastStartMatchLine != -1 && lastEndMatchLine != -1 && lastStartTargetLine != -1 &&
						    lastEndTargetLine) {
							blockIsSand = isSand(lastStartMatchLine, lastEndMatchLine, startMatchLine, endMatchLine,
							                     lastStartTargetLine, lastEndTargetLine, startTargetLine, endTargetLine,
							                     sandRatio);
							if (blockIsSand) {
								//connect the two blocks
								result[result.size() - 1].setEndMatchLine(endMatchLine);
								result[result.size() - 1].setEndTargetLine(endTargetLine);
							}
						}
						if (!blockIsSand) {

							MatchSaver matchSaver(matchFilePath, targetFilePath, startMatchLine, endMatchLine,
							                      startTargetLine,
							                      endTargetLine, matchVector.size() - 1, targetVector.size() - 1,
							                      result.size() + 1);
							result.push_back(matchSaver);
						}
						matchInt = endMatchLine + 1;
						targetInt = endTargetLine + 1;


						//define last Nums;
						lastStartMatchLine = startMatchLine;
						lastEndMatchLine = endMatchLine;
						lastStartTargetLine = startTargetLine;
						lastEndTargetLine = endTargetLine;

						startMatchLine = 0;
						endMatchLine = 0;
						startTargetLine = 0;
						endTargetLine = 0;
						continue;
					}
				}
			}
			targetInt++;
		}
		matchInt += windowStep;
		if (matchInt >= matchVector.size()) break;
	}

	return result;
}
