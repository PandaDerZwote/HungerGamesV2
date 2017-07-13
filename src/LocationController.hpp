#ifndef LOCATIONCONTROLLER_HPP_
#define LOCATIONCONTROLLER_HPP_

#include "Location.hpp"
#include <vector>
#include "Random.hpp"

using namespace std;

class LocationController
{
public:
	Location nullLocation;
	vector<Location> locations;
	LocationController();
	void setNeighbours(Location*, Location*);
	Location getRandomNeighbour(Location);
	Location getRandomNeighbourOrSelf(Location);
};

#endif /* LOCATIONCONTROLLER_HPP_ */
