/*
 **********2017.12.11**********
 *跳过了根据CONFIG获取*.o的步骤，直接采用Makefile中所有的*.o文件
 *发现一个设计问题：
 *根据对应关系获取的源码并不是全被用到，需要根据预编译来选择源码文件中的内容
 *
 **********2017.11.25**********
 *使用了linux系统命令，只能在linux系统下运行
 *
 *程序流程：
 *1、查找Makefile
 *2、依次打开Makefile
 *3、获取CONFIG名称和*.o的对应关系
 *4、打开根目录下的.config
 *5、获取CONFIG名称及其设置值（y或is not set）
 *6、根据对应关系获取目标*.o
 *7、查找*.c和*.h	//
 *8、按照原目录复制
**/
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int findPointOInAllMakefiles()
{
	system("grep -o -E \"[0-9a-zA-Z-]+\.o|\w+\.o\" allMakefiles.txt >> allPointOFiles.txt");
}

int findFileAndStoreFilename(string linuxCodeLocation,
							 string codeFileName,
					  		 string storeFile)
{
	string command = "find " + linuxCodeLocation + " -name "
					 + codeFileName + " >> " + storeFile;
	system(command.data());
	return 0;
}

int openMakefileByList()
{
	ifstream in("MakefileList.txt");
	string line;
	string command;

	if(in)
	{
		while (getline (in, line))
		{ 
//			cout << line << endl;
			command = "cat " + line + " >> allMakefiles.txt ";
			system(command.data());
		}
	}
	else
	{
		cout <<"no MakefileList.txt!" << endl;
	}
	return 0;
}

int findAndCopyPointO(string linuxCodeLocation)
{
	ifstream in("allPointOFiles.txt");
	string line;
	if(in)
	{
		while(getline(in, line))
		{
			line.erase(line.end() - 2, line.end());
			findFileAndStoreFilename(linuxCodeLocation, line + ".c",
									 "allPointOFilesLocation.txt");
			findFileAndStoreFilename(linuxCodeLocation, line + ".h",
									 "allPointOFilesLocation.txt");
		}
	}
	else
	{
		cout <<"no allPointOFiles.txt!" << endl;
	}
}

int copyCodeFiles(string aimFolder)
{
	ifstream in("allPointOFilesLocation.txt");
	string line;
	string command = "mkdir " + aimFolder;
	system(command.data());
	if(in)
	{
		while(getline(in, line))
		{
			command = "cp --parents " + line + " " + aimFolder;
			system(command.data());
		}
	}
	else
	{
		cout <<"no allPointOFilesLocation.txt!" << endl;
	}
}

int rmTmpFile()
{
	system("rm MakefileList.txt");
	system("rm allMakefiles.txt");
	system("rm allPointOfiles.txt");
	system("rm allPointOFilesLocation.txt");

	return 0;
}

int main() 
{
	//源码压缩包解压后的文件夹的根目录
	string linuxCodeLocation = "Desktop/linux-4.9.10/";

	//查找文件夹中所有的Makefile，储存到MakefileList.txt
	findFileAndStoreFilename(linuxCodeLocation, "Makefile", "MakefileList.txt");

	//依次打开所有的Makefile，获取其中的内容
	//TODO：获取CONFIG和*.o的对应关系
	openMakefileByList();

	//查找所有的Makefile中的*.o，储存到allPointOFiles.txt
	findPointOInAllMakefiles();

	//查找*.c*.h和的位置，储存到allPointOFilesLocation.txt
	findAndCopyPointO(linuxCodeLocation);

	//按照原目录复制*.c*.h到新目录
	copyCodeFiles("linuxCodeUsed");

	//删除程序执行过程中产生的临时文件
//	rmTmpFile();

    return 0;
}
