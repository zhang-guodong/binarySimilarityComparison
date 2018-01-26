//
// Created by zhanggd on 18-1-25.
//

#include "RabinKarpAlgorithm.h"

//计算大小为windowSize的整数串的指纹
int getFingerprint(int *stringInt, int windowSize)
{
	int windowNum = 0;
	for (int i = 0; i < windowSize * STEP; ++i)
	{
		windowNum = windowNum * PROGRESSIVE + *stringInt;
		stringInt += 1;
	}
	return windowNum % FINGERSIZE;
}

//精确匹配整数串
int cmpStringIntExact(int *stringInt1, int *stringInt2, int windowSize)
{
	for (int i = 0; i < windowSize * STEP; ++i)
	{
		if (*stringInt1 == *stringInt2)
		{
			stringInt1 += 1;
			stringInt2 += 1;
		} else
		{
			return 0;
		}
	}
	return 1;
}

//比较整数串，若指纹不等则判定为不等，若指纹相等则比较字符串
int cmpStringInt(int *stringInt1, int *stringInt2, int windowSize)
{
	int fingerprint1 = getFingerprint(stringInt1, windowSize);
	int fingerprint2 = getFingerprint(stringInt2, windowSize);
	if (fingerprint1 == fingerprint2)
	{
		return cmpStringIntExact(stringInt1, stringInt2, windowSize);
	} else
	{
		return 0;
	}
}