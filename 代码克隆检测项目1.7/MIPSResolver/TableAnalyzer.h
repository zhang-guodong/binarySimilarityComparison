//
// Created by mufengjun260 on 18-1-28.
//

#ifndef ICESHAVER_TABLEANALYZER_H
#define ICESHAVER_TABLEANALYZER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class TableAnalyzer {
public:
	TableAnalyzer(string tablePath);

	void setTablePath(string tablePath) { this->tablePath = tablePath; };

	string getAddr(string line);

	string getSymbolName(string line);

	string getSectionName(string line);

	string getSize(string line);

	void TEST();

private:
	int sectionStartAt;
	string tablePath;
};


#endif //ICESHAVER_TABLEANALYZER_H

