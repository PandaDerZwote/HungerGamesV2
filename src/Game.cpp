#include "Game.hpp"

using namespace std;

Game::Game()
{
	weapon_controller = WeaponController();
	location_controller = LocationController();
	contestant_controller = ContestantController();
}

// Turn

string Game::turn(Contestant* t_actor)
{
	string output = "";
	if (t_actor->checkVital())
	{
		if (!(contestant_controller.checkIfLastSurvivor(*t_actor)))
		{
			locationSwap(t_actor);
			if (contestant_controller.canStillAct(*t_actor))
			{
				output = locationEvent(t_actor);
				if (contestant_controller.canStillAct(*t_actor))
				{

				}
			}
		}
	}
	return output;
}

// Submethods of turn

void Game::locationSwap(Contestant* t_actor)
{
	t_actor->setLocation(location_controller.getRandomNeighbourOrSelf(t_actor->getLocation()));
}


// Event
string Game::locationEvent(Contestant* t_actor)
{
	int location = t_actor->getLocation().getId();
	string output = "";
	switch (location)
	{
	case 1:
		output = locationEventCornucopia(t_actor);
		break;
	case 2:
		output = locationEventMountain(t_actor);
		break;
	case 3:
		output = locationEventLake(t_actor);
		break;
	case 4:
		output = locationEventMeadow(t_actor);
		break;
	case 5:
		output = locationEventEasternForest(t_actor);
		break;
	case 6:
		output = locationEventWesternForest(t_actor);
		break;
	case 7:
		output = locationEventShore(t_actor);
		break;
	}
	return output;
}

// Event Submethods
string Game::locationEventCornucopia(Contestant* t_actor)
{
	string output = "";
	int random = setRandom(100);
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
							output.append(t_actor->getName() + " is casually looking around at the cornucopia.");
							t_actor->setActionPoints(0);
							break;
						case 2:
							output.append(t_actor->getName() + " is crying in despair.");
							t_actor->setActionPoints(0);
							break;
						case 3:
							output.append(t_actor->getName() + " is cursing everyone responsible for the Hunger Games.");
							t_actor->setActionPoints(0);
							break;
						}
					}
				}
				else
				{
					Weapon retrieved_weapon;
					if (random > 10)
					{
						Weapon retrieved_weapon = weapon_controller.getRandomWeapon();
					}
					if (!retrieved_weapon.isNull())
					{
						if (retrieved_weapon.getDamage() > t_actor->getWeapon().getDamage())
						{
							if (!(t_actor->getWeapon().isNull()))
							{
								output.append(t_actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it, throwing away " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
								t_actor->setActionPoints(0);
								t_actor->setWeapon(retrieved_weapon);
							}
							else
							{
								output.append(t_actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it.");
								t_actor->setActionPoints(0);
							}
						}
						else
						{
							output.append(t_actor->getName() + " searches the cornucopia for supplies and finds a(n) " + retrieved_weapon.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to keep " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
							t_actor->setActionPoints(0);
						}
					}
					else
					{
						output.append(t_actor->getName() + " searches the cornucopia for supplies and finds nothing.");
						t_actor->setActionPoints(0);
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
					output.append(t_actor->getName() + " stepped on a landmine!");
					t_actor->setActionPoints(0);
					break;
				case 4:
					output.append(t_actor->getName() + " stepped on a landmine and splatters!");
					t_actor->setActionPoints(0);
					break;
				case 5:
					output.append(t_actor->getName() + " stepped on a landmine and was annihilated!");
					t_actor->setActionPoints(0);
				}
				t_actor->die();
			}
	return output;
}

string Game::locationEventMountain(Contestant* t_actor)
{
	int random = setRandom(100);
	string output = "";
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
								output.append(t_actor->getName() + " is climbing in the mountains");
								t_actor->setActionPoints(0);
								break;
							case 2:
								output.append(t_actor->getName() + " is hiking in the mountains");
								t_actor->setActionPoints(0);
								break;
							case 3:
								output.append(t_actor->getName() + " is sitting on top of the mountains, watching over the arena.");
								t_actor->setActionPoints(0);
								break;
							}
						}
					}
					else
					{
						if (!(t_actor->getWeapon().isNull()))
						{
							output.append(t_actor->getName() + " lost " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " weapon while climbing the mountain!");
							t_actor->setActionPoints(0);
							t_actor->setWeapon(weapon_controller.getNull());
						}
					}
				}
				else
				{
					Weapon stone("rock", 1, 1);
					if (t_actor->getWeapon().getDamage() < stone.getDamage())
					{
						if (!(t_actor->getWeapon().isNull()))
						{
							output.append(t_actor->getName() + " found a rock in the mountains " + contestant_controller.getPronoun(*t_actor, "pronoun") + " drops " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + " for it.");
							t_actor->setWeapon(stone);
						}
						else
						{
							output.append(t_actor->getName() + " found a rock in the mountains and is now using it as a weapon.");
							t_actor->setActionPoints(0);
							t_actor->setWeapon(stone);
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
					output.append(t_actor->getName() + " falls of a cliff!");
					t_actor->setActionPoints(0);
					t_actor->die();
					break;
				case 2:
					output.append(t_actor->getName() + " falls of a cliff instantly dying on impact!");
					t_actor->setActionPoints(0);
					t_actor->die();
					break;
				case 3:
					output.append(t_actor->getName() + " falls of a cliff dying after hours of agony!");
					t_actor->setActionPoints(0);
					t_actor->die();
					break;
				case 4:
					t_actor->setHealth(t_actor->getHealth() - 2);
					if (t_actor->checkVital())
					{
						output.append(t_actor->getName() + " falls of a cliff and is injured but survives!");
						t_actor->setActionPoints(0);
					}
					else
					{
						output.append(t_actor->getName() + " falls of a cliff and dies from the injuries!");
						t_actor->setActionPoints(0);
						t_actor->setLocation(location_controller.nullLocation);
					}
					break;
				case 5:
					output.append(t_actor->getName() + " falls of a cliff but survives completetly unharmed!");
					t_actor->setActionPoints(0);
					break;
				}
			}
	return output;
}

