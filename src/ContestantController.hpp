#ifndef WORLD_CONTESTANTCONTROLLER_HPP_
#define WORLD_CONTESTANTCONTROLLER_HPP_

#include <vector>
#include "Contestant.hpp"
#include "Random.hpp"

class ContestantController
{
private:
	std::vector<Contestant> contestants;
	int id_counter;
public:
	// Constructors
	ContestantController();
	// Contestants
	void addContestant(Contestant);
	std::vector<Contestant>* getContestants();
	void setId(Contestant*);
	// Intrinsic Methods
	Contestant* getRandomContestantInArea(Contestant);
	bool checkIfLastSurvivor(Contestant);
	bool canStillAct(Contestant);
	string getPronoun(Contestant, string);
};



#endif /* WORLD_CONTESTANTCONTROLLER_HPP_ */
