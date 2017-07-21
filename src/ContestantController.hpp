#ifndef WORLD_CONTESTANTCONTROLLER_HPP_
#define WORLD_CONTESTANTCONTROLLER_HPP_

#include <vector>
#include "Contestant.hpp"
#include "Random.hpp"
#include "LocationController.hpp"
#include "WeaponController.hpp"

class ContestantController
{
private:
	std::vector<Contestant> contestants;
	string winner;
	int id_counter;
public:
	// Constructors
	ContestantController();
	// Contestants

	void addContestant(Contestant);
	std::vector<Contestant>* getContestants();
	Contestant* getContestant(int);
	void setId(Contestant*);
	void buildCast(LocationController);
	void equipCast(WeaponController);
	void refreshAP();
	// Intrinsic Methods
	Contestant* getRandomContestantInArea(Contestant);
	bool checkIfLastSurvivor(Contestant);
	bool checkForWinner();
	string accessWinner();
	bool canStillAct(Contestant);
	string getPronoun(Contestant, string);
	string stageFight(Contestant*);
};



#endif /* WORLD_CONTESTANTCONTROLLER_HPP_ */
