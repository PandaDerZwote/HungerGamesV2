#include "init.hpp"

void init(vector<Location> *world)
{
	random_init();
	vector<Location> new_world = location_init();
	world = &new_world;
}

void random_init()
{
	srand(time(0));
}

vector<Location> location_init()
{
	vector<Location> world;
	// Init
	Location cornucopia("Cornucopia");
	Location mountain("Mountain");
	Location lake("Lake");
	Location meadow("Meadow");
	Location forest_east("Eastern Forest");
	Location forest_west("Western Forest");
	Location shore("Shore");
	// Set nodes
	cornucopia.addNeighbour(mountain);
	cornucopia.addNeighbour(lake);
	cornucopia.addNeighbour(meadow);
	cornucopia.addNeighbour(forest_east);
	cornucopia.addNeighbour(shore);
	mountain.addNeighbour(cornucopia);
	mountain.addNeighbour(lake);
	lake.addNeighbour(cornucopia);
	lake.addNeighbour(mountain);
	lake.addNeighbour(forest_east);
	lake.addNeighbour(forest_west);
	meadow.addNeighbour(cornucopia);
	meadow.addNeighbour(forest_east);
	meadow.addNeighbour(shore);
	forest_east.addNeighbour(cornucopia);
	forest_east.addNeighbour(lake);
	forest_east.addNeighbour(meadow);
	forest_east.addNeighbour(forest_west);
	forest_east.addNeighbour(shore);
	forest_west.addNeighbour(lake);
	forest_west.addNeighbour(forest_east);
	shore.addNeighbour(cornucopia);
	shore.addNeighbour(meadow);
	shore.addNeighbour(forest_east);
	// Add to vector
	world.push_back(cornucopia);
	world.push_back(mountain);
	world.push_back(lake);
	world.push_back(meadow);
	world.push_back(forest_east);
	world.push_back(forest_west);
	world.push_back(shore);
	// Return
	return world;
}
