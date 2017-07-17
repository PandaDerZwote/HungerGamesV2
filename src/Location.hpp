#ifndef LOCATION_HPP_
#define LOCATION_HPP_

#include <string>
#include <vector>

class Location {
private:
	int id;
	std::string name;
	std::vector<Location> neighbours;
public:
	// Constructors
	Location();
	Location(std::string, int);
	// Name
	void setName(std::string);
	std::string getName();
	// ID
	void setId(int);
	int getId();
	// Neighbours
	void addNeighbour(Location);
	std::vector<Location> getNeighbours();
};

class LocationCornucopia {
public:
	virtual ~LocationCornucopia();
};
#endif /* LOCATION_HPP_ */

