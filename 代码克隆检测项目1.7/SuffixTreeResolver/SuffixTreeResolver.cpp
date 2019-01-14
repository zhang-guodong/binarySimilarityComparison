//
// Created by mufengjun260 on 4/23/18.
//

#include "SuffixTreeResolver.h"

extern vector<int> Input;
extern int inputLength;
extern Node *nodeArray;;
extern std::unordered_map<long, Edge> edgeHash;
int matchLength, targetLength, ISM, blockNum = 0;//ISM for instruction set max
int totalBML;

SuffixTree SuffixTreeResolver::buildSuffixTree(vector<int> plain) {
	Input = plain;

	inputLength = Input.size() - 1;

	// Allocating memory to the array of nodes.
	nodeArray = (Node *) malloc(2 * inputLength * (sizeof(Node)));

	SuffixTree tree(0, 0, -1);

	for (int i = 0; i <= inputLength; i++) {
		tree.carryPhase(tree, i);
	}

	//tree.printAllEdges();
	return tree;
}

vector<MatchSaver>
SuffixTreeResolver::getCompareResult(vector<int> matchVector, vector<int> targetVector, string matchFilePath,
                                     string targetFilePath, int BML, int instructionSetMax) {

	Node::noOfNodes = 1;
	edgeHash.erase(edgeHash.begin(), edgeHash.end());

	matchLength = matchVector.size() - 1;
	targetLength = targetVector.size() - 1;
	totalBML = BML;
	ISM = instructionSetMax;
	vector<MatchSaver> resultMatchSaver;

	if (matchVector.size() < BML || targetVector.size() < BML) {
		return resultMatchSaver;
	}

	//generate tmpVector to build suffixTree
	vector<int> tmpVector = matchVector;
	tmpVector.push_back(-1);
	tmpVector.insert(tmpVector.end(), targetVector.begin(), targetVector.end());
	tmpVector.push_back(-2);
	cout << endl;
	for (int ii = 0; ii <= tmpVector.size(); ii++) {
		cout << tmpVector[ii] << ",";
	}
	cout << endl;

	SuffixTree tree = buildSuffixTree(tmpVector);

	for (int i = -1; i <= ISM; i++) {
		Edge *e = Edge::findEdgePtr(0, i);
		if (e != NULL) {
			e->parentEdge = NULL;
			int tmpNum = e->pretreatEdge(resultMatchSaver);
		}
	}

	//add filePath to result
	for (int i = 0; i < resultMatchSaver.size(); i++) {
		resultMatchSaver[i].setMatchFile(matchFilePath);
		resultMatchSaver[i].setTargetFile(targetFilePath);
	}

	if (nodeArray) {
		delete nodeArray;
		nodeArray = NULL;
	}

	return resultMatchSaver;
}

