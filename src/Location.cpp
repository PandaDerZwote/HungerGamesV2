#include "Location.hpp"

Location::Location()
{
	this->name = "NULL";
	this->id = 0;
}

Location::Location(string p_name, int p_id)
{
	this->name = p_name;
	this->id = p_id;
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

void Location::setId(int p_id)
{
	this->id = p_id;
}

int Location::getId()
{
	return this->id;
}
