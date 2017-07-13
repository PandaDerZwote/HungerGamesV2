#include "Contest.hpp"

using namespace std;

void setup(vector<Contestant> *cast)
{
	WeaponController w;
	for (unsigned int i = 0; i < cast->size(); i++)
	{
		int random = setRandom(4);
		if (random < 4)
		{
			cast->at(i).setWeapon(w.getTierWeapon("low"));
			cout << cast->at(i).getName() << " acquired a(n) " << cast->at(i).getWeapon().getName() << "." << endl;
		}
		else
		{
			cout << cast->at(i).getName() << " acquired nothing." << endl;
		}
	}
	cout << "The setup phase has ended!" << endl << endl;
}

void locationSwap(Contestant *actor, World world)
{
	actor->setLocation(world.location_controller.getRandomNeighbourOrSelf(actor->getLocation()));
}

string locationEvent(Contestant *actor, World world)
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

	//Switch to get location events
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
				Weapon retrieved_weapon;
				if (random > 10)
				{
					Weapon retrieved_weapon = world.weapon_controller.getRandomWeapon();
				}
				if (!retrieved_weapon.isNull())
				{
					if (retrieved_weapon.getDamage() > actor->getWeapon().getDamage())
					{
						if (!actor->getWeapon().isNull())
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
			actor->die();
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
					if (!actor->getWeapon().isNull())
					{
						output.append(actor->getName() + " lost " + possesive_pronoun + " weapon while climbing the mountain!");
						actor->setActionPoints(0);
						actor->setWeapon(world.weapon_controller.getNull());
					}
				}
			}
			else
			{
				Weapon stone("rock", 1, 1);
				if (actor->getWeapon().getDamage() < stone.getDamage())
				{
					if (!actor->getWeapon().isNull())
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
				actor->die();
				break;
			case 2:
				output.append(actor->getName() + " falls of a cliff instantly dying on impact!");
				actor->setActionPoints(0);
				actor->die();
				break;
			case 3:
				output.append(actor->getName() + " falls of a cliff dying after hours of agony!");
				actor->setActionPoints(0);
				actor->die();
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
					actor->setLocation(world.location_controller.nullLocation);
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
				if (!actor->getWeapon().isNull())
				{
					output.append(actor->getName() + " lost " + possesive_pronoun + " weapon while swimming in the lake!");
					actor->setActionPoints(0);
					actor->setWeapon(world.weapon_controller.getNull());
				}
			}
		}
		else
		{
			output.append(actor->getName() + " drowned in the lake!");
			actor->setActionPoints(0);
			actor->die();
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
				actor->die();
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
