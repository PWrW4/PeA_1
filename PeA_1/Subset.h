#pragma once
#include <vector>

class Subset
{
public:
	static int Length;
	static std::vector<std::vector<int>> vectorOfSubsets;

	static void output(int string[], int position);
	static void generate(int string[], int position, int positions);
	static void setLength(int length);
	static std::vector<std::vector<int>> getVectorOfSubsets(int subsetSize);

	static void resetVectorOfSubsets();
};

