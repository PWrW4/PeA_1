#pragma once
#include <vector>
#include "Graph.h"

class BBElement
{
public:
	std::vector<int> route;
	BBElement * from = nullptr;
	int lowerBound;
	std::vector<std::vector<int>> * matrixCost;
	int vertex;
	bool done;
	bool vertexExistInRoute(int v);
	BBElement(int _vertex, BBElement * _from, int _lb, std::vector<std::vector<int>> * _matrixCost);
	~BBElement();
};

