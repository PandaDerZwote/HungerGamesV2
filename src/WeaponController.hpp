#ifndef WEAPONCONTROLLER_HPP_
#define WEAPONCONTROLLER_HPP_

#include "Weapon.hpp"
#include <vector>
#include "Random.hpp"

class WeaponController
{
private:
	vector<Weapon> low_tier_weapons;
	vector<Weapon> mid_tier_weapons;
	vector<Weapon> high_tier_weapons;
public:
	WeaponController();
	Weapon getRandomWeapon();
	Weapon getTierWeapon(string);
	Weapon getNull();
};


#endif /* WEAPONCONTROLLER_HPP_ */
