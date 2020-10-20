#include "DirectedNode.h"

int DirectedNode::ROW_MAX;
int DirectedNode::COL_MAX;

DirectedNode::DirectedNode(int row, int col, int value) {
	this->pos.first = row;
	this->pos.second = col;
	this->value = abs(value);
	this->dirchange = value < 0;
}

vector<pair<int, int>> DirectedNode::getTargets(bool dir) {
	vector<pair<int, int>> ret;
	if(this->value == 0) return vector<pair<int, int>>();

	if(!dir) { //moving regularly
		ret.emplace_back(this->pos.first + this->value, this->pos.second);
		ret.emplace_back(this->pos.first - this->value, this->pos.second);
		ret.emplace_back(this->pos.first, this->pos.second + this->value);
		ret.emplace_back(this->pos.first, this->pos.second - this->value);
	} else { //moving diagonally
		ret.emplace_back(this->pos.first + this->value, this->pos.second + this->value);
		ret.emplace_back(this->pos.first + this->value, this->pos.second - this->value);
		ret.emplace_back(this->pos.first - this->value, this->pos.second + this->value);
		ret.emplace_back(this->pos.first - this->value, this->pos.second - this->value);
	}

	//check for invalid values
	for(auto iter = ret.begin(); iter != ret.end(); ++iter) {
		if(iter->first < 0 || iter->first >= ROW_MAX || iter->second < 0 || iter->second >= COL_MAX) {
			ret.erase(iter);
			--iter;
		}
	}

	return ret;
}

void DirectedNode::setLimits(int row, int col) {
	ROW_MAX = row;
	COL_MAX = col;
}