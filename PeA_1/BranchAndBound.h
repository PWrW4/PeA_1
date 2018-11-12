#pragma once
#include "Graph.h"
#include "BBElement.h"

class BranchAndBound
{
private:
	std::vector<BBElement> nodeArray;
	int upperBound = INT32_MAX;
	Graph * G;
	int reduceMatrix(std::vector<std::vector<int>>* matrix_to_put, BBElement * from);
	void travel(std::vector<std::vector<int>>* matrix_to_put, int vertex, int vertex1);
	BBElement * getLowestCostNode();
	BBElement * createBBElement(int vertex, BBElement * from);
public:
	void Resolve();
	void ShowRoute();
	BranchAndBound(Graph * _G);
	~BranchAndBound();
};

