//
// Created by zhanggd on 19-1-5.
//

#include "JavaClassToToken.h"

vector<int> JavaClassToToken::javapClassToToken(string classPath) {
    vector<int> bytecode;

//将操作符序列写入vector
/*
		ifstream in(classPath.substr(0, classPath.find(".class")) + ".mnemonic");
		string line;

		if (in) {
			while (getline(in, line)) {
//				int i = 0;
//	            bytecode[i] = mnemonicMap[line];
				bytecode.push_back(mnemonicMap[line]);
			}
		} else {
			cout << "No " << classPath << "!" << endl;
		}
*/
    ifstream in(classPath);
    string line;
    while (in.good()) {
        in >> line;
        bytecode.push_back(classificationMap[mnemonicMap[line]]);
    }
    in.close();

    return bytecode;
}

//JavaClassToToken::JavaClassToToken(const map<string, int> &mnemonicMap) : mnemonicMap(mnemonicMap) {}
