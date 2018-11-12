#pragma once
#include <vector>
#include "Graph.h"
#include "Subset.h"


class HeldKarp
{
private:
	Graph * G;
	int bestCost;
	std::vector<int> bestRoute;
	std::vector<std::vector<Subset> > subsetVector;
public:

	void Resolve();
	void ShowRoute();
	HeldKarp(Graph * _G);
	~HeldKarp();
};
