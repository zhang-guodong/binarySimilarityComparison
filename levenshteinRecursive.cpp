#include <vector>
#include <iostream>
using namespace std;

int levenshtein(vector<int> str1, vector<int> str2)
{
    int result;
    //get length of str
    int length_str1 = str1.size();
    int length_str2 = str2.size();

    if (min(length_str1, length_str2) == 0)
        result = max(length_str1, length_str2);
    else 
    {
        //create no last one vector
        vector<int> str1_less1(length_str1 - 1);
        vector<int> str2_less1(length_str2 - 1);
        str1_less1.assign(str1.begin(), str1.end() - 1);
        str2_less1.assign(str2.begin(), str2.end() - 1);

        int min_lastThree = min(levenshtein(str1_less1, str2_less1),
                                min(levenshtein(str1, str2_less1),
                                    levenshtein(str1_less1, str2)));
                           
        if (str1[length_str1 - 1] == str2[length_str2 - 1])
            result = min_lastThree;
        else
            result = min_lastThree + 1; 
    }

    return result;
}
/*
int main()
{
	vector<int> str1{1,2};
	vector<int> str2{1};
	cout << levenshtein(str1, str2) << endl;
	return 0;
}