#include "pch.h"
#include "BruteForce.h"
#include <cstdint>


BruteForce::BruteForce(Graph * _G)
{
	G = _G;
	tmpRoute = new int[G->GetMatrixSize()];
	visitedCities = new bool[G->GetMatrixSize()];
	bestRoute = new int[G->GetMatrixSize()];

	bestCost = INT32_MAX;
	startTop = 0;
	tmpCost = 0;
	whichCity = 1;
	iteration = 0;

	for (int i = 0; i < G->GetMatrixSize(); ++i)
	{
		tmpRoute[i] = -1;
		visitedCities[i] = false;
		bestRoute[i] = -1;
	}
}


BruteForce::~BruteForce()
{
	delete[] visitedCities;
	delete[] bestRoute;
	delete[] tmpRoute;
}
