#pragma once
#include "Graph.h"

class BranchAndBound
{
private:
private:
	int tmpCost;
	int* tmpRoute;

	bool* visitedCities;
	int startTop;

	int bestCost;
	int* bestRoute;

	int whichCity;
	int iteration;

	int upperLimit;
	int lowerLimit;

	bool areAllCitiesVisited();

	Graph * G;
public:
	bool Resolve(int v);
	void ShowRoute();
	BranchAndBound(Graph * _G);
	~BranchAndBound();
};

