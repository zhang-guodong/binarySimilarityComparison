//
// Created by mufengjun260 on 18-1-28.
//

#ifndef ICESHAVER_MIPSRESOLVERUTIL_H
#define ICESHAVER_MIPSRESOLVERUTIL_H

#include <string>
#include <iostream>


using namespace std;

class MIPSResolverUtil {
public:
	static long HexToInt(string hexNum);

	static void mkdir(string dirPath);
};


#endif //ICESHAVER_MIPSRESOLVERUTIL_H
