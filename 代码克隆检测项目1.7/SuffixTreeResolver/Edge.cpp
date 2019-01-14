//
// Created by mufengjun260 on 4/19/18.
//

#include "Edge.h"
#include "MatchSaver.h"

extern unordered_map<long, Edge> edgeHash;
extern vector<int> Input;
extern int matchLength, targetLength, ISM, blockNum;//ISM for instruction set max
extern int totalBML;

long Edge::returnHashKey(int nodeID, int c) {
	// long contor = (1/2)*(nodeID + c)*(nodeID + c + 1) + c;
	// return contor;
	return (long) (nodeID +
	               (((long) c) << 59));
}

/*
 * Insert an edge into the hash table
 */
void Edge::insert() {
	this->isLeaf = (endLabelIndex == Input.size() - 1);
	long key = returnHashKey(startNode, Input[startLabelIndex]);
	// edgeHash.insert(make_pair<int, Node>(key, this));
	edgeHash[key] = *this;
	//cout << "Inserted " << startNode << " " << endNode << " " << startLabelIndex << " " << endLabelIndex << " " << key << endl;
}

/*
 * Remove an edge from the hash table.
 */
void Edge::remove() {
	long key = returnHashKey(startNode, Input[startLabelIndex]);
	edgeHash.erase(key);
	//cout << "Removed " << key << " " << startNode << " " << Input[startLabelIndex] << endl;
}

/*
 * Find an edge in the hash table corresponding to NODE & ASCIICHAR
 *
 */
Edge Edge::findEdge(int node, int asciiChar) {
	long key = returnHashKey(node, asciiChar);
	unordered_map<long, Edge>::const_iterator search = edgeHash.find(key);
	if (search != edgeHash.end()) {
		//cout << "Entry found for " << node << " " << asciiChar << endl;
		return edgeHash.at(key);
	}

	//cout << "Entry NOT found for " << node << " " << asciiChar << endl;
	// Return an invalid edge if the entry is not found.
	return Edge();
}

/**
 *
 * @param parentEdge
 * @return the num of special symbol between two string and end symbol from thisEdge to all EndLeaf append this node!
 */
int Edge::pretreatEdge(vector<MatchSaver> &resultVector) {
	if (this->isLeaf) {
		if (this->startLabelIndex <= matchLength + 1) {
			this->specialSignNum = 2;
		} else {
			this->specialSignNum = 1;
		}
		return this->specialSignNum;
	}

	//set distance to root
	if (this->parentEdge != NULL) {
		this->distanceToRoot = this->parentEdge->distanceToRoot + endLabelIndex - startLabelIndex + 1;
	} else {
		this->distanceToRoot = endLabelIndex - startLabelIndex + 1;
	}

	//Traverse all son edge
	vector<Edge> match, target;
	for (int i = -1; i <= ISM; i++) {
		Edge *e = findEdgePtr(this->endNode, i);
		if (e != NULL) {
			e->parentEdge = this;
			int tmpNum = e->pretreatEdge(resultVector);
			if (tmpNum == 1)target.push_back(*e);
			if (tmpNum == 2)match.push_back(*e);
			this->specialSignNum = max(tmpNum, this->specialSignNum);
			if (this->startLabelIndex < matchLength + 1) {
				this->specialSignNum = 2;
			}
		}
	}

	if (target.size() != 0 && match.size() != 0) {
		for (int matchInt = 0; matchInt < match.size(); matchInt++) {
			for (int targetInt = 0; targetInt < target.size(); targetInt++) {
				if (parentEdge != NULL) {
					bool isDup = 0;
					int startMatchLine = match[matchInt].startLabelIndex - match[matchInt].parentEdge->distanceToRoot;
					int endMatchLine = match[matchInt].startLabelIndex - 1;
					int startTargetLine = target[targetInt].startLabelIndex -
					                      match[matchInt].parentEdge->distanceToRoot - (matchLength + 2);
					int endTargetLine = target[targetInt].startLabelIndex - 1 - (matchLength + 2);

					for (int innerInt = 0; innerInt < resultVector.size(); innerInt++) {
						if (resultVector[innerInt].getEndMatchLine() == endMatchLine &&
						    resultVector[innerInt].getEndTargetLine() == endTargetLine &&
						    resultVector[innerInt].getStartMatchLine() > startMatchLine &&
						    resultVector[innerInt].getStartTargetLine() > startTargetLine) {
							resultVector[innerInt].setStartMatchLine(startMatchLine);
							resultVector[innerInt].setStartTargetLine(startTargetLine);
							isDup = 1;
						}
					}

					if ((!isDup) && (endTargetLine - startTargetLine >= totalBML - 1) &&
					    (endMatchLine - startMatchLine >= totalBML - 1)) {
						MatchSaver matchSaver("", "", startMatchLine, endMatchLine, startTargetLine, endTargetLine,
						                      matchLength, targetLength, resultVector.size());

						resultVector.push_back(matchSaver);
					}
				} else {
					bool isDup = 0;
					int startMatchLine = match[matchInt].startLabelIndex - 1;
					int endMatchLine = match[matchInt].startLabelIndex - 1;
					int startTargetLine = target[targetInt].startLabelIndex - 1 - (matchLength + 2);
					int endTargetLine = target[targetInt].startLabelIndex - 1 - (matchLength + 2);

					for (int innerInt = 0; innerInt < resultVector.size(); innerInt++) {
						if (resultVector[innerInt].getEndMatchLine() == endMatchLine &&
						    resultVector[innerInt].getEndTargetLine() == endTargetLine &&
						    resultVector[innerInt].getStartMatchLine() > startMatchLine &&
						    resultVector[innerInt].getStartTargetLine() > startTargetLine) {
							resultVector[innerInt].setStartMatchLine(startMatchLine);
							resultVector[innerInt].setStartTargetLine(startTargetLine);
							isDup = 1;
						}
					}

					if ((!isDup) && (endTargetLine - startTargetLine >= totalBML - 1) &&
					    (endMatchLine - startMatchLine >= totalBML - 1)) {
						MatchSaver matchSaver("", "", startMatchLine, endMatchLine, startTargetLine, endTargetLine,
						                      matchLength, targetLength, resultVector.size());

						resultVector.push_back(matchSaver);
					}
				}
			}
		}
	}


	return this->specialSignNum;
}

Edge *Edge::findEdgePtr(int node, int asciiChar) {
	long key = returnHashKey(node, asciiChar);
	unordered_map<long, Edge>::const_iterator search = edgeHash.find(key);
	if (search != edgeHash.end()) {
		//cout << "Entry found for " << node << " " << asciiChar << endl;
		return &edgeHash.at(key);
	}

	//cout << "Entry NOT found for " << node << " " << asciiChar << endl;
	// Return an invalid edge if the entry is not found.
	return NULL;
}
