#include <vector>
#include <iostream>
using namespace std;

int levenshtein(vector<int> str1, vector<int> str2)
{
	//获取向量长度
	int length_str1 = str1.size();
	int length_str2 = str2.size();

	int i, j;
	int tmp;
//	int d[length_str1 + 1][length_str2 + 1];
	vector<vector<int>> d(length_str1 + 1, vector<int>(length_str2 + 1));

	//赋初始值
	for (i = 0; i < length_str1 + 1; i++)
	{
		d[i][0] = i;
	}
	for (j = 0; j < length_str2 + 1; j++)
	{
		d[0][j] = j;
	}

	//计算编辑距离
	for (i = 1; i < length_str1 + 1; i++)
	{
		for (j = 1; j < length_str2 + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				tmp = 0;
			}
			else
			{
				tmp = 1;
			}
			//d[i][j] = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j])) + tmp;
			if (d[i - 1][j - 1] < d[i][j - 1])
			{
				if (d[i - 1][j - 1] < d[i - 1][j])
				{
					d[i][j] = d[i - 1][j - 1] + tmp;
				}
				else
				{
					d[i][j] = d[i - 1][j] + tmp;
				}
			}
			else
			{
				if (d[i][j - 1] < d[i - 1][j])
				{
					d[i][j] = d[i][j - 1] + tmp;
				}
				else
				{
					d[i][j] = d[i - 1][j] + tmp;
				}
			}
		}
	}
	
	//显示计算过程矩阵
	for (i = 0; i < length_str1+1; i++)
	{
		for (j = 0; j < length_str2+1; j++)
		{
			cout<<d[i][j]<<"\t";
		}
		cout<<endl;
	}

	//返回编辑距离
	return d[length_str1][length_str2];
}

int main()
{
	vector<int> str1{9,8,5,7};
	vector<int> str2{9,8,5}; 
	cout << levenshtein(str1, str2);
	return 0;
}
