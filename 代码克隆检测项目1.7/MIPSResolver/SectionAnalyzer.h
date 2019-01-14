//
// Created by mufengjun260 on 18-1-27.
//

#ifndef ICESHAVER_SECTIONANALYZER_H
#define ICESHAVER_SECTIONANALYZER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class SectionAnalyzer {
public:
	SectionAnalyzer(string sectionPath);

	string getValue(string sectionName, string titleName);

	void setSectionPath(string sectionPath);


private:
	string sectionPath;

	string getLineName(string line);

	int getStartSet(string headName);

};


#endif //ICESHAVER_SECTIONANALYZER_H
