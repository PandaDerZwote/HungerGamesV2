#include "Contest.hpp"

void setup(vector<Contestant> *cast)
{
	// init weapons
	Weapon axe("axe", 2, 2);
	Weapon bow("bow", 1, 3);
	Weapon c_bow("crossbow", 3, 2);
	Weapon brick ("rock", 1, 1);
	Weapon machete ("machete", 2, 2);
	Weapon spear ("spear", 2, 1);
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
			random = setRandom(6);
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
				cout << cast->at(i).getName() << " acquired a... rock?" << endl;
				break;
			case 5:
				cast->at(i).setWeapon(machete);
				cout << cast->at(i).getName() << " acquired a machete!" << endl;
				break;
			case 6:
				cast->at(i).setWeapon(spear);
				cout << cast->at(i).getName() << " acquired a spear!" << endl;
				break;
			}
		}
	}
	cout << "The setup phase has ended!" << endl << endl;
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
		//cout << actor->getName() << " changed location to the " << actor->getLocation().getName() << "." << endl;
	}
	else
	{
		//cout << actor->getName() << " remains at the " << actor->getLocation().getName() << "." << endl;
	}

}

string locationEvent(Contestant *actor)
{
	// Declare variables
	string output;
	string pronoun, pronoun_cap, possesive_pronoun, possesive_pronoun_cap, object_pronoun, object_pronoun_cap;
	if (actor->getGender() == "m")
	{
		pronoun = "he";
		pronoun_cap = "He";
		possesive_pronoun = "his";
		possesive_pronoun_cap = "His";
		object_pronoun = "him";
		object_pronoun_cap = "Him";
	}
	else
	{
		pronoun = "she";
		pronoun_cap = "She";
		possesive_pronoun = "her";
		possesive_pronoun_cap = "Her";
		object_pronoun = "her";
		object_pronoun_cap = "Her";
	}
	int random = setRandom(100);
	// Declare null objects
	Location null_location("NULL");
	Weapon null_weapon("NULL", 0, 0);
	switch (actor->getLocation().getId())
	{
	case 1:
		/*
		 * Cornucopia EventTable:
		 * 5% Landmine death
		 * 35% Find Item
		 * 10% flavour
		 * 50% Nothing
		 */
		if (random > 5)
		{
			if (random > 40)
			{
				if(random > 90)
				{
					int flavour_corn = setRandom(3);
					switch (flavour_corn)
					{
					case 1:
						output.append(actor->getName() + " is casually looking around at the cornucopia.");
						actor->setActionPoints(0);
						break;
					case 2:
						output.append(actor->getName() + " is crying in despair.");
						actor->setActionPoints(0);
						break;
					case 3:
						output.append(actor->getName() + " is cursing everyone responsible for the Hunger Games.");
						actor->setActionPoints(0);
						break;
					}
				}
			}
			else
			{
				Weapon retrieved_weapon = acquireWeapon();
				if (retrieved_weapon.getName() != "NULL")
				{
					if (retrieved_weapon.getDamage() > actor->getWeapon().getDamage())
					{
						if (actor->getWeapon().getName() != "NULL")
						{
							output.append(actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + pronoun_cap + " decides to equip it, throwing away " + possesive_pronoun + " " + actor->getWeapon().getName() + ".");
							actor->setActionPoints(0);
							actor->setWeapon(retrieved_weapon);
						}
						else
						{
							output.append(actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + pronoun_cap + " decides to equip it.");
							actor->setActionPoints(0);
						}
					}
					else
					{
						output.append(actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + pronoun_cap + " decides to keep " + possesive_pronoun + " " + actor->getWeapon().getName() + ".");
						actor->setActionPoints(0);
					}
				}
				else
				{
					output.append(actor->getName() + " searches the cornucopia for supplies and finds nothing.");
					actor->setActionPoints(0);
				}
			}
		}
		else
		{

			int randomLandmine = setRandom(5);
			switch (randomLandmine)
			{
			case 1:
			case 2:
			case 3:
				output.append(actor->getName() + " stepped on a landmine!");
				actor->setActionPoints(0);
				break;
			case 4:
				output.append(actor->getName() + " stepped on a landmine and splatters!");
				actor->setActionPoints(0);
				break;
			case 5:
				output.append(actor->getName() + " stepped on a landmine and was annihilated!");
				actor->setActionPoints(0);
			}
			actor->setHealth(0);
			actor->setLocation(null_location);
		}
		break;
	case 2:
		/*
		 * Mountain EventTable:
		 * 5% Falling
		 * 5% Losing weapon
		 * 25% Equiping Rock, when no other/worse weapon equiped
		 * 10% Flavour
		 * 55% Nothing
		 */
		if (random > 5)
		{
			if (random > 30)
			{
				if (random > 35)
				{
					if (random > 90)
					{
						int flavour_mountain = setRandom(3);
						switch (flavour_mountain)
						{
						case 1:
							output.append(actor->getName() + " is climbing in the mountains");
							actor->setActionPoints(0);
							break;
						case 2:
							output.append(actor->getName() + " is hiking in the mountains");
							actor->setActionPoints(0);
							break;
						case 3:
							output.append(actor->getName() + " is sitting on top of the mountains, watching over the arena.");
							actor->setActionPoints(0);
							break;
						}
					}
				}
				else
				{
					if (actor->getWeapon().getName() != "NULL")
					{
						output.append(actor->getName() + " lost " + possesive_pronoun + " weapon while climbing the mountain!");
						actor->setActionPoints(0);
						actor->setWeapon(null_weapon);
					}
				}
			}
			else
			{
				Weapon stone("rock", 1, 1);
				if (actor->getWeapon().getDamage() < stone.getDamage())
				{
					if (actor->getWeapon().getName() != "NULL")
					{
						output.append(actor->getName() + " found a rock in the mountains " + pronoun + " drops " + possesive_pronoun + " " + actor->getWeapon().getName() + " for it.");
						actor->setWeapon(stone);
					}
					else
					{
						output.append(actor->getName() + " found a rock in the mountains and is now using it as a weapon.");
						actor->setActionPoints(0);
						actor->setWeapon(stone);
					}
				}
			}
		}
		else
		{
			int randomMountain = setRandom(5);
			switch (randomMountain)
			{
			case 1:
				output.append(actor->getName() + " falls of a cliff!");
				actor->setActionPoints(0);
				actor->setHealth(0);
				actor->setLocation(null_location);
				break;
			case 2:
				output.append(actor->getName() + " falls of a cliff instantly dying on impact!");
				actor->setActionPoints(0);
				actor->setHealth(0);
				actor->setLocation(null_location);
				break;
			case 3:
				output.append(actor->getName() + " falls of a cliff dying after hours of agony!");
				actor->setActionPoints(0);
				actor->setHealth(0);
				actor->setLocation(null_location);
				break;
			case 4:
				actor->setHealth(actor->getHealth() - 2);
				if (actor->checkVital())
				{
					output.append(actor->getName() + " falls of a cliff and is injured but survives!");
					actor->setActionPoints(0);
				}
				else
				{
					output.append(actor->getName() + " falls of a cliff and dies from the injuries!");
					actor->setActionPoints(0);
					actor->setLocation(null_location);
				}
				break;
			case 5:
				output.append(actor->getName() + " falls of a cliff but survives completetly unharmed!");
				actor->setActionPoints(0);
				break;
			}
		}
		break;
	case 3:
		/*
		 * Lake EventTable:
		 * 5% Drown
		 * 5% Lose weapon
		 * 10% Flavour
		 * 80% do nothing
		 */
		if (random > 5)
		{
			if (random > 10)
			{
				if (random > 90)
				{
					int flavour_lake = setRandom(3);
					switch (flavour_lake)
					{
					case 1:
						output.append(actor->getName() + " is fishing at the lake.");
						actor->setActionPoints(0);
						break;
					case 2:
						output.append(actor->getName() + " is bathing in the lake.");
						actor->setActionPoints(0);
						break;
					case 3:
						output.append(actor->getName() + " is sitting near the lake, pondering about the games.");
						actor->setActionPoints(0);
						break;
					}
				}
			}
			else
			{
				if (actor->getWeapon().getName() != "NULL")
				{
					output.append(actor->getName() + " lost " + possesive_pronoun + " weapon while swimming in the lake!");
					actor->setActionPoints(0);
					actor->setWeapon(null_weapon);
				}
			}
		}
		else
		{
			output.append(actor->getName() + " drowned in the lake!");
			actor->setActionPoints(0);
			actor->setHealth(0);
			actor->setLocation(null_location);
		}
		break;
	case 4:
		/*
		 * Meadow EventTable:
		 * 5% Getting bitten by a snake
		 * 5% Receiving medical supplies
		 * 10% flavour
		 * 80% nothing
		 */
		if (random > 5)
		{
			if (random > 10)
			{
				if (random > 90)
				{
					int flavour_meadow = setRandom(3);
					switch (flavour_meadow)
					{
					case 1:
						output.append(actor->getName() + " is aimlessly running around the meadows.");
						actor->setActionPoints(0);
						break;
					case 2:
						output.append(actor->getName() + " is hunting in the meadows.");
						actor->setActionPoints(0);
						break;
					case 3:
						output.append(actor->getName() + " has started a campfire.");
						actor->setActionPoints(0);
						break;
					}
				}
			}
			else
			{
				if (actor->getHealth() < 5)
				{
					if (actor->getHealth() + 2 >= 5)
					{
						actor->setHealth(5);
						output.append(actor->getName() + " receives medical aid from an unknown sponsor and fully recovered!");
						actor->setActionPoints(0);
					}
					else
					{
						actor->setHealth(actor->getHealth() + 2);
						output.append(actor->getName() + " receives medical aid from an unknown sponsor.");
						actor->setActionPoints(0);
					}
				}
			}
		}
		else
		{
			int snake_random = setRandom(5);
			switch (snake_random)
			{
			case 1:
			case 2:
			case 3:
				output.append(actor->getName() + " was bitten by a snake! The snake was venomous and " + pronoun + " died!");
				actor->setActionPoints(0);
				actor->setHealth(0);
				actor->setLocation(null_location);
				break;
			case 4:
				actor->setHealth(actor->getHealth() - 2);
				if (actor->checkVital())
				{
					output.append(actor->getName() + " was bitten by a snake! Venom flows through " + possesive_pronoun + " body, but " + pronoun + " survives!");
					actor->setActionPoints(0);
				}
				else
				{
					output.append(actor->getName() + " was bitten by a snake! Venom flows through " + possesive_pronoun + " body, killing " + object_pronoun + " slowly and painfully!");
					actor->setActionPoints(0);
				}
				break;
			case 5:
				output.append(actor->getName() + " was bitten by a snake! Nothing happened.");
				actor->setActionPoints(0);
				break;
			}
		}
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	}
	return output;
}

