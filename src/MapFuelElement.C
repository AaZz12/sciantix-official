#include "MapFuelElement.h"

std::map<std::string, int> fe;

void MapFuelElement()
{
	for (std::vector<FuelElement>::size_type i = 0; i != fuelelement.size(); ++i)
		fe[fuelelement[i].getName()] = i;
}
