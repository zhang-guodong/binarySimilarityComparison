//
// Created by mufengjun260 on 18-1-28.
//
#include "MIPSResolverUtil.h"

long MIPSResolverUtil::HexToInt(string hexNum) {
	long result = 0, count = 0;
	for (int tmpInt = 0; tmpInt <= hexNum.length() - 1; tmpInt++) {
		switch (hexNum[tmpInt]) {
			case 'a':
			case 'A': {
				count = 10;
				break;

			}
			case 'b':
			case 'B': {
				count = 11;
				break;

			}
			case 'c':
			case 'C': {
				count = 12;
				break;
			}
			case 'd':
			case 'D': {
				count = 13;
				break;
			}
			case 'e':
			case 'E': {
				count = 14;
				break;
			}
			case 'f':
			case 'F': {
				count = 15;
				break;
			}
			default: {
				count = hexNum[tmpInt] - '0';
				break;
			}
		}
		result = (result << 4) + count;
	}
	return result;
}

void MIPSResolverUtil::mkdir(string dirPath) {

	//调用objdump -t
	string command =
			"mkdir " + dirPath;
	const char *commandInChar = command.data();

	//运行命令，等待命令进程结束
	FILE *pipe = popen(commandInChar, "r");
	if (pipe == NULL) {
		cout << "mkdir failed";
	}
	char *line;

	while (fgets(line, sizeof(line), pipe) != NULL) {
	}

	pclose(pipe);
}
