/*
 *汇编指令分类：
 *1、数据传输
 *2、算术运算
 *3、逻辑运算
 *4、串指令
 *5、程序转移
 *6、其他指令：伪指令
 *           控制指令
 **/
/*
"neg", 
"clt",
"set",
"btr",
"in",
"ud2",
"pause",
"bt",
"tzcnt",
"prefetchnta"
*/
#include <fstream>
#include "sortInstruction.h"

map<string, int> allOrder =
    {
        //1、数据传输
        //1-1、通用数据传送指令
        {"mov", 1},
        {"push", 1},
        {"pop", 1},
        //1-2、输入输出端口传送指令
        //1-3、目的地址传送指令
        {"lea", 1},

        //2、算术运算
        {"inc", 2},
        {"dec", 2},
        {"add", 2},
        {"sub", 2},
        {"imul", 2},
        {"mul", 2},
        {"idiv", 2},
        {"div", 2},
        {"cmp", 2},

        //3、逻辑运算
        {"not", 3},
        {"xor", 3},
        {"or", 3},
        {"and", 3},
        {"sal", 3},
        {"shl", 3},
        {"sar", 3},
        {"shr", 3},
        {"test", 3},

        //4、串操作
//        {"", },

        //5、程序转移
        //5-1、无条件转移指令
        {"jmp", 5},
        {"call", 5},
        {"ret", 5},
        //5-2、条件转移指令
        {"je", 5},
        {"jne", 5},
        {"js", 5},
        {"jnz", 5},
        {"jg", 5},
        {"jge", 5},
        {"jl", 5},
        {"jle", 5},
        {"ja", 5},
        {"jae", 5},
        {"jb", 5},
        {"jbe", 5},
        //5-5、处理器控制指令
        {"hlt", 5},
        {"nop", 5},
        {"std", 5},
        {"cld", 5},
        {"sti", 5},
        {"cli", 5},

        //6、其他指令
//        {"", },

    };

int sortInstruction(string order)
{
    int type = allOrder[order];
    if (type == 0)
    {
        ofstream mcfile;
        mcfile.open("orderNotInMap.txt", ios::app);
        mcfile << order << endl;
        mcfile.close();
    }
    return type;
}