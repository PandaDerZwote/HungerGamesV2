#include "Weapon.hpp"

Weapon::Weapon(string pName, int pDamage, int pDurability)
{
	this->name = pName;
	this->damage = pDamage;
	this->durability = pDurability;
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

string Weapon::nameGet()
{
	return this->name;
}

int Weapon::damageGet()
{
	return this->damage;
}
