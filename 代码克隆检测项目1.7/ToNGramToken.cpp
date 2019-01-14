//
// Created by mufengjun260 on 17-10-18.
//

#include "ToNGramToken.h"

using namespace std;

/**
 * 将单独的command生成的token串进行N-Gram化后形成新的token串
 * @param normalTokenVector 未进行N-Gram化的token串
 * @param correspondence 之前已生成的N-Gram化后的整合串与N-Gram-Token的对应关系
 * @param gramSize N-Gram化时的N
 * @return N-Gram化后的token串
 */
vector<int>
ToNGramToken::toNGramToken(vector<int> normalTokenVector, map<vector<int>, int> &correspondence, int gramSize) {
    vector<int> resultVector;
    vector<int> tmpVector;
    int max_num = correspondence.size() - 1;
    for (int tmpInt = 0; tmpInt <= normalTokenVector.size() - 1; tmpInt++) {
        if (tmpVector.size() < gramSize) {
            tmpVector.push_back(normalTokenVector[tmpInt]);
        } else {
            if (!correspondence.count(tmpVector)) {
                max_num++;
                correspondence.insert(make_pair(tmpVector, max_num));
            }
            resultVector.push_back(correspondence[tmpVector]);

            //生成下一tmpString
            tmpVector.erase(tmpVector.begin());
            tmpVector.push_back(normalTokenVector[tmpInt]);
        }
    }

    return resultVector;
}
