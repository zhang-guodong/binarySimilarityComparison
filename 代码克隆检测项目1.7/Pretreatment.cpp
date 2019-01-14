//
// Created by mufengjun260 on 17-10-27.
//

#include <iostream>
#include <cstdio>
#include "Pretreatment.h"

using namespace std;

/**
 *  根据输入的二进制文件进行反汇编的预处理后写入文件，并对反汇编结果进行at&t指令的抽取
 * @param binaryPath 一个二进制.o文件的绝对路径
 * @return 经过反汇编处理与参数清洗处理的文件路径vector
 */

vector<string> Pretreatment::pretreatMIPSBinaryFile(string binaryPath) {
    string assemblyInstructions;
    assemblyInstructions = binaryPath + ".dump";

    //调用系统命令进行转换
    string command = "/home/mufengjun260/Software/buildroot-2017.11.2/output/host/bin/mipsel-linux-objdump -S " + binaryPath + " >> " + assemblyInstructions;
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

    //对生成的反汇编文件进行command的抽取
    TextPartParser textPartParser;
    vector<string> files = textPartParser.parse(assemblyInstructions);

    return files;
}

vector<string> Pretreatment::pretreatX86BinaryFile(string binaryPath) {
    string assemblyInstructions;
    assemblyInstructions = binaryPath + ".dump";

    //调用系统命令进行转换
    string command = "objdump -S " + binaryPath + " >> " + assemblyInstructions;
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

    //对生成的反汇编文件进行command的抽取
    TextPartParser textPartParser;
    vector<string> files = textPartParser.parse(assemblyInstructions);

    return files;
}
