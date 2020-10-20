#pragma once

#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
#include "ListNode.h"

using std::pair;
using std::vector;
using std::ostream;
using std::stringstream;

class DirectedNode {
public:
	//info about node in game
	pair<int, int> pos; //position of trampoline in grid.
	int value; //the number on this node
	bool dirchange = false; //if this node causes a direction change. Set explicitly when true.

	//info about node in graph
	ListNode* targets[2];
	DirectedNode* parent;

	DirectedNode(int row, int col, int value);

	/**
	 * Calculate a list of targets that can be traveled to from this node.
	 * Invalid targets wil not be returned.
	 *
	 * @var dir false if moving normally, true if diagonally
	 */
	vector<pair<int, int>> getTargets(bool dir);

	static void setLimits(int row, int col);

	void printPos() {
		std::cout << "(" << this->pos.first+1 << "," << this->pos.second+1 << ")";
	}

private:
	//info about the game
	static int ROW_MAX, COL_MAX;
};


