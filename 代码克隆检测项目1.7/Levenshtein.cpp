//
// Created by mufengjun260 on 17-11-8.
//

#include "Levenshtein.h"

int Levenshtein::levenshtein(vector<int> str1, vector<int> str2) {
    //获取向量长度
    int length_str1 = str1.size();
    int length_str2 = str2.size();

    int i, j;
    int tmp;
    vector<vector<int>> d(length_str1 + 1, vector<int>(length_str2 + 1));
    // int d[length_str1 + 1][length_str2 + 1];

    //赋初始值
    for (i = 0; i < length_str1 + 1; i++) {
        d[i][0] = i;
    }
    for (j = 0; j < length_str2 + 1; j++) {
        d[0][j] = j;
    }

    //计算编辑距离
    for (i = 1; i < length_str1 + 1; i++) {
        for (j = 1; j < length_str2 + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                tmp = 0;
            } else {
                tmp = 1;
            }
            d[i][j] = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j])) + tmp;
        }
    }

    //显示结果
    for (i = 0; i < length_str1 + 1; i++) {
        for (j = 0; j < length_str2 + 1; j++) {
            //cout<<d[i][j]<<"\t";
        }
        //cout<<endl;
    }

    //返回编辑距离
    return d[length_str1][length_str2];
}
