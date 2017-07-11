#include "Contest.hpp"

void setup(vector<Contestant> *cast)
{
	// init weapons
	Weapon axe("Axe", 2, 2);
	Weapon bow("Bow", 1, 3);
	Weapon c_bow("Crossbow", 3, 2);
	Weapon brick ("Brick", 1, 1);
	Weapon machete ("Machete", 2, 2);
	// roll weapons
	cout << "The games have started!" << endl;
	int members = cast->size();
	for (int i = 0; i < members; i++)
	{
		int random = setRandom(5);
		if (random == 1)
		{
			cout << cast->at(i).getName() << " didn't acquire any weapons." << endl;
		}
		else
		{
			random = setRandom(5);
			switch (random)
			{
			case 1:
				cast->at(i).setWeapon(axe);
				cout << cast->at(i).getName() << " acquired an axe!" << endl;
				break;
			case 2:
				cast->at(i).setWeapon(bow);
				cout << cast->at(i).getName() << " acquired a bow!" << endl;
				break;
			case 3:
				cast->at(i).setWeapon(c_bow);
				cout << cast->at(i).getName() << " acquired a crossbow!" << endl;
				break;
			case 4:
				cast->at(i).setWeapon(brick);
				cout << cast->at(i).getName() << " acquired a... brick?" << endl;
				break;
			case 5:
				cast->at(i).setWeapon(machete);
				cout << cast->at(i).getName() << " acquired a machete!" << endl;
				break;
			}
		}
	}
	cout << "The setup phase has ended!" << endl;
}

void locationSwap(Contestant *actor, vector<Location> world)
{
	Location current_location = actor->getLocation();
	int neighbour_locations = current_location.getNeighbours().size();
	int random = setRandom(neighbour_locations);
	if (random != neighbour_locations)
	{
		string new_loc = actor->getLocation().getNeighbours().at(random - 1).getName();
		for (unsigned int i = 0; i < world.size(); i++)
		{
			if (new_loc == world[i].getName())
			{
				actor->setLocation(world[i]);
			}
		}
		cout << actor->getName() << " changed location to " << actor->getLocation().getName() << "." << endl;
	}
	else
	{
		cout << actor->getName() << " remains at " << actor->getLocation().getName() << "." << endl;
	}

}

void locatioEvent(Contestant *actor)
{
	int random = setRandom(100);
	switch (actor->getLocation().getName())
	{
	case "Cornucopia":
		break;
	case "Mountain":
			break;
	case "Meadow":
			break;
	case "Lake":
			break;
	case "Eastern Forest":
			break;
	case "Western Forest":
			break;
	case "Shore":
			break;
	}
}
