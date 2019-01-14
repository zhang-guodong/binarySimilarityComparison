//
// Created by mufengjun260 on 17-10-13.
//

#ifndef ICESHAVER_RESULTSAVER_H
#define ICESHAVER_RESULTSAVER_H


#include <vector>
#include <iostream>


class MatrixSaver {
private:
public:
    std::vector<bool> vector;

    MatrixSaver();

    int push_back(bool isSame);

    bool getLocation(int i, int j, int m, int n);

    int output(int m, int n);

    int fileOutput(int m, int n, std::string filePath);
};


#endif //ICESHAVER_RESULTSAVER_H