string Game::locationEventLake(Contestant* t_actor)
{
	int random = setRandom(100);
	string output = "";
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
							output.append(t_actor->getName() + " is fishing at the lake.");
							t_actor->setActionPoints(0);
							break;
						case 2:
							output.append(t_actor->getName() + " is bathing in the lake.");
							t_actor->setActionPoints(0);
							break;
						case 3:
							output.append(t_actor->getName() + " is sitting near the lake, pondering about the games.");
							t_actor->setActionPoints(0);
							break;
						}
					}
				}
				else
				{
					if (!(t_actor->getWeapon().isNull()))
					{
						output.append(t_actor->getName() + " lost " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " weapon while swimming in the lake!");
						t_actor->setActionPoints(0);
						t_actor->setWeapon(weapon_controller.getNull());
					}
				}
			}
			else
			{
				output.append(t_actor->getName() + " drowned in the lake!");
				t_actor->setActionPoints(0);
				t_actor->die();
			}
	return output;
}

string Game::locationEventMeadow(Contestant* t_actor)
{
	int random = setRandom(100);
	string output = "";
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
							output.append(t_actor->getName() + " is aimlessly running around the meadows.");
							t_actor->setActionPoints(0);
							break;
						case 2:
							output.append(t_actor->getName() + " is hunting in the meadows.");
							t_actor->setActionPoints(0);
							break;
						case 3:
							output.append(t_actor->getName() + " has started a campfire.");
							t_actor->setActionPoints(0);
							break;
						}
					}
				}
				else
				{
					if (t_actor->getHealth() < 5)
					{
						if (t_actor->getHealth() + 2 >= 5)
						{
							t_actor->setHealth(5);
							output.append(t_actor->getName() + " receives medical aid from an unknown sponsor and fully recovered!");
							t_actor->setActionPoints(0);
						}
						else
						{
							t_actor->setHealth(t_actor->getHealth() + 2);
							output.append(t_actor->getName() + " receives medical aid from an unknown sponsor.");
							t_actor->setActionPoints(0);
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
					output.append(t_actor->getName() + " was bitten by a snake! The snake was venomous and " + contestant_controller.getPronoun(*t_actor, "pronoun") + " died!");
					t_actor->setActionPoints(0);
					t_actor->die();
					break;
				case 4:
					t_actor->setHealth(t_actor->getHealth() - 2);
					if (t_actor->checkVital())
					{
						output.append(t_actor->getName() + " was bitten by a snake! Venom flows through " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " body, but " + contestant_controller.getPronoun(*t_actor, "pronoun") + " survives!");
						t_actor->setActionPoints(0);
					}
					else
					{
						output.append(t_actor->getName() + " was bitten by a snake! Venom flows through " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " body, killing " + contestant_controller.getPronoun(*t_actor, "object_pronoun") + " slowly and painfully!");
						t_actor->setActionPoints(0);
					}
					break;
				case 5:
					output.append(t_actor->getName() + " was bitten by a snake! Nothing happened.");
					t_actor->setActionPoints(0);
					break;
				}
			}
	return output;
}

