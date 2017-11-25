/*
 *使用了linux系统命令，只能在linux系统下运行
 *
 *程序流程：
 *1、查找Makefile
 *2、依次打开Makefile    //TODO
 *3、获取CONFIG名称和*.o的对应关系
 *4、打开根目录下的.config
 *5、获取CONFIG名称及其设置值（y或is not set）
 *6、根据对应关系获取目标*.o
 *7、查找*.c和*.h
 *8、按照原目录复制
**/
#include <stdlib.h>

#include <iostream>
using namespace std;

#define FILENAME "Makefile"
#define LINUXCODELOCATION "Desktop/linux-4.9.10/"

int findMakefile()
{
    system("find Desktop/linux-4.9.10/ -name Makefile fprint MakefileList.txt");
}

int openConfig()
{
    
}

int main() 
{
//  system("find %d -name %d", LINUXCODELOCATION, FILENAME);
    findMakefile();
    return 0;
}