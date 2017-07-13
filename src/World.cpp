#include "World.hpp"

World::World()
{
	weapon_controller = WeaponController();
	location_controller = LocationController();
}

Location World::getLocation(int p_id)
{
	return location_controller.locations[p_id];
}
