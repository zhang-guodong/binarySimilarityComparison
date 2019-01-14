//
// Created by mufengjun260 on 18-1-25.
//

#include "MIPSPretreatment.h"

using namespace std;

string MIPSPretreatment::getSection(std::string filePath) {
	string sectionPath;
	sectionPath = filePath + ".elf.section";

	//调用readelf -S
	string command =
			"/home/mufengjun260/Software/buildroot-2017.11.2/output/host/bin/mipsel-linux-readelf -S " + filePath +
			" > " + sectionPath;
	const char *commandInChar = command.data();

	//运行命令，等待命令进程结束
	FILE *pipe = popen(commandInChar, "r");
	if (pipe == NULL) {
		cout << "popen failed";
	}
	char *line;

	while (fgets(line, sizeof(line), pipe) != NULL) {
	}

	pclose(pipe);
	return sectionPath;
}

string MIPSPretreatment::getTable(std::string filePath) {
	string tablePath;
	tablePath = filePath + ".table";

	//调用objdump -t
	string command =
			"/home/mufengjun260/Software/buildroot-2017.11.2/output/host/bin/mipsel-linux-objdump -t " + filePath +
			" > " + tablePath;
	const char *commandInChar = command.data();

	//运行命令，等待命令进程结束
	FILE *pipe = popen(commandInChar, "r");
	if (pipe == NULL) {
		cout << "popen failed";
	}
	char *line;

	while (fgets(line, sizeof(line), pipe) != NULL) {
	}

	pclose(pipe);
	return tablePath;
}

string MIPSPretreatment::getDump(string filePath) {
	string dumpPath;
	dumpPath = filePath + ".dump";

	//调用objdump -t
	string command =
			"/home/mufengjun260/Software/buildroot-2017.11.2/output/host/bin/mipsel-linux-objdump -S " + filePath +
			" > " + dumpPath;
	const char *commandInChar = command.data();

	//运行命令，等待命令进程结束
	FILE *pipe = popen(commandInChar, "r");
	if (pipe == NULL) {
		cout << "popen failed";
	}
	char *line;

	while (fgets(line, sizeof(line), pipe) != NULL) {
	}

	pclose(pipe);
	return dumpPath;
}
