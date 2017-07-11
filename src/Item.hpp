#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>

using namespace std;

class Item
{
private:
	string name;
public:
	Item(string pName);
	void use();
};

#endif /* ITEM_HPP_ */
