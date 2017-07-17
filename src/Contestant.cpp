#include "Contestant.hpp"

Contestant::Contestant(string p_name)
{
	this->name = p_name;
	this->health = 5;
	this->alive = true;
	Location start("NULL", 0);
	this->location = start;
	this->gender = "m";
	this->action_points = 1;
	this->id = 0;
}

void Contestant::addPic(string p_pic_path)
{
	pic_path = p_pic_path;
}

string Contestant::getName()
{
	return name;
}

void Contestant::setId(int t_id)
{
	this->id = t_id;
}

int Contestant::getId()
{
	return id;
}

// Location

Location Contestant::getLocation()
{
	return location;
}

void Contestant::setLocation(Location p_location)
{
	this->location = p_location;
}

// Gender

string Contestant::getGender()
{
	return this->gender;
}

void Contestant::setGender(string p_gender)
{
	this->gender = p_gender;
}

// Health

int Contestant::getHealth()
{
	return this->health;
}

void Contestant::setHealth(int p_health)
{
	this->health = p_health;
	if (health <= 0)
	{
		this->alive = false;
	}
}

bool Contestant::checkVital()
{
	return this->alive;
}

void Contestant::die()
{
	this->setHealth(0);
	Location l;
	this->setLocation(l);
}

// ActionPoints

int Contestant::getActionPoints()
{
	return this->action_points;
}

void Contestant::setActionPoints(int p_action_points)
{
	this->action_points = p_action_points;
}



// Weapon

void Contestant::setWeapon(Weapon p_weapon)
{
	this->weapon = p_weapon;
}

Weapon Contestant::getWeapon()
{
	return this->weapon;
}

bool Contestant::checkWeapon()
{
	if (this->getWeapon().getName() == "NULL")
	{
		return false;
	}
	return true;
}


// Combat

void Contestant::combatRound(Contestant *p_enemy)
{
	// Determine combat bonus for both sides
	int combat_bonus = this->getWeapon().getDamage();
	int enemy_combat_bonus = p_enemy->getWeapon().getDamage();
	// Test if Weapon breaks
	if (this->getWeapon().durabilityTest() == false)
	{
		Weapon null_weapon("NULL", 0, 0);
		this->setWeapon(null_weapon);
	}
	if (p_enemy->getWeapon().durabilityTest() == false)
	{
		Weapon null_weapon("NULL", 0, 0);
		p_enemy->setWeapon(null_weapon);
	}
	// Determine Combat Roll
	int combat_roll = setRandom(6) + combat_bonus;
	int enemy_combat_roll = setRandom(6) + enemy_combat_bonus;
	// Determine Result
	int result = combat_roll - enemy_combat_roll;
	if (result < 0)
	{
		this->setHealth(this->getHealth() + result);
		//cout << pEnemy->name << " deals " << result * -1 << " damage to " << this->name << " (" << this->getHealth() << " remaining)" << endl;
	}
	if (result > 0)
	{
		p_enemy->setHealth(p_enemy->getHealth() - result);
		//cout << this->name << " deals " << result << " damage to " << pEnemy->name << " (" << pEnemy->getHealth() << " remaining)" << endl;
	}
}
