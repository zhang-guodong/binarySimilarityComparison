#include <iostream>
#include "sortInstruction.h"
using namespace std;

int main()
{
    cout << sortInstruction("add") << endl;
	cout << sortInstruction("aaa") << endl;
	cout << sortInstruction("aaa") << endl;
    cout << sortInstruction("bbb") << endl;
    //TODO:学习map中find的用法
    /*
    string nFindKey = "aaa"; //要查找的Key
    //定义一个条目变量(实际是指针)
    typedef map<string, int> UDT_MAP_STRING_INT;
    map<string, int> :: iterator ip = allOrder.find(nFindKey);
    if(ip == allOrder.end())
    {
        //没找到
        cout << "found!" << endl;
    }
    else
    {
        //找到
        cout << "not found!" << endl;
    }
    allOrder.find()
    */
    /*
    vector<int> str1{1,2};
	vector<int> str2{1};
	cout << levenshtein(str1, str2) << endl;
    */
	return 0;
}