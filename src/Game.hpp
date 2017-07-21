#ifndef GAME_HPP_
#define GAME_HPP_

#include "Contestant.hpp"
#include "Item.hpp"
#include "Location.hpp"
#include <vector>
#include "WeaponController.hpp"
#include "LocationController.hpp"
#include "ContestantController.hpp"

class Game
{
public:
	// Controller
	WeaponController weapon_controller;
	LocationController location_controller;
	ContestantController contestant_controller;
	// Constructor
	Game();

	// Game
	void play();

	// Turn
	string turn(Contestant*);
	// Submethods of turn
	void locationSwap(Contestant*);

	// Event
	string locationEvent(Contestant*);
	// Submethods of event
	string locationEventCornucopia(Contestant*);
	string locationEventMountain(Contestant*);
	string locationEventLake(Contestant*);
	string locationEventMeadow(Contestant*);
	string locationEventEasternForest(Contestant*);
	string locationEventWesternForest(Contestant*);
	string locationEventShore(Contestant*);
};

#endif /* GAME_HPP_ */
