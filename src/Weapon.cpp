#include "Weapon.hpp"

Weapon::Weapon(string p_name, int p_damage, int p_durability)
{
	this->name = p_name;
	this->damage = p_damage;
	this->durability = p_durability;
}

Weapon::Weapon()
{
	this->name = "NULL";
	this->damage = 0;
	this->durability = 0;
}

bool Weapon::durabilityTest()
{
	if (binaryRandom() == true)
	{
		durability -= 1;
		if (durability <= 0)
		{
			return false;
		}
		else return true;
	}
	return true;
}

string Weapon::getName()
{
	return this->name;
}

int Weapon::getDamage()
{
	return this->damage;
}
