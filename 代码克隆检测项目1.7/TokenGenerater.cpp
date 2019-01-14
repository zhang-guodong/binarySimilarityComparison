//
// Created by mufengjun260 on 17-10-7.
//

#include "TokenGenerater.h"

using namespace std;

/**
 * 输入序列文件，生成token序列
 * @param file 待转化为token串的command文件路径
 * @param correspondence 在之前已经生成的指令串和token的对应关系
 * @return 将输入的文件tokne化后组成的vector
 */
vector<int> TokenGenerater::tokenGenerater(string file, map<string, int> &correspondence) {
    fstream fstream;
    fstream.open(file, ios::in);

    if (fstream.is_open()) {
        vector<int> fileVector;
        int max_num = correspondence.size() - 1;
        string tmpString;
        while (fstream.good()) {
            fstream >> tmpString;
            if (tmpString != "") {
                //包含则返回1,不包含则返回0;不包含时执行
                if (correspondence.find(tmpString) == correspondence.end()) {
                    max_num++;
                    correspondence.insert(make_pair(tmpString, max_num));
                }

                fileVector.push_back(correspondence[tmpString]);

            }
        }
        fileVector.pop_back();
        fstream.close();
        return fileVector;
    }
}
