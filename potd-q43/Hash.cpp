#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    std::vector<int>* array = new std::vector<int>(M);	// Hint: This comes in handy
	int permutation_count = 0;	
	float goodness = 0;

	std::vector<int> &arr_ref = *array;

	for(int i = 0; i < M; i++)
	{
		arr_ref[i] = -1;
	}

	do {
		if (permutation_count++ == M) break;
		int idx = bernstein(str, M);		
		arr_ref[idx]++;
	} while(std::next_permutation(str.begin(), str.end()));

	int collisions = 0;
	
	for(int i = 0; i < M; i++)
	{
		if(arr_ref[i] > 0)
		{
			collisions += arr_ref[i];
		}
	}
	
	// std::cout << "collisions(" << M << "): " << collisions << std::endl;

	delete array;

	goodness = (float)collisions/(float)M;

	return goodness;
}

