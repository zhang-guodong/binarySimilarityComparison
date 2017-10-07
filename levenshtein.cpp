#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int levenshtein(char * str1, char * str2)
{
	int length_str1 = strlen(str1);
	int length_str2 = strlen(str2);
	//TODO d需要改成动态数组
	int d[20][10];
	for (int i = 0; i < length_str1+1; i++)
			{
				d[i][0] = i;
	}
	for (int i = 0; i < length_str2+1; i++)
	{
		d[0][i] = i;
	}
	for (int i = 1; i < length_str1+1; i++)
	{
		for (int j = 1; j < length_str2+1; j++)
		{
			int same = 1;
			if (str1[i-1] == str2[j-1])
			{
				same = 0;
			}
			else
			{
				same = 1;
			}
			d[i][j] = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j])) + same;
		}
	}
	
	for (int i = 0; i < length_str1+1; i++)
	{
		for (int j = 0; j < length_str2+1; j++)
		{
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
	
	return d[length_str1][length_str2];
}

int main()
{
	
	cout<<levenshtein("abdef", "abcd");
	system("pause");
	return 0;
}