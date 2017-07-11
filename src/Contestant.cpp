#include "Contestant.hpp"

Contestant::Contestant(string pName)
{
	this->name = pName;
	health = 5;
	alive = true;
}

// Weapon

void Contestant::weaponSet(Weapon pWeapon)
{
	this->weapon = pWeapon;
}

Weapon Contestant::weaponGet()
{
	return this->weapon;
}

bool Contestant::weaponCheck()
{
	if (this->weaponGet().nameGet() == "NULL")
	{
		return false;
	}
	return true;
}

// Health

int Contestant::getHealth()
{
	return this->health;
}

void Contestant::setHealth(int pHealth)
{
	this->health = pHealth;
	if (health <= 0)
	{
		this->alive = false;
	}
}

bool Contestant::checkVital()
{
	return this->alive;
}

// Combat

void Contestant::combatRound(Contestant *pEnemy)
{
	// Determine combat bonus for both sides
	int combatBonus = this->weaponGet().damageGet();
	int enemyCombatBonus = pEnemy->weaponGet().damageGet();
	// Test if Weapon breaks
	if (this->weaponGet().durabilityTest() == false)
	{
		Weapon nullWeapon("NULL", 0, 0);
		this->weaponSet(nullWeapon);
	}
	if (pEnemy->weaponGet().durabilityTest() == false)
	{
		Weapon nullWeapon("NULL", 0, 0);
		pEnemy->weaponSet(nullWeapon);
	}
	// Determine Combat Roll
	int combatRoll = setRandom(6) + combatBonus;
	int enemyCombatRoll = setRandom(6) + enemyCombatBonus;
	// Determine Result
	int result = combatRoll - enemyCombatRoll;
	if (result < 0)
	{
		this->setHealth(this->getHealth() + result);
		cout << pEnemy->name << " deals " << result * -1 << " damage to " << this->name << " (" << this->getHealth() << " remaining)" << endl;
	}
	if (result > 0)
	{
		pEnemy->setHealth(pEnemy->getHealth() - result);
		cout << this->name << " deals " << result << " damage to " << pEnemy->name << " (" << pEnemy->getHealth() << " remaining)" << endl;
	}
}
