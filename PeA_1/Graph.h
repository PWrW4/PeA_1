#pragma once
#include <string>
#include <vector>

class Graph
{
private:
	std::vector<std::vector<int>> CityMatrix;
	int MatrixSize = 0;
public:
	Graph();
	~Graph();
	 
	int GetMatrixSize();
	int GetTravelCost(int from, int to);

	void LoadGraph(std::string fileName);
	void DrawMatrix();
	void DrawMatrixSize();
};
