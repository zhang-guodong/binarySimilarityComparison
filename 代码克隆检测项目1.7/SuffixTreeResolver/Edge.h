//
// Created by mufengjun260 on 4/19/18.
//

#ifndef ICESHAVER_EDGE_H
#define ICESHAVER_EDGE_H


#include "Node.h"
#include "MatchSaver.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Edge {
public:
	// Edges are hash-searched on the basis of startNode.
	// startNode = -1 means that this edge is not valid yet.

	int startNode;
	int endNode;
	int startLabelIndex;
	int endLabelIndex;
	int specialSignNum = 0;
	int distanceToRoot = 0;
	bool isLeaf = false;

	Edge *parentEdge;

	void printID();

	void insert();

	void remove();

	// node is the starting node and c is the ASCII input char.
	// Static because I want to call it without using an instantiated object.
	static long returnHashKey(int node, int c);

	static Edge findEdge(int node, int c);

	// Constructors.
	Edge() : startNode(-1) {};

	// everytime a new edge is created, a new node is also created and thus the
	// endNode is declared as below.
	Edge(int start, int first, int last) :
			startNode(start),
			endNode(Node::noOfNodes++),
			startLabelIndex(first),
			endLabelIndex(last) {};

	// Destructor
	~Edge() {
		//  cout << "destroying edge " << startNode << " " << endNode << endl;
	}

	int pretreatEdge(vector<MatchSaver> &resultVector);

	static Edge *findEdgePtr(int node, int asciiChar);
};

#endif //ICESHAVER_EDGE_H
