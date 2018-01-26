#include "RabinKarpAlgorithm.h"

#include <iostream>

using namespace std;

int main()
{
	int string[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *num = string;
//	getFingerprint(num, 2);
	int string2[] = {1, 2, 3, 4, 5, 0, 0, 8, 9};
	int *num2 = string2;
	cout << cmpStringIntExact(num, num2, 2) << endl;
	return 0;
}