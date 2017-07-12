#include "init.hpp"

void init(vector<Location> *world, vector<Contestant> *cast)
{
	random_init();
	location_init(world);
	contestant_init(cast, world);
}

void random_init()
{
	srand(time(0));
}

void location_init(vector<Location> *world)
{
	// Init
	Location cornucopia("cornucopia");
	Location mountain("mountain");
	Location lake("lake");
	Location meadow("meadow");
	Location forest_east("eastern forest");
	Location forest_west("western forest");
	Location shore("shore");
	// Set ID
	cornucopia.setId(1);
	mountain.setId(2);
	lake.setId(3);
	meadow.setId(4);
	forest_east.setId(5);
	forest_west.setId(6);
	shore.setId(7);
	// Set nodes
	cornucopia.addNeighbour(mountain);
	cornucopia.addNeighbour(lake);
	cornucopia.addNeighbour(meadow);
	cornucopia.addNeighbour(forest_east);
	cornucopia.addNeighbour(shore);
	mountain.addNeighbour(cornucopia);
	mountain.addNeighbour(lake);
	lake.addNeighbour(cornucopia);
	lake.addNeighbour(mountain);
	lake.addNeighbour(forest_east);
	lake.addNeighbour(forest_west);
	meadow.addNeighbour(cornucopia);
	meadow.addNeighbour(forest_east);
	meadow.addNeighbour(shore);
	forest_east.addNeighbour(cornucopia);
	forest_east.addNeighbour(lake);
	forest_east.addNeighbour(meadow);
	forest_east.addNeighbour(forest_west);
	forest_east.addNeighbour(shore);
	forest_west.addNeighbour(lake);
	forest_west.addNeighbour(forest_east);
	shore.addNeighbour(cornucopia);
	shore.addNeighbour(meadow);
	shore.addNeighbour(forest_east);
	// Add to vector
	world->push_back(cornucopia);
	world->push_back(mountain);
	world->push_back(lake);
	world->push_back(meadow);
	world->push_back(forest_east);
	world->push_back(forest_west);
	world->push_back(shore);
	// Return
}

void contestant_init(vector<Contestant> *cast, vector<Location> *world)
{
	int cast_size;
	cout << "Please set cast size." << endl;
	cin >> cast_size;
	for (int i = 0; i < cast_size; i++)
	{
		string p_name, p_pic_path, p_gender;
		cout << "Please insert the name of contestant nr. " << i+1 << "." << endl;
		cin >> p_name;
		cout << "m or w?" << endl;
		cin >> p_gender;
		if (p_gender != "m" && p_gender != "w")
		{
			p_gender = "m";
		}
		//cout << "Add a picture? Insert path to picture or type \'n\', if no picture is wanted." << endl;
		//cin >> p_pic_path;
		Contestant new_contestant(p_name);
		/*if (p_pic_path != "n")
		{
			new_contestant.addPic(p_pic_path);
		}*/
		new_contestant.setLocation(world->at(0));
		new_contestant.setGender(p_gender);
		cast->push_back(new_contestant);
	}
}
