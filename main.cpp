#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

#include "DirectedNode.h"
#include "ListNode.h"

using namespace std;


ListNode* dfs_visit(ListNode* start, bool dir) {
	ListNode* ret = NULL;
	ListNode* returned = NULL;
	ListNode* last;
	bool nextdir;
	while(start != NULL) {
		if(start->val->value == 0) { //goal node
			cout << "Found goal node!" << endl;
			start->next = NULL;
			return start;
		}
		nextdir = dir xor start->val->dirchange;
		cout << "nextdir is " << nextdir << endl;
		if(start->status == ListNode::UNDISCOVERED) {
			start->status = ListNode::DISCOVERED;
			returned = dfs_visit(start->val->targets[nextdir], nextdir);
		}
		if(returned != NULL) {
			ret = new ListNode();
			ret->next = returned;
			ret->val = start->val;
			cout << "Adding ";
			ret->val->printPos();
			cout << "To string" << endl;
			return ret;
		}
		last = start;
		start = start->next;
	}
	last->status = ListNode::EXPLORED;

	return ret;
}

int main(int argc, char** argv) {
	//check that we have an appropriate number of arguments
	if(argc != 2) {
		cout << "Usage: " << argv[0] << " [maze file]" << endl;
		return EXIT_FAILURE;
	}

	//load maze input file and check that it is valid.
	ifstream mazefile(argv[1]);
	if(mazefile.fail()) {
		cout << "Problem with your input file. Please check that it exists and try again." << endl;
		return EXIT_FAILURE;
	}

	int NUM_ROWS, NUM_COLS;

	mazefile >> NUM_ROWS >> NUM_COLS;

	DirectedNode::setLimits(NUM_ROWS, NUM_COLS);
	ListNode* adjlist[NUM_ROWS][NUM_COLS][2]; //syntax: node[row][col][dir]; Space-inefficient probably!
	DirectedNode* maze[NUM_ROWS][NUM_COLS];

	cout << "Beginning first loop" << endl;

	int curval;
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			mazefile >> curval;
			maze[i][j] = new DirectedNode(i, j, curval);
			for(int k = 0; k < 2; ++k) {
				adjlist[i][j][k] = new ListNode();
			}
			maze[i][j]->targets[0] = adjlist[i][j][0];
			maze[i][j]->targets[1] = adjlist[i][j][1];
		}
	}

	cout << "finished first loop" << endl;

	//fill out adjacency list
	ListNode* cur;
	DirectedNode* targetnode;
	for(int i = 0; i < NUM_ROWS; ++i) {
		for(int j = 0; j < NUM_COLS; ++j) {
			for(int k = 0; k < 2; ++k) {
				cur = adjlist[i][j][k];
				auto targets = maze[i][j]->getTargets(k == 1);

				for(auto target : targets) {
					if(cur->next != NULL) cur = cur->next;

					cur->val = maze[target.first][target.second];
					cur->next = new ListNode();
				}
				if(cur->next == NULL) cur->val = maze[i][j];
				cur->next = NULL;
			}
		}
	}

	cout << "Finished second loop" << endl;


	//set up source node
	ListNode* src = adjlist[0][0][0]; //we start at (0,0) moving normally

	//execute DFS search
	ListNode* solution = dfs_visit(src, false);
	ListNode* realSolution = new ListNode();
	realSolution->val = maze[0][0]; //add start node
	realSolution->next = solution;

	//flip and print results
	queue<ListNode*> Q;
	while(realSolution != NULL) {
		Q.push(realSolution);
		realSolution = realSolution->next;
	}

	cout << "Solution: ";
	while(!Q.empty()) {
		Q.front()->val->printPos();
		cout << " ";
		Q.pop();
	}
	cout << endl;
	return EXIT_SUCCESS;
}