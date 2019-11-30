#include "simplerand.h"

// Initialize seed from std::random_device
std::mt19937 SimpleRand::randGen((std::random_device())());

double SimpleRand::rand()
{
	//std::uniform_int_distribution<unsigned> rand(0, i);
	std::uniform_real_distribution<double> randDist;
	return randDist(randGen);
}

int SimpleRand::randRange( int s, int e)
{
	std::uniform_int_distribution<int> randDist(s, e);
	return randDist(randGen);
}
