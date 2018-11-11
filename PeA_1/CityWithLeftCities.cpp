#include "pch.h"
#include "CityWithLeftCities.h"

bool CityWithLeftCities::operator<(const CityWithLeftCities& other) const
{
	if (City < other.City) return true;
	if (City > other.City) return false;

	if (CitiesLeft < other.CitiesLeft) return true;
	if (CitiesLeft > other.CitiesLeft) return false;

	return false;
}

CityWithLeftCities::CityWithLeftCities(int city, std::vector<int> citiesLeft): City(city), CitiesLeft(citiesLeft)
{
	;
}
