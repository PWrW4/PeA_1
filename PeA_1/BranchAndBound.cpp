#include "pch.h"
#include "BranchAndBound.h"
#include <ostream>
#include <iostream>
#include <algorithm>

#define startVertex 0;

int BranchAndBound::reduceMatrix(std::vector<std::vector<int>>* matrix_to_put, BBElement * from)
{
	for (int i = 0; i < matrix_to_put->size(); ++i)
	{
		(*matrix_to_put)[i][i] = INT32_MAX;
	}

	int minimalX = 0;
	int minimalY = 0;

	for (int i = 0; i < matrix_to_put->size(); ++i)
	{
		int minimal=INT32_MAX;
		for (int j = 0; j < matrix_to_put->size(); ++j)
		{
			minimal = std::min(minimal, (*matrix_to_put)[i][j]);
		
		}
		if (minimal != 0 || minimal!=INT32_MAX)
		{
			for (int j = 0; j < matrix_to_put->size(); ++j)
			{
				if ((*matrix_to_put)[i][j] != INT32_MAX)
				{
					(*matrix_to_put)[i][j] -= minimal;
				}
			}
		}
		if (minimal!=INT32_MAX)
		{
			minimalX += minimal;
		}
	}

	for (int i = 0; i < matrix_to_put->size(); ++i)
	{
		int minimal= INT32_MAX;
		for (int j = 0; j < matrix_to_put->size(); ++j)
		{
			minimal = std::min(minimal, (*matrix_to_put)[j][i]);
		}
		if (minimal != 0 || minimal != INT32_MAX)
		{
			for (int j = 0; j < matrix_to_put->size(); ++j)
			{
				if ((*matrix_to_put)[j][i] != INT32_MAX)
				{
					(*matrix_to_put)[j][i] -= minimal;
				}

			}
		}
		if (minimal != INT32_MAX)
		{
			minimalY += minimal;
		}
	}

	return minimalX + minimalY;
}

void BranchAndBound::travel(std::vector<std::vector<int>>* matrix_to_put, int vertex, int vertex1)
{
	(*matrix_to_put)[vertex1][vertex] = INT32_MAX;
	for (int i = 0; i < matrix_to_put->size(); ++i)
	{
		(*matrix_to_put)[vertex][i] = INT32_MAX;
		(*matrix_to_put)[i][vertex1] = INT32_MAX;
	}
}

BBElement * BranchAndBound::createBBElement(int vertex, BBElement * from)
{
	int loweBound=-1;
	std::vector<std::vector<int>> * matrixToPut = new std::vector<std::vector<int>>;
	if (from==nullptr)
	{
		matrixToPut->resize(G->MatrixSize, std::vector<int>(G->MatrixSize));
		*matrixToPut = G->CityMatrix;
		loweBound = reduceMatrix(matrixToPut, from);
	}
	else
	{
		matrixToPut->resize(G->MatrixSize, std::vector<int>(G->MatrixSize));
		*matrixToPut = *from->matrixCost;
		travel(matrixToPut,from->vertex,vertex);
		loweBound = reduceMatrix(matrixToPut,from)+(*nodeArray[0].matrixCost)[from->vertex][vertex]+from->lowerBound;		
	}

	return new BBElement(vertex,from,loweBound, matrixToPut);
}

void BranchAndBound::Resolve()
{
	nodeArray.push_back(*createBBElement(0, nullptr));
	nodeArray.push_back(*createBBElement(1, &nodeArray[0]));
	nodeArray.push_back(*createBBElement(2, &nodeArray[0]));
	nodeArray.push_back(*createBBElement(3, &nodeArray[0]));
	nodeArray.push_back(*createBBElement(4, &nodeArray[0]));
}

void BranchAndBound::ShowRoute()
{
//	std::cout << "Najkrótszy cykl Hamiltonowski o koszcie(B&B): " << bestCost << std::endl;
//	for (int i = 0; i < G->MatrixSize; i++)
//	{
//		if (i < G->MatrixSize - 1)
//			std::cout << bestRoute[i] << " -> ";
//		else
//			std::cout << bestRoute[i] << " -> " << bestRoute[0] << std::endl;
//	}
}

BranchAndBound::BranchAndBound(Graph * _G)
{
	G = _G;
}


BranchAndBound::~BranchAndBound()
{
}
