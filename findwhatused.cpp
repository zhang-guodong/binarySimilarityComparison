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

int findPointOInAllMakefiles(string allMakefiles,
							 string allPointOFiles)
{
	string command = "grep -o -E \"[0-9a-zA-Z-]+\.o|\w+\.o\" "
					 + allMakefiles + " >> " + allPointOFiles;
	system(command.data());
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

int openMakefileByList(string MakefileList, string allMakefiles)
{
	ifstream in(MakefileList);
	string line;
	string command;

	if(in)
	{
		while (getline (in, line))
		{ 
			command = "cat " + line + " >> " + allMakefiles;
			system(command.data());
		}
	}
	else
	{
		cout << "no " << MakefileList << "!" << endl;
	}
	return 0;
}

int getLocationOfPointO(string linuxCodeLocation,
						string allPointOFiles,
						string allCodeFilesLocation)
{
	ifstream in(allPointOFiles);
	string line;
	if(in)
	{
		while(getline(in, line))
		{
			line.erase(line.end() - 2, line.end());
			findFileAndStoreFilename(linuxCodeLocation, line + ".c",
									 allCodeFilesLocation);
			findFileAndStoreFilename(linuxCodeLocation, line + ".h",
									 allCodeFilesLocation);
		}
	}
	else
	{
		cout <<"no " << allPointOFiles << "!" << endl;
	}
}

int copyCodeFiles(string aimFolder, string allCodeFilesLocation)
{
	ifstream in(allCodeFilesLocation);
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
		cout <<"no " << allCodeFilesLocation << "!" << endl;
	}
}

int showOverTime()
{
	system("date");
}

int rmTmpFile(string fileName)
{
	string command = "rm " + fileName;
	system(command.data());
}

int main() 
{
	//源码压缩包解压后的文件夹的根目录
	string linuxCodeLocation = "Desktop/linux-4.10.10/";
	//复制目的地文件夹
	string aimFolder = "codeUsedIn41010";
	//Makefile目录表
	string MakefileList = "MakefileList.txt";
	//Makefile中的内容
	string allMakefiles = "allMakefiles.txt";
	//从Makefile中获得的.o文件名册
	string allPointOFiles = "allPointOFiles.txt";
	//.o文件目录表
	string allCodeFilesLocation = "allCodeFilesLocation.txt";

	//查找文件夹中所有的Makefile，储存到MakefileList.txt
	cout << "正在查找Makefile文件..." << endl;
	findFileAndStoreFilename(linuxCodeLocation, "Makefile", MakefileList);
	showOverTime();

	//依次打开所有的Makefile，获取其中的内容
	//TODO：获取CONFIG和*.o的对应关系
	cout << "正在获取Makefile中的内容..." << endl;
	openMakefileByList(MakefileList, allMakefiles);
	showOverTime();

	//查找所有的Makefile中的*.o，储存到allPointOFiles.txt
	cout << "正在查找Makefile中的.o文件..." << endl;
	findPointOInAllMakefiles(allMakefiles, allPointOFiles);
	showOverTime();

	//查找*.c*.h和的位置，储存到allCodeFilesLocation.txt
	cout << "正在查找源码位置..." << endl;
	getLocationOfPointO(linuxCodeLocation, allPointOFiles, allCodeFilesLocation);
	showOverTime();

	//按照原目录复制*.c*.h到新目录
	cout << "正在复制源码..." << endl;
	copyCodeFiles(aimFolder, allCodeFilesLocation);
	showOverTime();

	//删除程序执行过程中产生的临时文件
	rmTmpFile(MakefileList);
	rmTmpFile(allMakefiles);
	rmTmpFile(allPointOFiles);
	rmTmpFile(allCodeFilesLocation);
	showOverTime();
    return 0;
}
