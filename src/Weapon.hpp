/*
 * Weapon.hpp
 *
 *  Created on: 10.07.2017
 *      Author: Jan
 */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>
#include "Random.hpp"

using namespace std;

class Weapon
{
private:
	string name;
	int damage, durability;
public:
	// Constructors
	Weapon(string p_name, int p_damage, int p_durability);
	Weapon();
	// Get and Set
	string getName();
	int getDamage();
	// Tests
	bool isNull();
	// Intrinsic Methods
	bool durabilityTest();
};



#endif /* WEAPON_HPP_ */
