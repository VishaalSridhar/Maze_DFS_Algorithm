//
// Created by Vishaal Sridhar on 4/23/2018.
//
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include "Graph.h"
#include "NodeList.h"
#include "DFS.h"
using namespace std;

class Graph;

NodeList* temporary;
NodeList* isFinished = NULL;
NodeList* ending;
bool diagonal;

NodeList* discovered(NodeList* initial);
NodeList* reached(NodeList* initial);
NodeList* notFinished(NodeList* initial);

NodeList* DFS(NodeList* initial, bool direction) {

	cout << "before while " << endl;
	cout << "initial is " << initial << endl;
	while (initial != NULL) {
		cout << "before reached" << endl;
		//reached(initial);

		if (initial->value->curr == 0) {
			initial->next = NULL; // End recursion, reached goal
			return initial;
		}
		cout << "reached" << endl;

		if ((direction == true) && (initial->value->changeDirection == true)) {
			diagonal = false;
		}
		else if ((direction == false) && (initial->value->changeDirection == false)) {
			diagonal = false;
		}
		else if ((direction == true) && (initial->value->changeDirection == false)) {
			diagonal = true;
		}
		else if ((direction == false) && (initial->value->changeDirection == true)) {
			diagonal = true;
		}

		cout << "Checked conditions" << endl;

		//discovered(initial);
		if (initial->tileStatus == NodeList::UNDISCOVERED) {
			initial->tileStatus = NodeList::DISCOVERED;
			isFinished = DFS(initial->value->currTargets[diagonal], diagonal);
		}
		cout << "discovered" << endl;

		//notFinished(initial);
		if (isFinished != NULL) {
			temporary = new NodeList();
			temporary->next = isFinished;
			temporary->value = initial->value;
			temporary->value->print();
			cout << endl;
			return temporary;
		}
		cout << "notfinished" << endl;

		ending = initial;
		initial = initial->next;
	}
	cout << "after while, end is " << ending << endl;
	ending->tileStatus = NodeList::EXPLORED;

	cout << "about to return" << endl;
	return temporary;
}


