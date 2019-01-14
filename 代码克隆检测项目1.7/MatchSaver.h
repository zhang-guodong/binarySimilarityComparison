//
// Created by mufengjun260 on 17-12-22.
//

#ifndef ICESHAVER_MATCHSAVER_H
#define ICESHAVER_MATCHSAVER_H

#include <string>

using namespace std;

class MatchSaver {
private:
	string matchFile, targetFile;
	int startMatchLine, endMatchLine, startTargetLine, endTargetLine, totalMatchLine, totalTargetLine, blockNum;

public:
	void setMatchFile(const string &matchFile);

	void setTargetFile(const string &targetFile);

	void setBlockNum(int blockNum);

	void setStartMatchLine(int startMatchLine);

	void setStartTargetLine(int startTargetLine);

	void setEndMatchLine(int endMatchLine);

	void setEndTargetLine(int endTargetLine);

	int getBlockNum() const;


	int getTotalMatchLine() const;

	const string &getMatchFile() const;

	const string &getTargetFile() const;

	int getStartMatchLine() const;

	int getEndMatchLine() const;

	int getStartTargetLine() const;

	int getEndTargetLine() const;

	int getTotalTargetLine() const;

	MatchSaver(string matchFile, string targetFile, int startMatchLine, int endMatchLine, int startTargetLine,
	           int endTargetLine, int totalMatchLine, int totalTargetLine, int blockNum);
};


#endif //ICESHAVER_MATCHSAVER_H
