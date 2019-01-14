//
// Created by mufengjun260 on 5/6/18.
//

#include "JavaResolver.h"
#include "JavaClassToToken.h"

vector<int> JavaResolver::resolveJavaBinFile(string binFilePath) {

    JavaClassToToken javaClassToToken1;
    vector<int> resultVector = javaClassToToken1.javapClassToToken(binFilePath);

    return resultVector;
}
