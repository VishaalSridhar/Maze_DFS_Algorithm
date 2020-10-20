#pragma once
#include "NodeList.h"
#include "Graph.h"


NodeList* DFS(NodeList* initial, bool direction);
NodeList* notFinished(NodeList* initial);
NodeList* reached(NodeList* initial);
NodeList* discovered(NodeList* initial); 
