#pragma once
#include "Graph.h"

class BruteForce
{
private:
	int tmpCost;
	int* tmpRoute;

	bool* visitedCities;
	int startTop;

	int bestCost;
	int* bestRoute;

	int whichCity;
	int iteration;

	Graph * G;
public:
	BruteForce(Graph * _G);
	~BruteForce();
};

