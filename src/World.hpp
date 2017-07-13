#ifndef WORLD_HPP_
#define WORLD_HPP_

#include "Contestant.hpp"
#include "Item.hpp"
#include "Location.hpp"
#include <vector>
#include "WeaponController.hpp"
#include "LocationController.hpp"

class World
{
public:
	// Controller
	WeaponController weapon_controller;
	LocationController location_controller;
	// Methoden
	World();
	Location getLocation(int);
};

#endif /* WORLD_HPP_ */
