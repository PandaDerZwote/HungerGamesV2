#ifndef CONTESTANT_HPP_
#define CONTESTANT_HPP_

#include <string>
#include <vector>
#include "Item.hpp"
#include "Weapon.hpp"
#include <iostream>

using namespace std;

class Contestant
{
private:
	string name, picPath;
	int health;
	Weapon weapon;
	vector<Item> inventory;
	bool alive;
public:
	// Setup
	Contestant(string name);
	void addPic(string pPicPath);
	// Health
	int getHealth();
	void setHealth(int pHealth);
	bool checkVital();
	// Weapon
	void weaponSet(Weapon nWeapon);
	Weapon weaponGet();
	bool weaponCheck();
	// Combat
	void combatRound(Contestant *pEnemy);
};



#endif /* CONTESTANT_HPP_ */
