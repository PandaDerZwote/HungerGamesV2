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
	vector<Contestant> survivors;
	init(&world, &cast);
	// Contest
	setup(&cast);
	Contestant winner("Nobody");
	int day = 1;
	while (winner.getName() == "Nobody")
	{
		cout << " - DAY " << day << " -" << endl;
		unsigned int cast_alive = cast.size();
		for (unsigned int i = 0; i < cast_alive; i++)
		{
			if (cast[i].checkVital())
			{
				string output;
				// Test if last survivor
				bool last_survivor = true;
				for (unsigned int j = 0; j < cast.size(); j++)
				{
					if (cast[j].checkVital() && j != i)
					{
						last_survivor = false;
					}
				}
				if (last_survivor)
				{
					break;
				}
				// Turn
				//insert items
				locationSwap(&cast[i], world);
				output = locationEvent(&cast[i]);
				if (cast[i].checkVital() && cast[i].getActionPoints() == 1)
				{
					//insert interaction
					//insert combat
					//insert retreat
				}
				cout << output << endl;
			}
		}
		/*string input;
		cout << "To continue, type anything" << endl;
		cin >> input;
		*/
		cout << endl;
		day++;
		survivors.clear();
		// Check survivors and refresh Action Points.
		for (unsigned int i = 0; i < cast.size(); i++)
		{
			cast[i].setActionPoints(1);
			if (cast[i].checkVital())
			{
				survivors.push_back(cast[i]);
			}
		}
		if (survivors.size() == 1)
		{
			winner = survivors[0];
		}
	}
	cout << "And the winner is " << survivors[0].getName() << "!";
}
