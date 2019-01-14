//
// Created by mufengjun260 on 4/18/18.
//

#include <assert.h>
#include <vector>
#include "SuffixTree.h"

//string Input;
int inputLength;
vector<int> Input;
int Node::noOfNodes = 1;
Node *nodeArray;
std::unordered_map<long, Edge> edgeHash;

/*
 * Break an edge so as to add new string at a specific point.
 */
int breakEdge(SuffixTree &s, Edge &e) {
	// Remove the edge
	e.remove();
	Edge *newEdge = new Edge(s.rootNode, e.startLabelIndex,
	                         e.startLabelIndex + s.endIndex - s.startIndex);
	newEdge->insert();
	// Add the suffix link for the new node.
	nodeArray[newEdge->endNode].suffixNode = s.rootNode;
	e.startLabelIndex += s.endIndex - s.startIndex + 1;
	e.startNode = newEdge->endNode;
	e.insert();
	return newEdge->endNode;
}

void SuffixTree::carryPhase(SuffixTree &tree, int lastIndex) {
	// cout << "Phase " << lastIndex << " Adding " << Input.substr(0, lastIndex + 1) << endl;
	int parentNode;
	// to keep track of the last encountered node.
	// Used for creating the suffix link.
	int previousParentNode = -1;
	if (lastIndex == 363) {
		int a = 9;
	}
	while (true) {
		// First we try to match an edge for this, if there is one edge and all
		// other subsequent suffixs would already be there.
		Edge e;
		parentNode = tree.rootNode;

		if (tree.endReal()) {
			e = Edge::findEdge(tree.rootNode, Input[lastIndex]);
			if (e.startNode != -1)
				break;
		}
			// If previoustree ends in between an edge, then we need to find that
			// edge and match after that.
		else {
			e = Edge::findEdge(tree.rootNode, Input[tree.startIndex]);
			int diff = tree.endIndex - tree.startIndex;
			if (Input[e.startLabelIndex + diff + 1] == Input[lastIndex])
				// We have a match
				break;
			//If match was not found this way, then we need to break this edge
			// and add a node and insert the string.
			//cout << " breaking edge " << endl;
			parentNode = breakEdge(tree, e);
		}

		// We have not matchng edge at this point, so we need to create a new
		// one, add it to the tree at parentNode position and then insert it
		// into the hash table.
		//
		// We are creating a new node here, which means we also need to update
		// the suffix link here. Suffix link from the last visited node to the
		// newly created node.
		//cout << "adding new edge" << endl;
		Edge *newEdge = new Edge(parentNode, lastIndex, inputLength);
		newEdge->insert();
		if (previousParentNode > 0)
			nodeArray[previousParentNode].suffixNode = parentNode;
		previousParentNode = parentNode;

		// Move to next suffix, i.e. next extension.
		if (tree.rootNode == 0)
			tree.startIndex++;
		else {
			tree.rootNode = nodeArray[tree.rootNode].suffixNode;
			//printf("using suffix link while adding %d %d\n", tree.rootNode, nodeArray[tree.rootNode].suffixNode);
		}
		tree.migrateToClosestParent();
	}

	if (previousParentNode > 0)
		nodeArray[previousParentNode].suffixNode = parentNode;
	tree.endIndex++;
	tree.migrateToClosestParent();
}

// rootNode should be equal to the closest node to the end of the tree so
// tht this can be used in the next iteration.
void SuffixTree::migrateToClosestParent() {
	// If the current suffix tree is ending on a node, this condition is already
	// met.
	if (endReal()) {
		//cout << "Nothing needs to be done for migrating" << endl;
	} else {
		Edge e = Edge::findEdge(rootNode, Input[startIndex]);
		// Above will always return a valid edge as we call this method after
		// adding above.
		if (e.startNode == -1) {
			//cout << rootNode << " " << startIndex << " " << Input[startIndex] << endl;
		}
		assert(e.startNode != -1);
		int labelLength = e.endLabelIndex - e.startLabelIndex;

		// Go down
		while (labelLength <= (endIndex - startIndex)) {
			startIndex += labelLength + 1;
			rootNode = e.endNode;
			if (startIndex <= endIndex) {
				e = Edge::findEdge(e.endNode, Input[startIndex]);
				if (e.startNode == -1) {
					//cout << rootNode << " " << startIndex << " " << Input[startIndex] << endl;
				}
				assert(e.startNode != -1);
				labelLength = e.endLabelIndex - e.startLabelIndex;
			}
		}

	}
}


bool SuffixTree::search(vector<int> pattern) {
	int len = pattern.size();
	// Starting from 0 we start searching the pattern.
	Edge e = Edge::findEdge(0, pattern[0]);
	// index until where we have matched on edge.
	int iter = 0;
	int i = -1;
	if (e.startNode != -1) {
		while (i < len) {
			//cout << "Search:\tEdge: " << e.startNode << " " << e.endNode << " : "<< Input[e.startLabelIndex] << " " << Input[e.endLabelIndex] << " I: " << i << endl;
			// Match the pattern on this edge.
			iter = 0;
			// Match this edge as much as possible.
			while (e.endLabelIndex >= e.startLabelIndex + iter) {
				//cout << "Search:\tmatching " << Input[e.startLabelIndex + iter] << " "<< pattern[i + iter + 1]<< " at index: " << e.startLabelIndex + iter << endl;
				// If character matches we increase the iterator
				// otherwise we are done. No match.
				if (Input[e.startLabelIndex + iter] == pattern[i + iter + 1]) {
					iter++;
					// If we have a match in the middle then we are done.
					if (i + iter + 1 >= len) {
						//cout << "Search:\tWe have a match ending at "<< e.startLabelIndex + iter - 1 << endl;
						return true;
					}
				} else {
					//cout << "Search:\tMatch not found, matched only upto index:" << i + iter << endl;
					return false;
				}
			}
			// We have done all possible matches on this edge. We can proceed
			// only if the entire label matches.
			assert(iter = (e.endLabelIndex - e.startLabelIndex + 1));

			// Now we need to find another edge to match.
			e = Edge::findEdge(e.endNode, pattern[i + iter + 1]);
			if (e.startNode == -1) {
				//cout << "Search:\tMatch not found, matched only upto " << i + iter<< " " << pattern[i + iter + 1] << endl;
				return false;
			}
			i += (iter);
		}
	}
	//cout << "Search:\tMatched :D " << iter << endl;
	return true;
}

/*
 * This function prints all the edges in the suffix tree.
 */
void SuffixTree::printAllEdges() {
	int count = 0;
	//cout << "StartNode\tEndNode\tSuffixLink\tFirstIndex\tlastIndex\tString" << endl;
	// For auto : C++11 FTW :)
	for (auto it = edgeHash.begin(); it != edgeHash.end(); it++) {
		cout << it->second.startNode << "\t\t" << it->second.endNode
		     << "\t\t" << nodeArray[it->second.endNode].suffixNode
		     << "\t\t" << it->second.startLabelIndex
		     << "\t\t" << it->second.endLabelIndex
		     << "\t\t";
		count++;
		int head;
		if (inputLength > it->second.endLabelIndex)
			head = it->second.endLabelIndex;
		else
			head = inputLength;
		for (int i = it->second.startLabelIndex; i < head + 1; i++)
			cout << Input[i] << ' ';
		cout << it->second.isLeaf << ' ' << it->second.specialSignNum << endl;
	}
	cout << "Total edges: " << count << endl;
}
