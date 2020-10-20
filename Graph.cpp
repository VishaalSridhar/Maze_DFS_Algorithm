//
// Created by Vishaal Sridhar on 4/23/2018.
//
#include "Graph.h"
#include <iterator>
using namespace std;

int Graph::rowVal;
int Graph::colVal;


int convert(int value) {
	return abs(value);
}

void Graph::matrix(int row, int col) {
	rowVal = row;
	colVal = col;
}

Graph::Graph(int row, int col, int value) {
	//init();
	this->tile.x = row;
	this->tile.y = col;
	int temp = convert(value);
	this->curr = temp;
	if (value < 0) {
		this->changeDirection = true;
	}
	else {
		this->changeDirection = false;
	}
}

vector<struct Graph::point> Graph::targets(bool direction) {
	struct point squares;
	vector<struct point> temp;
	if (this->curr == 0) {
		return vector<struct point>();
	}
	if (!direction) {
		squares.x = this->tile.x + this->curr;
		squares.y = this->tile.y;
		temp.push_back(squares);

		squares.x = this->tile.x - this->curr;
		squares.y = this->tile.y;
		temp.push_back(squares);

		squares.x = this->tile.x;
		squares.y = this->tile.y + this->curr;
		temp.push_back(squares);

		squares.x = this->tile.x;
		squares.y = this->tile.y - this->curr;
		temp.push_back(squares);
	}
	else if (direction) {
		squares.x = this->tile.x + this->curr;
		squares.y = this->tile.y + this->curr;
		temp.push_back(squares);

		squares.x = this->tile.x + this->curr;
		squares.y = this->tile.y - this->curr;
		temp.push_back(squares);

		squares.x = this->tile.x - this->curr;
		squares.y = this->tile.y + this->curr;
		temp.push_back(squares);

		squares.x = this->tile.x - this->curr;
		squares.y = this->tile.y - this->curr;
		temp.push_back(squares);
	}
	for (auto i = temp.begin(); i != temp.end(); ++i) {
		if ((i->x < 0) || (i->x >= rowVal) || (i->y <0) || (i->x >= colVal)) {
			
		}
	}
	//invalidTargets(temp);
	return temp;
}

void Graph::invalidTargets(vector<struct point> &temp) {

}

