//
// Created by mufengjun260 on 18-1-28.
//

#include "TableAnalyzer.h"

TableAnalyzer::TableAnalyzer(string tablePath) {
	this->tablePath = tablePath;
	ifstream tableFile(tablePath);
	string line;
	int lineNum = 0;
	while (getline(tableFile, line)) {
		lineNum++;
		if (lineNum < 5) {
			continue;
		}
		if (line.find(".text") != string::npos) {
			this->sectionStartAt = line.find(".text");
			break;
		}
	}

}

string TableAnalyzer::getSectionName(string line) {
	string tmpLine = line.substr(sectionStartAt, line.size() - 1);
	return tmpLine.substr(0, tmpLine.find('\t'));
}

string TableAnalyzer::getAddr(string line) {
	return line.substr(0, line.find(' '));
}

string TableAnalyzer::getSymbolName(string line) {
	return line.substr(line.find_last_of(' ') + 1, line.size() - 1);
}

string TableAnalyzer::getSize(string line) {
	string tmpLine = line.substr(0, line.find_last_of(' '));
	return tmpLine.substr(tmpLine.find_last_of('\t') + 1, tmpLine.size() - 1);
}

void TableAnalyzer::TEST() {
	ifstream tableFile(tablePath);
	string line;
	int lineNum = 0;
	while (getline(tableFile, line)) {
		lineNum++;
		if (lineNum < 5) {
			continue;
		}
		string symbolName = getSymbolName(line);
		if (getSymbolName(line) == "kernel_init") {
			string addr = getAddr(line);
			string section = getSectionName(line);
			string size = getSize(line);
			cout << getAddr(line) << ' ' << getSectionName(line) << ' ' << getSize(line);
		}
	}
}
