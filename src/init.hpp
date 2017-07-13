/*
 * init.hpp
 *
 *  Created on: 11.07.2017
 *      Author: Jan
 */

#ifndef INIT_HPP_
#define INIT_HPP_

#include "Random.hpp"
#include "Location.hpp"
#include "Contestant.hpp"
#include "LocationController.hpp"
#include "World.hpp"

void init(vector<Contestant> *cast);

void random_init();

//void location_init(vector<Location> *world);

vector<Contestant> contestantInit(World);

#endif /* INIT_HPP_ */
