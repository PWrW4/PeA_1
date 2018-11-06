#include "pch.h"
#include "BruteForce.h"
#include <cstdint>
#include <iostream>


bool BruteForce::areAllCitiesVisited()
{
	for (int i = 0; i < G->GetMatrixSize(); i++)
	{
		if (!visitedCities[i])
			return false;
	}
	return true;
}

bool BruteForce::Resolve(int v)
{
	if (iteration == 0)
	{
		visitedCities[v] = true;
		tmpRoute[v] = 0;
	}
	iteration++;
	if (!areAllCitiesVisited())
	{
		visitedCities[v] = true;//mo¿na to umieœciæ w tworzeniu funkcji, chocia¿ wierzcho³ek pocz¹tkowy mo¿na wybraæ losowo

		for (int c = 0; c < G->GetMatrixSize(); c++)//sprawdzam czy dane miasto nie by³o ju¿ odwiedzone
		{
			if (!visitedCities[c] && G->GetTravelCost(v, c) > 0 && c != v)
			{
				tmpCost += G->GetTravelCost(v, c);
				visitedCities[c] = true;
				tmpRoute[whichCity++] = c;
				//Console.WriteLine("v: " + v + ", c: " + c + ", koszt: " + cityMatrix[v, c] + ", aktualny koszt: " + tmpCost);
				Resolve(c);

				tmpCost -= G->GetTravelCost(v, c);//po odwiedzeniu miasta
				visitedCities[c] = false;
				whichCity--;
			}
		}
	}
	else
	{
		tmpCost += G->GetTravelCost(tmpRoute[G->GetMatrixSize() - 1], tmpRoute[0]);

		if (tmpCost < bestCost) //zapisanie najlepszej drogi i jej wartoœci
		{
			bestCost = tmpCost;

			for (int i = 0; i < G->GetMatrixSize(); i++)
				bestRoute[i] = tmpRoute[i];
		}

		tmpCost -= G->GetTravelCost(tmpRoute[G->GetMatrixSize() - 1], tmpRoute[0]);
	}
	return true;
}

void BruteForce::ShowRoute()
{
	std::cout <<"Najkrótszy cykl Hamiltonowski o koszcie: "<< bestCost<<std::endl;
	for (int i = 0; i < G->GetMatrixSize(); i++)
	{
		if (i < G->GetMatrixSize() - 1)
			std::cout << bestRoute[i] << " -> ";
		else
			std::cout<< bestRoute[i] <<" -> " << bestRoute[0] << std::endl;
	}
}

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
