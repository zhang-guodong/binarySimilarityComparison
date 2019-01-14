//
// Created by mufengjun260 on 4/18/18.
//

#ifndef ICESHAVER_SUFFIXTREE_H
#define ICESHAVER_SUFFIXTREE_H

#include <string>
#include <iostream>
#include "Edge.h"
#include "Node.h"

using namespace std;

class SuffixTree {
public:
	int rootNode;   // Origin of the suffix tree
	int startIndex; // Starting index of the string represented.
	int endIndex;   // End index of the string represented.

	SuffixTree() :
			rootNode(0),
			startIndex(-1),
			endIndex(-1) {};

	SuffixTree(int root, int start, int end) :
			rootNode(root),
			startIndex(start),
			endIndex(end) {};

	// Real means that the suffix string ends at a node and thus the
	// remaining string on that edge would be an empty string.
	bool endReal() { return startIndex > endIndex; }

	void carryPhase(SuffixTree &tree, int lastIndex);

	void migrateToClosestParent();

	bool search(vector<int> pattern);

	void printAllEdges();
};


#endif //ICESHAVER_SUFFIXTREE_H
