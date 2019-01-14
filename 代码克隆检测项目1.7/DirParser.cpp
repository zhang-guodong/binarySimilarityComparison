//
// Created by mufengjun260 on 17-10-26.
//

#include "DirParser.h"

/**
 * 输入目录，递归获取该目录下所有文件路径
 * @param dirPath 待分析的目录
 * @return 该目录下所有文件路径组成的vector
 */
vector<string> DirParser::getFiles(string dirPath) {
    vector<string> files;

    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir = opendir(dirPath.c_str())) == NULL) {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            continue;
        else if (ptr->d_type == 8)    ///file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            files.push_back(dirPath + '/' + (string) ptr->d_name);
        else if (ptr->d_type == 10)    ///link file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            continue;
        else if (ptr->d_type == 4)    ///dir
        {
            vector<string> tmpVector = getFiles(dirPath + '/' + (string) ptr->d_name);
            files.insert(files.end(), tmpVector.begin(), tmpVector.end());
            /*
                memset(base,'\0',sizeof(base));
                strcpy(base,basePath);
                strcat(base,"/");
                strcat(base,ptr->d_nSame);
                readFileList(base);
            */
        }
    }
    closedir(dir);

    return files;
}
