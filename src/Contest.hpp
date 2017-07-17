#ifndef CONTEST_HPP_
#define CONTEST_HPP_

#include <iostream>
#include <vector>
#include "Contestant.hpp"
#include "Game.hpp"
#include "Location.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include "Random.hpp"
#include "WeaponController.hpp"
#include "LocationController.hpp"

void setup(std::vector<Contestant> *cast);

void locationSwap(Contestant*, Game);

string locationEvent(Contestant*, Game);

#endif /* CONTEST_HPP_ */
