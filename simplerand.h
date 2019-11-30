#pragma once
#include <random>

class SimpleRand
	// Probably not thread safe
{
public:
	double rand();
	int randRange(int s, int e);
private:
	static std::mt19937 randGen;
};

