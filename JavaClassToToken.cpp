//
// Created by zhanggd on 19-1-5.
//

#include "JavaClassToToken.h"

vector<int> JavaClassToToken::javapClassToToken(string classPath) {
	vector<int> bytecode;
	string command;

	//判断bc文件是否存在
	fstream _file;
     _file.open(classPath.substr(0, classPath.find(".class")) + ".bc",ios::in);
     string tmpString=classPath.substr(0, classPath.find(".class")) + ".bc";
    if(!_file) {

		//获取class文件的反汇编文件
		command = "javap -c "
				+ classPath
				+ " >> "
				+ classPath.substr(0, classPath.find(".class")) + ".bc";
		system(command.data());

		//从反汇编文件中获取助记符
		command = "awk '/[0-9]: /{print $2}' "
				+ classPath.substr(0, classPath.find(".class")) + ".bc"
				+ " >> "
				+ classPath.substr(0, classPath.find(".class")) + ".mnemonic";
		system(command.data());

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
        ifstream in(classPath.substr(0, classPath.find(".class")) + ".mnemonic");
        string line;
        while (in.good()) {
            in >> line;
            bytecode.push_back(mnemonicMap[line]);
        }
	}

	return bytecode;
}
