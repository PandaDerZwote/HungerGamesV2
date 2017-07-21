#include "ContestantController.hpp"

using namespace std;

// Constructor
ContestantController::ContestantController()
{
	this->id_counter = 0;
	this->winner = "";
}

//Contestants
void ContestantController::addContestant(Contestant t_actor)
{
	contestants.push_back(t_actor);
	setId(&contestants[contestants.size() - 1]);
}

vector<Contestant>* ContestantController::getContestants()
{
	return &contestants;
}

Contestant* ContestantController::getContestant(int t_contestant_number)
{
	return &contestants[t_contestant_number];
}

void ContestantController::setId(Contestant* t_actor)
{
	t_actor->setId(id_counter);
	id_counter++;
}

void ContestantController::buildCast(LocationController world)
{
	int cast_size;
	cout << "Please set cast size." << endl;
	cin >> cast_size;
	for (int i = 0; i < cast_size; i++)
	{
		string p_name, p_pic_path, p_gender;
		cout << "Please insert the name of contestant nr. " << i+1 << "." << endl;
		cin >> p_name;
		cout << "m or w?" << endl;
		cin >> p_gender;
		if (p_gender != "m" && p_gender != "w")
		{
			p_gender = "m";
		}
		Contestant new_contestant(p_name);
		new_contestant.setLocation(world.locations[0]);
		new_contestant.setGender(p_gender);
		addContestant(new_contestant);
	}
}

void ContestantController::equipCast(WeaponController weapons)
{
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		int random = setRandom(4);
		if (random < 4)
		{
			contestants[i].setWeapon(weapons.getTierWeapon("low"));
		}
	}
}

void ContestantController::refreshAP()
{
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		contestants[i].setActionPoints(1);
	}
}

//Intrinsic Methods
Contestant* ContestantController::getRandomContestantInArea(Contestant t_actor)
{
	int location_id = t_actor.getLocation().getId();
	vector<int> possible_contestants;
	for (unsigned int i = 0; i < contestants.size() ; i++)
	{
		if (contestants[i].getLocation().getId() == location_id && contestants[i].checkVital() && contestants[i].getId() != t_actor.getId())
		{
			possible_contestants.push_back(i);
		}
	}
	if (possible_contestants.size() > 0)
	{
		return &contestants[possible_contestants[setRandom(possible_contestants.size()) - 1]];
	}
	return nullptr;
}

bool ContestantController::checkIfLastSurvivor(Contestant t_actor)
{
	bool last_survivor = true;
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		if (contestants[i].checkVital() && contestants[i].getId() != t_actor.getId())
		{
			last_survivor = false;
			return last_survivor;
		}
	}
	return last_survivor;
}

bool ContestantController::checkForWinner()
{
	int survivors = 0;
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		if (contestants[i].checkVital() == true)
		{
			survivors++;
			winner = contestants[i].getName();
		}
		if (survivors > 1)
		{
			return false;
		}
	}
	return true;
}

string ContestantController::accessWinner()
{
	return winner;
}

bool ContestantController::canStillAct(Contestant t_actor)
{
	if (!(t_actor.checkVital()))
	{
		return false;
	}
	if (t_actor.getActionPoints() == 0)
	{
		return false;
	}
	return true;
}

string ContestantController::getPronoun(Contestant t_actor, string t_pronoun)
{
	string pronoun;
	if (t_actor.getGender() == "m")
	{
		if (t_pronoun == "pronoun") { pronoun = "he"; }
		if (t_pronoun == "pronoun_cap") { pronoun = "He"; }
		if (t_pronoun == "possesive_pronoun") { pronoun = "his"; }
		if (t_pronoun == "possesive_pronoun_cap") { pronoun = "His"; }
		if (t_pronoun == "object_pronoun") { pronoun = "him"; }
		if (t_pronoun == "object_pronoun_cap") { pronoun = "Him"; }
	}
	else
	{
		if (t_pronoun == "pronoun") { pronoun = "she"; }
		if (t_pronoun == "pronoun_cap") { pronoun = "She"; }
		if (t_pronoun == "possesive_pronoun") { pronoun = "her"; }
		if (t_pronoun == "possesive_pronoun_cap") { pronoun = "Her"; }
		if (t_pronoun == "object_pronoun") { pronoun = "her"; }
		if (t_pronoun == "object_pronoun_cap") { pronoun = "Her"; }
	}
	return pronoun;
}

