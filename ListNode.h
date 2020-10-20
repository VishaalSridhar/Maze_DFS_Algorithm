#pragma once


#include "DirectedNode.h"

class DirectedNode;

class ListNode {
public:
	DirectedNode* val;
	ListNode* next;
	int status = Status::UNDISCOVERED;

	enum Status {
		UNDISCOVERED,
		DISCOVERED,
		EXPLORED
	};
};




