#include "sortInstruction.h"
#include "levenshteinRecursive.h"
#include <iostream>
using namespace std;

int main()
{
    SortInstruction soutins1;
    string a="add";
    cout << soutins1.sortInstruction(a) << endl;
//	cout << sortInstruction("aaa") << endl;
    /*
    vector<int> str1{1,2};
	vector<int> str2{1};
	cout << levenshtein(str1, str2) << endl;
    */
	return 0;
}