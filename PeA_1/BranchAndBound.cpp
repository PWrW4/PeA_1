#include "pch.h"
#include "BranchAndBound.h"
#include <ostream>
#include <iostream>


bool BranchAndBound::areAllCitiesVisited()
{
	for (int i = 0; i < G->MatrixSize; i++)
	{
		if (!visitedCities[i])
			return false;
	}
	return true;
}

void BranchAndBound::Resolve(int v)
{
//	if (iteration == 0)
//	{
//		visitedCities[v] = true;
//		tmpRoute[v] = 0;
//	}
//	iteration++;
//	std::cout << iteration << std::endl;
//	if (!areAllCitiesVisited())
//	{
//		visitedCities[v] = true;//można to umieścić w tworzeniu funkcji, chociaż wierzchołek początkowy można wybrać losowo
//
//		for (int c = 0; c < G->MatrixSize; c++)//sprawdzam czy dane miasto nie było już odwiedzone
//		{
//			if (!visitedCities[c] && G->CityMatrix[v][c] > 0 && c != v && tmpCost < bestCost && tmpCost >= lowerLimit)
//			{
//				tmpCost += G->CityMatrix[v][c];
//				visitedCities[c] = true;
//				tmpRoute[whichCity++] = c;
//				//Console.WriteLine("v: " + v + ", c: " + c + ", koszt: " + cityMatrix[v, c] + ", aktualny koszt: " + tmpCost);
//				Resolve(c);
//
//				tmpCost -= G->CityMatrix[v][c];//po odwiedzeniu miasta
//				visitedCities[c] = false;
//				whichCity--;
//			}
//		}
//	}
//	else
//	{
//		tmpCost += G->GetTravelCost(tmpRoute[G->MatrixSize - 1], tmpRoute[0]);
//
//		if (tmpCost < bestCost) //zapisanie najlepszej drogi i jej wartości
//		{
//			bestCost = tmpCost;
//
//			for (int i = 0; i < G->MatrixSize; i++)
//				bestRoute[i] = tmpRoute[i];
//		}
//
//		tmpCost -= G->GetTravelCost(tmpRoute[G->MatrixSize - 1], tmpRoute[0]);
//	}
}

void BranchAndBound::ShowRoute()
{
	std::cout << "Najkrótszy cykl Hamiltonowski o koszcie(B&B): " << bestCost << std::endl;
	for (int i = 0; i < G->MatrixSize; i++)
	{
		if (i < G->MatrixSize - 1)
			std::cout << bestRoute[i] << " -> ";
		else
			std::cout << bestRoute[i] << " -> " << bestRoute[0] << std::endl;
	}
}

BranchAndBound::BranchAndBound(Graph * _G)
{
//	G = _G;
//	tmpRoute = new int[G->MatrixSize];
//	visitedCities = new bool[G->MatrixSize];
//	bestRoute = new int[G->MatrixSize];
//
//	bestCost = INT32_MAX;
//	upperLimit = INT32_MAX;
//	startTop = 0;
//	tmpCost = 0;
//	whichCity = 1;
//	iteration = 0;
//	lowerLimit = 0;
//
//	for (int i = 0; i < G->MatrixSize; ++i)
//	{
//		tmpRoute[i] = -1;
//		visitedCities[i] = false;
//		bestRoute[i] = -1;
//	}
//
//	for (int i = 0; i < G->MatrixSize; i++)//szukam minimalnej drogi wychodzącej z każdego wierzchołka 
//	{
//		int min = G->GetTravelCost(i, 0);
//		for (int j = 0; j < G->MatrixSize; j++)
//		{
//			if (G->GetTravelCost(i, j) < min)
//				min = G->GetTravelCost(i, j);
//		}
//		lowerLimit += min;
//	}
}


BranchAndBound::~BranchAndBound()
{
	delete[] visitedCities;
	delete[] bestRoute;
	delete[] tmpRoute;
}
