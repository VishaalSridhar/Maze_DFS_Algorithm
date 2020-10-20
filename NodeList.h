#pragma once
//
// Created by Vish on 4/23/2018.
//
#ifndef MAZE_LIST_H
#define MAZE_LIST_H

#include "Graph.h"
using namespace std;
class Graph;

class NodeList {
public:
	Graph* value;
	NodeList* next;
	int tileStatus = UNDISCOVERED;

	enum nodeColor {
		UNDISCOVERED, DISCOVERED, EXPLORED
	};
};
#endif //MAZE_LIST_H

