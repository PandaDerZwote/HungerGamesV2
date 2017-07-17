#include "ContestantController.hpp"

using namespace std;

ContestantController::ContestantController()
{
	this->id_counter = 0;
}

void ContestantController::addContestant(Contestant t_actor)
{
	contestants.push_back(t_actor);
	setId(&contestants[contestants.size() - 1]);
}

vector<Contestant>* ContestantController::getContestants()
{
	return &contestants;
}

Contestant* ContestantController::getRandomContestantInArea(Contestant t_actor)
{
	int location_id = t_actor.getLocation().getId();
	vector<int> possible_contestants;
	for (unsigned int i = 0; i < contestants.size() ; i++)
	{
		if (contestants[i].getLocation().getId() == location_id && contestants[i].checkVital())
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

void ContestantController::setId(Contestant* t_actor)
{
	t_actor->setId(id_counter);
	id_counter++;
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
		if (t_pronoun == "possesiv_pronoun") { pronoun = "his"; }
		if (t_pronoun == "possesiv_pronoun_cap") { pronoun = "His"; }
		if (t_pronoun == "object_pronoun") { pronoun = "him"; }
		if (t_pronoun == "object_pronoun_cap") { pronoun = "Him"; }
	}
	else
	{
		if (t_pronoun == "pronoun") { pronoun = "she"; }
		if (t_pronoun == "pronoun_cap") { pronoun = "She"; }
		if (t_pronoun == "possesiv_pronoun") { pronoun = "her"; }
		if (t_pronoun == "possesiv_pronoun_cap") { pronoun = "Her"; }
		if (t_pronoun == "object_pronoun") { pronoun = "her"; }
		if (t_pronoun == "object_pronoun_cap") { pronoun = "Her"; }
	}
	return pronoun;
}
