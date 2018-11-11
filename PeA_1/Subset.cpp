#include "pch.h"
#include "Subset.h"


int Subset::Length = 0;
std::vector<std::vector<int>> Subset::vectorOfSubsets;

void Subset::output(int string[], int position)
{

	bool * temp_string = new bool[Length];
	int index = 0;
	int i;
	for (i = 0; i < Length; i++)
	{
		if ((index < position) && (string[index] == i))
		{
			temp_string[i] = 1;
			index++;
		}
		else
			temp_string[i] = 0;
	}


	std::vector<int> temp;

	for (i = 0; i < Length; i++)
		if (temp_string[i] == true)
			temp.push_back(i);


	delete[] temp_string;

	vectorOfSubsets.push_back(temp);

}

void Subset::generate(int string[], int position, int positions)
{

	if (position < positions)
	{
		if (position == 0)
		{
			for (int i = 0; i < Subset::Length; i++)
			{
				string[position] = i;
				generate(string, position + 1, positions);
			}
		}
		else
		{
			for (int i = string[position - 1] + 1; i < Subset::Length; i++)
			{
				string[position] = i;
				generate(string, position + 1, positions);
			}
		}
	}
	else
		output(string, positions);
}

void Subset::setLength(int length)
{
	Length = length;
}

std::vector<std::vector<int>> Subset::getVectorOfSubsets(int subsetSize)
{
	int * string = new int[Length];
	generate(string, 0, subsetSize);
	delete[] string;
	return vectorOfSubsets;
}

void Subset::resetVectorOfSubsets()
{
	vectorOfSubsets.clear();
}
