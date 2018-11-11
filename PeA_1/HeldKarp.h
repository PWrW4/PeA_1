#pragma once
#include <vector>
#include "Graph.h"


class HeldKarp
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

	bool ifVectorContain(std::vector<int> vect, int value);
	std::vector<int> getVectorWithoutElement(std::vector<int> vect, int value);

	Graph * G;
public:

	void Resolve();
	void ShowRoute();
	HeldKarp(Graph * _G);
	~HeldKarp();
};
