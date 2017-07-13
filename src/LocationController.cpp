#include "LocationController.hpp"
#include <iostream>

LocationController::LocationController()
{
	nullLocation = Location();
	Location corn("cornucopia", 1);
	Location mount("mountains", 2);
	Location lake("lake", 3);
	Location mead("meadow", 4);
	Location east_for("eastern forest", 5);
	Location west_for("western forest", 6);
	Location shore("shore", 7);
	setNeighbours(&corn, &mount);
	setNeighbours(&corn, &lake);
	setNeighbours(&corn, &mead);
	setNeighbours(&corn, &east_for);
	setNeighbours(&corn, &shore);
	setNeighbours(&mount, &lake);
	setNeighbours(&lake, &east_for);
	setNeighbours(&lake, &west_for);
	setNeighbours(&mead, &shore);
	setNeighbours(&mead, &east_for);
	setNeighbours(&east_for, &west_for);
 	setNeighbours(&east_for, &shore);
 	locations = vector<Location>{corn, mount, lake, mead, east_for, west_for, shore};
}

void LocationController::setNeighbours(Location *node_1, Location *node_2)
{
	node_1->addNeighbour(*node_2);
	node_2->addNeighbour(*node_1);
}

Location LocationController::getRandomNeighbour(Location t_self)
{
	unsigned int random = setRandom(t_self.getNeighbours().size()) - 1;
	int id = t_self.getNeighbours().at(random).getId();
	for (unsigned int i = 0; i < locations.size(); i++)
	{
		if (locations[i].getId() == id)
		{
			return locations[i];
		}
	}
	return nullLocation;
}

Location LocationController::getRandomNeighbourOrSelf(Location t_self)
{
	unsigned int random = setRandom(t_self.getNeighbours().size());
	if (random == t_self.getNeighbours().size())
	{
		return t_self;
	}
	int id = t_self.getNeighbours().at(random).getId();
	for (unsigned int i = 0; i < locations.size(); i++)
	{
		if (locations[i].getId() == id)
		{
			return locations[i];
		}
	}
	return nullLocation;
}
