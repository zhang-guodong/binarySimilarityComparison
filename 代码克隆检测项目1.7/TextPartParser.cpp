//
// Created by mufengjun260 on 17-10-27.
//

#include <iostream>
#include "TextPartParser.h"

/**
 * 分析反汇编文件，获取command，写入文件
 * @param textPath 反汇编文件
 * @return command文件路径组成的vector
 */
vector<string> TextPartParser::parse(string textPath) {
	string tmpLine;
	vector<string> outputFiles;
	ifstream inputFile(textPath);
	ofstream outputFile;
	int totalLineNum = 0;
	bool isWriting = false;
	bool gotOffset = false;
	CommandFinder commandFinder;
	int commandOffset = 0;
	//int dirStatus = mkdir((textPath).data(), 0666);

	if (inputFile) {
		while (getline(inputFile, tmpLine)) {
			totalLineNum++;

			if (totalLineNum > 8 && tmpLine == "") {
				isWriting = false;
				gotOffset = false;
				outputFile.close();
			}

			if (isWriting) {
				if (!gotOffset) {
					commandOffset = commandFinder.getCommandOffset(tmpLine);
					gotOffset = true;
				}
				if (tmpLine.length() >= commandOffset) {
					tmpLine = tmpLine.substr(commandOffset + 1, tmpLine.length() - commandOffset) + " ";

					string command = tmpLine.substr(0, tmpLine.find(' '));
					outputFile << command + " ";
				}
			}

			if (tmpLine.find(">:") != string::npos) {
				isWriting = true;
				string outputFilePath =
						textPath + '.' + tmpLine.substr(tmpLine.find('<') + 1, tmpLine.size() - 3 - tmpLine
								.find('<'));

//                if (outputFilePatlh ==
//                    "/home/mufengjun260/githubRepo/ICESHAVER/testOfLinuxKernel/vmlinux-4.9.10.o.dump.intel_cqm_cpu_exit>:") {
//                    //for debug
//                    cout << "bingo!!!";
//                }
				outputFile.open(outputFilePath, std::ios::out | std::ios::app);
				outputFiles.push_back(outputFilePath);
			}
		}
		return outputFiles;
	}
}