Weapon acquireWeapon()
{
	Weapon return_weapon("NULL", 0, 0);
	int random = setRandom(100);
	int weapon_seed = setRandom(5);
	if (random > 33)
	{
		if (random > 66)
		{
			if (random > 90)
			{
				switch (weapon_seed)
				{
				case 1:
					return_weapon = Weapon("trident", 3, 3);
					break;
				case 2:
					return_weapon = Weapon("scythe", 4, 2);
					break;
				case 3:
					return_weapon = Weapon("steel mace", 2, 4);
					break;
				case 4:
					return_weapon = Weapon("grenade", 6, 0);
					break;
				case 5:
					return_weapon = Weapon("flamethrower", 5, 2);
					break;
				}
			}
			else
			{
				switch (weapon_seed)
				{
				case 1:
					return_weapon = Weapon("axe", 2, 2);
					break;
				case 2:
					return_weapon = Weapon("machete", 2, 2);
					break;
				case 3:
					return_weapon = Weapon("bow", 3, 2);
					break;
				case 4:
					return_weapon = Weapon("sword", 2, 3);
					break;
				case 5:
					return_weapon = Weapon("crossbow", 4, 2);
					break;
				}
			}
		}
		else
		{
			switch (weapon_seed)
			{
			case 1:
				return_weapon = Weapon("branch", 1, 1);
				break;
			case 2:
				return_weapon = Weapon("slingshot", 2, 1);
				break;
			case 3:
				return_weapon = Weapon("spear", 2, 1);
				break;
			case 4:
				return_weapon = Weapon("whip", 1, 2);
				break;
			case 5:
				return_weapon = Weapon("knife", 2, 2);
				break;
			}
		}
	}
	return return_weapon;
}
