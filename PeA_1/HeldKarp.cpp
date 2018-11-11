#include "pch.h"
#include "HeldKarp.h"
#include <map>
#include <vector>
#include <ostream>
#include <iostream>
#include "Subset.h"
#include "WeightAndPrevious.h"
#include "CityWithLeftCities.h"

#define startCity 0

bool HeldKarp::ifVectorContain(std::vector<int> vect, int value)
{
	for (size_t i = 0; i < vect.size(); i++)
		if (vect[i] == value)
			return true;
	return false;
}

std::vector<int> HeldKarp::getVectorWithoutElement(std::vector<int> vect, int value)
{
	std::vector<int> newVect(vect);
	for (size_t i = 0; i < newVect.size(); i++) {
		if (newVect[i] == value) {
			newVect.erase(newVect.begin() + i);
			return newVect;
		}
	}
	return {};
}

void HeldKarp::Resolve()
{

	std::map<CityWithLeftCities, WeightAndPrevious> mapOfReadyNodes;


	//from 1 becasue 0 is our start city
	for (int i = 1; i < G->GetMatrixSize(); i++) {

		std::vector<int> temp;
		mapOfReadyNodes[CityWithLeftCities(i, temp)] = WeightAndPrevious(G->GetTravelCost(i,startCity), startCity);
	}

	Subset::setLength(G->GetMatrixSize()); // set length - set size of the set from we will make subsets

	for (int subsetLength = 1; subsetLength < G->GetMatrixSize() - 1; subsetLength++) {
		Subset::resetVectorOfSubsets();
		std::vector<std::vector<int>> temp = Subset::getVectorOfSubsets(subsetLength); // make vector of all subsets of size subsetLength

		for (size_t m = 0; m < temp.size(); m++) { //g(?,|{3}|{4}|) = c23 + g(3, ∅ ) = c23 + c31 = 6 + 15 = 21

			if (!ifVectorContain(temp[m], startCity)) {
				for (size_t j = 0; j < G->GetMatrixSize(); j++) { //g(|2|4|,{3}) = c23 + g(3, ∅ ) = c23 + c31 = 6 + 15 = 21

					if (!ifVectorContain(temp[m], j) && j != startCity) {

						int tempPath;
						mapOfReadyNodes[CityWithLeftCities(j, temp[m])] = WeightAndPrevious(std::numeric_limits<int>::max(), -1);

						for (size_t k = 0; k < temp[m].size(); k++) {

							tempPath = G->GetTravelCost(j,temp[m][k]) + mapOfReadyNodes[CityWithLeftCities(temp[m][k], getVectorWithoutElement(temp[m], temp[m][k]))].Weight;
//							 std::cout << "\n" << j << " " << temp[m][k] << " " << G->GetTravelCost(j,temp[m][k]) << " " << mapOfReadyNodes[CityWithLeftCities(temp[m][k], getVectorWithoutElement(temp[m], temp[m][k]))].Weight << " " << tempPath << "\n";

							if (tempPath < mapOfReadyNodes[CityWithLeftCities(j, temp[m])].Weight) {
								mapOfReadyNodes[CityWithLeftCities(j, temp[m])].Weight = tempPath;
								mapOfReadyNodes[CityWithLeftCities(j, temp[m])].PreviousCity = temp[m][k];
							}
						}
					}
				}
			}
		}
	}

	int res = std::numeric_limits<int>::max();
	int prev = -1;

	int tempRes;

	std::vector<int> vectorWithoutStartCity;

	//make vector of all cities without start one
	for (size_t i = 0; i < G->GetMatrixSize(); i++)
		if (i != startCity)
			vectorWithoutStartCity.push_back(i);

	//last step of Held Karp
	for (size_t i = 0; i < vectorWithoutStartCity.size(); i++) {

		tempRes = G->GetTravelCost(startCity,vectorWithoutStartCity[i]) + mapOfReadyNodes[CityWithLeftCities(vectorWithoutStartCity[i], getVectorWithoutElement(vectorWithoutStartCity, vectorWithoutStartCity[i]))].Weight;

		if (tempRes < res) {
			res = tempRes;
			prev = vectorWithoutStartCity[i];
		}
	}

	std::cout << res << "path: " << startCity << " - ";

	//	result.pathWeight = res;

	while (!vectorWithoutStartCity.empty()) {

//		result.shortestPath.push_back(prev);
		std::cout << prev << " - ";
		vectorWithoutStartCity = getVectorWithoutElement(vectorWithoutStartCity, prev);
		prev = mapOfReadyNodes[CityWithLeftCities(prev, vectorWithoutStartCity)].PreviousCity;


	}

}

void HeldKarp::ShowRoute()
{
	std::cout << "Najkrótszy cykl Hamiltonowski o koszcie(BF): " << bestCost << std::endl;
	for (int i = 0; i < G->GetMatrixSize(); i++)
	{
		if (i < G->GetMatrixSize() - 1)
			std::cout << bestRoute[i] << " -> ";
		else
			std::cout << bestRoute[i] << " -> " << bestRoute[0] << std::endl;
	}
}

HeldKarp::HeldKarp(Graph * _G)
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


HeldKarp::~HeldKarp()
{
	delete[] visitedCities;
	delete[] bestRoute;
	delete[] tmpRoute;
}
