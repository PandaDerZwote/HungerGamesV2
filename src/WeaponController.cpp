#include "WeaponController.hpp"

WeaponController::WeaponController()
{
	// Low tier weapons
	low_tier_weapons.push_back(Weapon("branch" , 1, 1));
	low_tier_weapons.push_back(Weapon("slingshot" , 1, 1));
	low_tier_weapons.push_back(Weapon("primitive spear" , 1, 1));
	low_tier_weapons.push_back(Weapon("whip" , 1, 1));
	low_tier_weapons.push_back(Weapon("knife" , 1, 2));
	// Mid tier weapons
	mid_tier_weapons.push_back(Weapon("axe" , 2, 2));
	mid_tier_weapons.push_back(Weapon("spear" , 2, 1));
	mid_tier_weapons.push_back(Weapon("bow" , 2, 2));
	mid_tier_weapons.push_back(Weapon("sword" , 2, 2));
	mid_tier_weapons.push_back(Weapon("machete" , 2, 2));
	mid_tier_weapons.push_back(Weapon("crossbow" , 3, 2));
	// High tier weapons
	high_tier_weapons.push_back(Weapon("trident" , 3, 2));
	high_tier_weapons.push_back(Weapon("scythe" , 3, 2));
	high_tier_weapons.push_back(Weapon("gun" , 4, 2));
	high_tier_weapons.push_back(Weapon("grenade" , 6, 0));
	high_tier_weapons.push_back(Weapon("flamethrower" , 5, 1));
	high_tier_weapons.push_back(Weapon("steel mace" , 3, 2));
}

Weapon WeaponController::getRandomWeapon()
{
	int random = setRandom(100);
	vector<Weapon> range_of_choices;
	if(random > 50)
	{
		if (random > 95)
		{
			range_of_choices = high_tier_weapons;
		}
		else
		{
			range_of_choices = mid_tier_weapons;
		}
	}
	else
	{
		range_of_choices = low_tier_weapons;
	}
	return range_of_choices[setRandom(range_of_choices.size() - 1)];
}

Weapon WeaponController::getTierWeapon(string p_tier)
{
	if (p_tier == "low")
	{
		return low_tier_weapons[setRandom(low_tier_weapons.size() - 1)];
	}
	if (p_tier == "mid")
	{
		return mid_tier_weapons[setRandom(mid_tier_weapons.size() - 1)];
	}
	if (p_tier == "high")
	{
		return high_tier_weapons[setRandom(high_tier_weapons.size() - 1)];
	}
	else
	{
		return getRandomWeapon();
	}
}

Weapon WeaponController::getNull()
{
	return Weapon("NULL", 0, 0);
}
