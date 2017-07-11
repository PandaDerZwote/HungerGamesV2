#ifndef CONTEST_HPP_
#define CONTEST_HPP_

#include <iostream>
#include <vector>
#include "Contestant.hpp"
#include "Location.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include "Random.hpp"

using namespace std;

void setup(vector<Contestant> *cast);

void locationSwap(Contestant *actor, vector<Location> world);

void locationEvent(Contestant *actor);

#endif /* CONTEST_HPP_ */
