//
// Created by mufengjun260 on 18-1-27.
//
#include "SectionAnalyzer.h"

string SectionAnalyzer::getValue(string sectionName, string titleName) {
	ifstream sectionFile(sectionPath);
	string line;
	int lineNum = 0;
	while (getline(sectionFile, line)) {
		lineNum++;
		if (lineNum <= 4) {
			continue;
		}
		if (line.find("Key to Flags:") != string::npos) {
			cout << "sectionNotFound";
			return "";
		}
		if (this->getLineName(line) == sectionName) {
			string tmpLine = line.substr(this->getStartSet(titleName), line.size() - 1);
			return tmpLine.substr(0, tmpLine.find(' '));
		}
	}
}

int SectionAnalyzer::getStartSet(string headName) {
	ifstream sectionFile(sectionPath);
	string line;
	int lineNum = 0;
	while (getline(sectionFile, line)) {
		lineNum++;
		if (lineNum == 4) {
			return line.find(headName);
		}
	}

	return -1;
}

string SectionAnalyzer::getLineName(string line) {
	string tmpLine = line.substr(getStartSet("Name"), getStartSet("type"));
	return tmpLine.substr(0, tmpLine.find(' '));
}

SectionAnalyzer::SectionAnalyzer(string sectionPath) {
	this->sectionPath = sectionPath;

}

void SectionAnalyzer::setSectionPath(string sectionPath) {
	this->sectionPath = sectionPath;
}