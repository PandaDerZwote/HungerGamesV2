#ifndef CONTEST_HPP_
#define CONTEST_HPP_

#include <iostream>
#include <vector>
#include "Contestant.hpp"
#include "Location.hpp"
#include "Weapon.hpp"
#include "Item.hpp"
#include "Random.hpp"
#include "WeaponController.hpp"
#include "LocationController.hpp"
#include "World.hpp"

void setup(std::vector<Contestant> *cast);

void locationSwap(Contestant*, World);

string locationEvent(Contestant*, World);

#endif /* CONTEST_HPP_ */
