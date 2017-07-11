#include <iostream>
#include "Random.hpp"
#include "init.hpp"
#include "Weapon.hpp"
#include "Contestant.hpp"
#include "Location.hpp"
#include "Contest.hpp"

using namespace std;

int main()
{
	// Initiate
	vector<Location> world;
	vector<Contestant> cast;
	init(&world, &cast);
	// Contest
	setup(&cast);
	Contestant winner("Nobody");
	int test = 5;
	while (winner.getName() == "Nobody")
	{
		int cast_alive = cast.size();
		for (int i = 0; i < cast_alive; i++)
		{
			if (cast[i].checkVital())
			{
			//insert items
			locationSwap(&cast[i], world);
			//insert loc_events
			//insert interaction
			//insert combat
			//insert retreat
			}
		}
		test -= 1;
		if (test == 0)
		{
			winner = cast[0];
		}
	}
}
