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

void init(vector<Location> *world);

void random_init();

vector<Location> location_init();

#endif /* INIT_HPP_ */
