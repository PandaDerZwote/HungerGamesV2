#include "Random.hpp"

bool binaryRandom()
{
	if (rand() % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int setRandom(int pPossibilities)
{
	int ret = 1 + (rand() % pPossibilities);
	return ret;
}
