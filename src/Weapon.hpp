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
	Weapon(string pName, int pDamage, int pDurability);
	Weapon();
	bool durabilityTest();
	bool nullWeapon();
	string nameGet();
	int damageGet();
};



#endif /* WEAPON_HPP_ */
