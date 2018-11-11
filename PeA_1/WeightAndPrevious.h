#pragma once
class WeightAndPrevious
{
public:
	int Weight;
	int PreviousCity;

	WeightAndPrevious() = default;

	WeightAndPrevious(int weight, int previousCity);
};

