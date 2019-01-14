//
// Created by mufengjun260 on 5/6/18.
//

#include <fstream>
#include <JAVAResolver/JavaResolver.h>
#include "AnalyzeWholeJavaDir.h"
#include "AnalyzeBetweenJavaFiles.h"

map<vector<string>, double>
AnalyzeWholeJavaDir::analyzeJavaDir(string dirPath, int gramSize, int windowStep, int windowLength, string resultPath) {
    map<vector<string>, double> resultMap, minResultMap;
    double similarity;
    DirParser dirParser;
    FileNameGenerator fileNameGenerator;
    AnalyzeBetweenJavaFiles analyzeBetweenFiles;
    string dirPath1 = dirPath.substr(0, dirPath.find('+'));
    vector<string> binaryFiles1 = dirParser.getFiles(dirPath1);
    string dirPath2 = dirPath.substr(dirPath.find('+') + 1, dirPath.length());
    vector<string> binaryFiles2 = dirParser.getFiles(dirPath2);
    vector<string> JavaTokenFiles;
    vector<string> pathOfOpFile1, pathOfOpFile2;

    //集中反编译
    for (int i = 0; i < binaryFiles1.size(); i++) {
        string command;

        string tmpString = binaryFiles1[i].substr(0, binaryFiles1[i].find(".class")) + ".bc";
        //获取class文件的反汇编文件
        command = "javap -c "
                  + binaryFiles1[i]
                  + " >> "
                  + binaryFiles1[i].substr(0, binaryFiles1[i].find(".class")) + ".bc";
        system(command.data());

        //从反汇编文件中获取助记符
        command = "awk '/[0-9]: /{print $2}' "
                  + binaryFiles1[i].substr(0, binaryFiles1[i].find(".class")) + ".bc"
                  + " >> "
                  + binaryFiles1[i].substr(0, binaryFiles1[i].find(".class")) + ".mnemonic";
        system(command.data());
        pathOfOpFile1.push_back(binaryFiles1[i].substr(0, binaryFiles1[i].find(".class")) + ".mnemonic");
    }
    for (int i = 0; i < binaryFiles2.size(); i++) {
        string command;

        string tmpString = binaryFiles2[i].substr(0, binaryFiles2[i].find(".class")) + ".bc";
        //获取class文件的反汇编文件
        command = "javap -c "
                  + binaryFiles2[i]
                  + " >> "
                  + binaryFiles2[i].substr(0, binaryFiles2[i].find(".class")) + ".bc";
        system(command.data());

        //从反汇编文件中获取助记符
        command = "awk '/[0-9]: /{print $2}' "
                  + binaryFiles2[i].substr(0, binaryFiles2[i].find(".class")) + ".bc"
                  + " >> "
                  + binaryFiles2[i].substr(0, binaryFiles2[i].find(".class")) + ".mnemonic";
        system(command.data());
        pathOfOpFile2.push_back(binaryFiles2[i].substr(0, binaryFiles2[i].find(".class")) + ".mnemonic");

    }

    //对结果添加CSV Head
    ofstream ofstream1(resultPath);
    string headString = "matchFilePath,targetFilePath,startMatchLine,endMatchLine,startTargetLine,endTargetLine,blockNum,usage,totalUsage";
    ofstream1 << headString << endl;
    ofstream1.close();

    //
    //对处理后的二进制文件
    for (int i = 0; i <= pathOfOpFile1.size() - 1; i++) {
        bool foundWholeFileCopy = false;
        vector<string> minVector;
        for (int j = 0; j <= pathOfOpFile2.size() - 1; j++) {
            vector<string> tmpVector;
            tmpVector.push_back(binaryFiles1[i]);
            tmpVector.push_back(binaryFiles2[j]);
            similarity = analyzeBetweenFiles.analyzeBetweenJavaFiles(pathOfOpFile1[i], pathOfOpFile2[j],
                                                                     gramSize, windowStep, windowLength,
                                                                     resultPath);
            resultMap.insert(make_pair(tmpVector, similarity));
        }

    }


    return resultMap;
}


float AnalyzeWholeJavaDir::getSandRatio() const {
    return sandRatio;
}

void AnalyzeWholeJavaDir::setSandRatio(float sandRatio) {
    AnalyzeWholeJavaDir::sandRatio = sandRatio;
}
