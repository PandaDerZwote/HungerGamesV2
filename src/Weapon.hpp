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
	Weapon(string p_name, int p_damage, int p_durability);
	Weapon();
	bool durabilityTest();
	bool nullWeapon();
	string getName();
	int getDamage();
};



#endif /* WEAPON_HPP_ */
