#pragma once
//
// Created by Vishaal Sridhar on 4/23/2018.
//
#ifndef MAZE_GRAPH_H
#define MAZE_GRAPH_H

#include "utility"
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include "NodeList.h"
#include <iostream>
using namespace std;

class NodeList;

class Graph {
public:
	struct point {
		int x;
		int y;
	};
	struct point tile;
	int curr;
	bool changeDirection = false;
	Graph(int row, int col, int value);
	Graph* prt;
	NodeList* currTargets[2];
	vector<struct point> targets(bool direction);
	static int rowVal, colVal;
	static void matrix(int row, int col);
	//void print();
	void invalidTargets(vector<struct point> &temp);
	void print() {
		cout << "(" << this->tile.x + 1 << "," << this->tile.y + 1 << ")";
	}
};
#endif //MAZE_GRAPH_H