string ContestantController::stageFight(Contestant* t_actor)
{
	string output = "";
	int random;

	Weapon actor_weapon = t_actor->getWeapon();
	Contestant* enemy = getRandomContestantInArea(*t_actor);
	if (!(enemy == nullptr))
	{
		Weapon enemy_weapon = enemy->getWeapon();
		bool winner = t_actor->combatRound(enemy);
		if (winner)
		{
			if (enemy->checkVital())
			{
				if (actor_weapon.isNull())
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands!";
						break;
					case 2:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands!";
						break;
					case 3:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 4:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 5:
						output = t_actor->getName() + " assaults " + enemy->getName() + " with nothing but " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					}
				}
				else
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 2:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 3:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 4:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 5:
						output = t_actor->getName() + " assaults " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
					}
				}
			}
			else
			{
				if (actor_weapon.isNull())
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " kills " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands!";
						break;
					case 2:
						output = t_actor->getName() + " murders " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands!";
						break;
					case 3:
						output = t_actor->getName() + " kills " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 4:
						output = t_actor->getName() + " murders " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 5:
						output = t_actor->getName() + " slays " + enemy->getName() + " with nothing but " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					}
				}
				else
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " kills " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 2:
						output = t_actor->getName() + " murders " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 3:
						output = t_actor->getName() + " kills " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 4:
						output = t_actor->getName() + " murders " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 5:
						output = t_actor->getName() + " slays " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
					}
				}
			}
		}
		else
		{
			if (t_actor->checkVital())
			{
				if (actor_weapon.isNull())
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands! But without success.";
						break;
					case 2:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands! But " + getPronoun(*t_actor, "possesive_pronoun") + " attack was brushed off.";
						break;
					case 3:
						output = t_actor->getName() + " attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists! But without success.";
						break;
					case 4:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists! But " + getPronoun(*t_actor, "possesive_pronoun") + " attack was brushed off.";
						break;
					case 5:
						output = t_actor->getName() + " assaults " + enemy->getName() + " with nothing but " + getPronoun(*t_actor, "possesive_pronoun") + " fists! The attack was a failure.";
						break;
					}
				}
				else
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " unsuccessfully attacks " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 2:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName() + ", but failed.";
						break;
					case 3:
						output = t_actor->getName() + " fails while attacking " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 4:
						output = t_actor->getName() + " ambushes " + enemy->getName() + " unsuccessfully attacking " + getPronoun(*enemy, "object pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 5:
						output = t_actor->getName() + " assaults " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName() + ". The attack was an utter failure!";
						break;
					}
				}
			}
			else
			{
				if (actor_weapon.isNull())
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " gets killed by " + enemy->getName() + " while attacking with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands.";
						break;
					case 2:
						output = t_actor->getName() + " dies attacking " + enemy->getName() + " with " + getPronoun(*t_actor, "possesive_pronoun") + " bare hands!";
						break;
					case 3:
						output = t_actor->getName() + " is brought down by " + enemy->getName() + " while attacking with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 4:
						output = t_actor->getName() + " is killed by " + enemy->getName() + " while attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					case 5:
						output = t_actor->getName() + " is slayn by " + enemy->getName() + " while attacking with nothing but " + getPronoun(*t_actor, "possesive_pronoun") + " fists!";
						break;
					}
				}
				else
				{
					random = setRandom(5);
					switch (random)
					{
					case 1:
						output = t_actor->getName() + " gets killed by " + enemy->getName() + " despite attacking with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 2:
						output = t_actor->getName() + " dies to " + enemy->getName() + " while attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 3:
						output = t_actor->getName() + " falls to " + enemy->getName() + " while attacking with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 4:
						output = t_actor->getName() + " is brought down by " + enemy->getName() + " while attacking " + getPronoun(*enemy, "object_pronoun") + " with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					case 5:
						output = t_actor->getName() + " is slayn by " + enemy->getName() + " during his assault with " + getPronoun(*t_actor, "possesive_pronoun") + " " + actor_weapon.getName();
						break;
					}
				}
			}
		}
		t_actor->setActionPoints(0);
		enemy->setActionPoints(0);
	}
	return output;
}
