#include <iostream>
#include "Random.hpp"
#include "init.hpp"
#include "Weapon.hpp"
#include "Contestant.hpp"
#include "Location.hpp"

using namespace std;

int main()
{
	// Initiate
	vector<Location> world;
	init(&world);
	// Main Body
	vector<Location> test = world[0].getNeighbours();
	cout << test.size();
}
