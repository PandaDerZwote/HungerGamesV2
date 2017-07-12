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
	int health;
	Weapon weapon;
	vector<Item> inventory;
	bool alive;
	Location location;
public:
	// Setup
	Contestant(string p_name);
	void addPic (string p_pic_path);
	string getName();
	// Location
	Location getLocation();
	void setLocation(Location p_location);
	// Gender
	string getGender();
	void setGender(string p_gender);
	// Health
	int getHealth();
	void setHealth(int p_health);
	bool checkVital();
	// Weapon
	void setWeapon(Weapon n_weapon);
	Weapon getWeapon();
	bool checkWeapon();
	// Combat
	void combatRound(Contestant *p_enemy);
};



#endif /* CONTESTANT_HPP_ */
