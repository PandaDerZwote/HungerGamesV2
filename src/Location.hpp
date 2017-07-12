#ifndef LOCATION_HPP_
#define LOCATION_HPP_

#include <string>
#include <vector>

using namespace std;

class Location
{
private:
	int id;
	string name;
	vector<Location> neighbours;
public:
	Location();
	Location(string p_name);
	string getName();
	void addNeighbour(Location pNeighbour);
	vector<Location> getNeighbours();
	void setId(int p_id);
	int getId();
};

#endif /* LOCATION_HPP_ */
