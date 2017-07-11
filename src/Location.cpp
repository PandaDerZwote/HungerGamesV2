#include "Location.hpp"

Location::Location(string pName)
{
	this->name = pName;
}

void Location::addNeighbour(Location pNeighbour)
{
	neighbours.push_back(pNeighbour);
}

vector<Location> Location::getNeighbours()
{
	return neighbours;
}
