#include "Location.hpp"

Location::Location()
{
	this-> name = "NULL";
}

Location::Location(string p_name)
{
	this->name = p_name;
}

void Location::addNeighbour(Location pNeighbour)
{
	neighbours.push_back(pNeighbour);
}

vector<Location> Location::getNeighbours()
{
	return neighbours;
}

string Location::getName()
{
	return name;
}
