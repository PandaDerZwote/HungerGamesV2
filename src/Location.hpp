/*
 * Location.hpp
 *
 *  Created on: 10.07.2017
 *      Author: Jan
 */

#ifndef LOCATION_HPP_
#define LOCATION_HPP_

#include <string>
#include <vector>

using namespace std;

class Location
{
private:
	string name;
	vector<Location> neighbours;
public:
	Location(string name);
	void addNeighbour(Location pNeighbour);
	vector<Location> getNeighbours();
};

void init_Locate();

#endif /* LOCATION_HPP_ */