string Game::locationEventEasternForest(Contestant* t_actor)
{
	int random = setRandom(100);
	string output = "";
	if (random > 5)
	{
		if (random > 15)
		{
			if (random > 90)
			{
				int flavour_eastern_forest = setRandom(3);
				switch (flavour_eastern_forest)
				{
				case 1:
					output.append(t_actor->getName() + " got lost in the woods.");
					t_actor->setActionPoints(0);
					break;
				case 2:
					output.append(t_actor->getName() + " searches the woods for food.");
					t_actor->setActionPoints(0);
					break;
				case 3:
					output.append(t_actor->getName() + " wonders if there is something deeper in the woods.");
					t_actor->setActionPoints(0);
					break;
				}
			}
		}
		else
		{
			Weapon stach = weapon_controller.getTierWeapon("low");
			if (!stach.isNull())
			{
				if (stach.getDamage() > t_actor->getWeapon().getDamage())
				{
					if (!(t_actor->getWeapon().isNull()))
					{
						output.append(t_actor->getName() + " found a hidden weapon stach! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it, throwing away " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
						t_actor->setActionPoints(0);
						t_actor->setWeapon(stach);
					}
					else
					{
						output.append(t_actor->getName() + " found a hidden weapon stach! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it.");
						t_actor->setActionPoints(0);
					}
				}
				else
				{
					output.append(t_actor->getName() + " found a hidden weapon stach! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to keep " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
					t_actor->setActionPoints(0);
				}
			}
		}
	}
	else
	{
		int pit_random = setRandom(5);
		switch (pit_random)
		{
		case 1:
			output.append(t_actor->getName() + " falls into a pit snapping " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " on impact!");
			t_actor->setActionPoints(0);
			t_actor->die();
			break;
		case 2:
		case 3:
		case 4:
			t_actor->setHealth(t_actor->getHealth() - 1);
			if (t_actor->checkVital())
			{
				output.append(t_actor->getName() + " falls into a pit hitting " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " head on a rock " + contestant_controller.getPronoun(*t_actor, "pronoun") + " is fine though.");
				t_actor->setActionPoints(0);
			}
			else
			{
				output.append(t_actor->getName() + " falls into a pit hitting " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " head on a rock " + contestant_controller.getPronoun(*t_actor, "pronoun") + " dies from internal bleeding!");
				t_actor->setActionPoints(0);
			}
			break;
		case 5:
			output.append(t_actor->getName() + " falls into a pit. It wasn't deep enough to do anything, while climbing out of it, a shadowy figure runs away.");
			t_actor->setActionPoints(0);
			break;
		}
	}
	return output;
}

string Game::locationEventWesternForest(Contestant* t_actor)
{
	int random = setRandom(100);
	string output = "";
	if (random > 5)
	{
		if (random > 10)
		{
			if (random > 88)
			{
				if (random > 98)
				{
					Weapon stach = weapon_controller.getTierWeapon("high");
					if (!stach.isNull())
					{
						if (stach.getDamage() > t_actor->getWeapon().getDamage())
						{
							if (!(t_actor->getWeapon().isNull()))
							{
								output.append(t_actor->getName() + " found a high quality loot crate! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it, throwing away " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
								t_actor->setActionPoints(0);
								t_actor->setWeapon(stach);
							}
							else
							{
								output.append(t_actor->getName() + " found a high quality loot crate! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to equip it.");
								t_actor->setActionPoints(0);
							}
						}
						else
						{
							output.append(t_actor->getName() + " found a high quality loot crate! Inside was a(n) " + stach.getName() + ". " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " decides to keep " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " " + t_actor->getWeapon().getName() + ".");
							t_actor->setActionPoints(0);
						}
					}
				}
				else
				{
					int flavour_eastern_forest = setRandom(3);
					switch (flavour_eastern_forest)
					{
					case 1:
						output.append(t_actor->getName() + " is pretty sure there is something in the woods.");
						t_actor->setActionPoints(0);
						break;
					case 2:
						output.append(t_actor->getName() + " finds weird berries in the woods.");
						t_actor->setActionPoints(0);
						break;
					case 3:
						output.append(t_actor->getName() + " starts a fire but abandons it.");
						t_actor->setActionPoints(0);
						break;
					}
				}
			}
		}
		else
		{
			output.append(t_actor->getName() + " was devoured by... something in the woods...");
			t_actor->setActionPoints(0);
			t_actor->die();
		}
	}
	else
	{
		int tree_random = setRandom(5);
		switch (tree_random)
		{
		case 1:
			output.append(t_actor->getName() + " tries to climb up a tree, but falls, injuring " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " leg on impact. It gets infected, killing " + contestant_controller.getPronoun(*t_actor, "object_pronoun") + ".");
			t_actor->setActionPoints(0);
			t_actor->die();
			break;
		case 2:
		case 3:
		case 4:
			t_actor->setHealth(t_actor->getHealth() - 1);
			if (t_actor->checkVital())
			{
				output.append(t_actor->getName() + " tries to climb up a tree, but falls, injuring " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " leg. " + contestant_controller.getPronoun(*t_actor, "pronoun_cap") + " is fine though.");
				t_actor->setActionPoints(0);
			}
			else
			{
				output.append(t_actor->getName() + " tries to climb up a tree, but falls and gets impaled on a spike!");
				t_actor->setActionPoints(0);
			}
			break;
		case 5:
			output.append(t_actor->getName() + " tries to climb up a tree but falls, " + contestant_controller.getPronoun(*t_actor, "pronoun") + " manages to land without a scratch.");
			t_actor->setActionPoints(0);
			break;
		}
	}
	return output;
}

string Game::locationEventShore(Contestant* t_actor)
{
	int random = setRandom(100);
		string output = "";
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
								output.append(t_actor->getName() + " is walking alongside the shore.");
								t_actor->setActionPoints(0);
								break;
							case 2:
								output.append(t_actor->getName() + " is sun bathing.");
								t_actor->setActionPoints(0);
								break;
							case 3:
								output.append(t_actor->getName() + " is skipping stones on the shore.");
								t_actor->setActionPoints(0);
								break;
							}
						}
					}
					else
					{
						if (!(t_actor->getWeapon().isNull()))
						{
							output.append(t_actor->getName() + " lost " + contestant_controller.getPronoun(*t_actor, "possesive_pronoun") + " weapon while swimming at the shore!");
							t_actor->setActionPoints(0);
							t_actor->setWeapon(weapon_controller.getNull());
						}
					}
				}
				else
				{
					output.append(t_actor->getName() + " got carried away by the currents at the shore!");
					t_actor->setActionPoints(0);
					t_actor->die();
				}
		return output;
}
