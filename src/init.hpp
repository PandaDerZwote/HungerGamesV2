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

void init(vector<Location> *world, vector<Contestant> *cast);

void random_init();

void location_init(vector<Location> *world);

void contestant_init(vector<Contestant> *cast, vector<Location> *world);

#endif /* INIT_HPP_ */
