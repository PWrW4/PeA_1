#pragma once
#include <vector>

class CityWithLeftCities
{
public:

	int City;
	std::vector<int> CitiesLeft;

	bool operator<(const CityWithLeftCities& other) const;

	CityWithLeftCities(int city, std::vector<int> citiesLeft);
};

