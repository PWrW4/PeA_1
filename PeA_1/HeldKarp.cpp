#include "pch.h"
#include "HeldKarp.h"
#include <map>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

#define startCity 0

void HeldKarp::Resolve()
{
	std::vector<std::vector<int> > best(1 << (G->MatrixSize - 1), std::vector<int>(G->MatrixSize, INT_MAX));

	// use DP to solve all states
	// note that whenever we solve a particular state, 
	// the smaller states we need have already been solved

	for (int visited = 1; visited < (1 << (G->MatrixSize - 1)); ++visited) {
		for (int last = 0; last < (G->MatrixSize - 1); ++last) {

			// last visited vertex must be one of the visited vertices
			if (!(visited & 1 << last)) continue;

			// try all possibilities for the previous vertex,
			// pick the best among them
			if (visited == 1 << last) {
				// previous vertex must have been N-1
				best[visited][last] = G->CityMatrix[G->MatrixSize - 1][last];
			}
			else {
				// previous vertex was one of the other ones in "visited"
				int prev_visited = visited ^ 1 << last;
				for (int prev = 0; prev < G->MatrixSize - 1; ++prev) {
					if (!(prev_visited & 1 << prev)) continue;
					best[visited][last] = std::min(
						best[visited][last],
						G->CityMatrix[last][prev] + best[prev_visited][prev]
					);
				}
			}
		}
	}

	// use the precomputed path lengths to choose the cheapest cycle
	int answer = INT_MAX;
	for (int last = 0; last < G->MatrixSize - 1; ++last) {
		answer = std::min(answer,(G->CityMatrix[last][G->MatrixSize - 1] + best[(1 << (G->MatrixSize - 1)) - 1][last]));
	}
	std::cout << answer;
}

void HeldKarp::ShowRoute()
{
	std::cout << "Najkrótszy cykl Hamiltonowski o koszcie(BF): " << bestCost << std::endl;
	for (int i = 0; i < G->MatrixSize; i++)
	{
		if (i < G->MatrixSize - 1)
			std::cout << bestRoute[i] << " -> ";
		else
			std::cout << bestRoute[i] << " -> " << bestRoute[0] << std::endl;
	}
}

HeldKarp::HeldKarp(Graph * _G)
{
	G = _G;

	bestRoute = new int[G->MatrixSize];
	bestCost = INT32_MAX;

	for (int i = 0; i < G->MatrixSize; ++i)
	{
		bestRoute[i] = -1;
	}
}


HeldKarp::~HeldKarp()
{
	delete[] visitedCities;
	delete[] bestRoute;
	delete[] tmpRoute;
}
