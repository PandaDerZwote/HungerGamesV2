#include "init.hpp"

void init(vector<Contestant> *cast)
{
	random_init();
}

void random_init()
{
	srand(time(0));
}

vector<Contestant> contestantInit(World world)
{
	vector<Contestant> cast;
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
		new_contestant.setLocation(world.getLocation(0));
		new_contestant.setGender(p_gender);
		cast.push_back(new_contestant);
	}
	return cast;
}
