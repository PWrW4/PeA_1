﻿#include "pch.h"
#include "HeldKarp.h"
#include <map>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>

#define startCity 0

void HeldKarp::Resolve()
{

	int test = (1 << (G->MatrixSize - 1));

	for (int visited = 1; visited < (1 << (G->MatrixSize - 1)); ++visited) {
		for (int last = 0; last < (G->MatrixSize - 1); ++last) {

			// last visited vertex must be one of the visited vertices
			if (!(visited & 1 << last)) continue;

			// try all possibilities for the previous vertex,
			// pick the best among them
			if (visited == 1 << last) {
				// previous vertex must have been N-1
				subsetVector[visited][last].cost = G->CityMatrix[G->MatrixSize - 1][last];
				subsetVector[visited][last].from = (G->MatrixSize - 1);
				subsetVector[visited][last].vertex = last;
			}
			else {
				// previous vertex was one of the other ones in "visited"
				int prev_visited = visited ^ 1 << last;
				for (int prev = 0; prev < G->MatrixSize - 1; ++prev) {
					if (!(prev_visited & 1 << prev)) continue;
					subsetVector[visited][last].cost = std::min(
						subsetVector[visited][last].cost,
						G->CityMatrix[prev][last] + subsetVector[prev_visited][prev].cost
					);
					if (subsetVector[visited][last].cost > (G->CityMatrix[prev][last] + subsetVector[prev_visited][prev].cost))
					{
						subsetVector[visited][last].from = visited;
						subsetVector[visited][last].vertex = last;
					}
					else
					{
						subsetVector[visited][last].from = prev_visited;
						subsetVector[visited][last].vertex = last;
					}
				}
			}
		}
	}

	// chose cycle
	for (int last = 0; last < G->MatrixSize - 1; ++last) {
		bestCost = std::min(bestCost,(G->CityMatrix[last][G->MatrixSize - 1] + subsetVector[(1 << (G->MatrixSize - 1)) - 1][last].cost));
//		std::cout << last <<"   "<< G->CityMatrix[last][G->MatrixSize - 1] + subsetVector[(1 << (G->MatrixSize - 1)) - 1][last].cost<<std::endl;
	}
}

void HeldKarp::ShowRoute()
{
	for (int last = 0; last < G->MatrixSize - 1; ++last) {
		subsetVector[(1 << (G->MatrixSize - 1)) - 1][last].cost = (G->CityMatrix[last][G->MatrixSize - 1] + subsetVector[(1 << (G->MatrixSize - 1)) - 1][last].cost);
	}

	int idOfSubset = (1 << (G->MatrixSize - 1))-1;
	std::vector<int> route;
	route.push_back(G->MatrixSize-1);
	while (route.size() != G->MatrixSize)
	{
		
		Subset tmp_min;
		for (int i = 0; i < G->MatrixSize; ++i)
		{
			if (tmp_min.cost > subsetVector[idOfSubset][i].cost)
			{
				tmp_min.cost = subsetVector[idOfSubset][i].cost;
				tmp_min.from = subsetVector[idOfSubset][i].from;
				tmp_min.vertex = subsetVector[idOfSubset][i].vertex;
			}
		}
		route.push_back(tmp_min.vertex);
		idOfSubset = tmp_min.from;
	}


	std::cout << "Najkrótszy cykl Hamiltonowski o koszcie(BF): " << bestCost << std::endl;
	for (int i = G->MatrixSize-1; i >=0; i--)
	{
		if (i > 0)
			std::cout << route[i] << " -> ";
		else
			std::cout << route[i] << " -> " << route[G->MatrixSize - 1] << std::endl;
	}
}

HeldKarp::HeldKarp(Graph * _G)
{
	G = _G;
	subsetVector.resize(1 << (G->MatrixSize - 1), std::vector<Subset>(G->MatrixSize));
	bestCost = INT32_MAX;
}


HeldKarp::~HeldKarp()
{
}
