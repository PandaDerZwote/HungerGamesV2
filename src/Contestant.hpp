#ifndef CONTESTANT_HPP_
#define CONTESTANT_HPP_

#include <string>
#include <vector>
#include "Item.hpp"
#include "Weapon.hpp"
#include <iostream>
#include "Location.hpp"

using namespace std;

class Contestant
{
private:
	string name, pic_path, gender;
	int health, action_points, id;
	Weapon weapon;
	vector<Item> inventory;
	bool alive;
	Location location;
public:
	// Setup
	Contestant(string);
	void addPic (string);
	string getName();
	void setId(int);
	int getId();
	// Location
	Location getLocation();
	void setLocation(Location);
	// Gender
	string getGender();
	void setGender(string);
	// Health
	int getHealth();
	void setHealth(int);
	bool checkVital();
	void die();
	// Action Points
	int getActionPoints();
	void setActionPoints(int);
	// Weapon
	void setWeapon(Weapon);
	Weapon getWeapon();
	bool checkWeapon();
	// Combat
	void combatRound(Contestant*);
};



#endif /* CONTESTANT_HPP_ */
