// Fisher-Yates-shuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <algorithm>
#include "simplerand.h"

using namespace std;

/*
for i from n−1 downto 1 do
	 j ← random integer such that 0 ≤ j ≤ i
	 exchange a[j] and a[i]
*/

template<class T> void shuffle(T &d)
{
	SimpleRand rand;
	for ( auto i = d.size() - 1; i >= 1; --i)
	{
		auto j = rand.randRange(0, i);
		//cout << "i: " << i << "; j: " << j << endl;
		auto temp = d[i];
		d[i] = d[j];
		d[j] = temp;
	}
}

int main()
{
	std::array<int, 52> d; // Sorted deck of 52 cards
	int i = 1;
	std::generate(d.begin(), d.end(), [&i]() { return i++; });
	shuffle( d);

	// Double check algorithm is sane
	for (auto i = 1; i <= 52; ++i)
	{
		bool found = false;
		for (auto j = 0; j < 52; ++j)
		{
			if (d[j] == i)
				found = true;
		}
		if (found == false)
		{
			cout << "ERROR\n";
		}
	}
}
