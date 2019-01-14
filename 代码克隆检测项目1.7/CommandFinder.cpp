//
// Created by mufengjun260 on 17-10-29.
//

#include <iostream>
#include "CommandFinder.h"

/**
 * 根据输入的反汇编结果分析出其中指令的偏移量
 * @param filePath 反汇编结果路径
 * @return  指令偏移量offset
 */
int CommandFinder::getCommandOffset(string line) {
    return contentCommand(line);
}

/**
 * 检测字符串中是否包含at&t指令，并返回指令在该字符串中的定位
 * @param tmpLine  待检测字符串
 * @return 如包含at&t指令，返回指令在字符串中的定位；否则，返回-1
 */
int CommandFinder::contentCommand(string tmpLine) {
    vector<string> commands{"mov", "push", "pop", "lea", "inc", "dec", "neg", "not", "add", "sub", "imul", "xor", "or",
                            "and", "sal", "shl", "sar", "shr", "mul", "clt", "idiv", "div", "cmp", "test", "set", "jmp",
                            "je", "jne", "js", "jnz", "jg", "jge", "jl", "jle", "ja", "jae", "jb", "jbe", "call",
                            "leave", "ret", "btr", "in", "ud2", "cli", "pause", "bt", "sti", "nop", "tzcnt", "cld",
                            "hlt", "prefetchnta", "lar","iret","fxsave"};
    for (int i = 0; i <= commands.size() - 1; i++) {
        if (tmpLine.find(commands[i]) != string::npos) {
            return tmpLine.find(commands[i]);
        }
    }
    return -1;
}
