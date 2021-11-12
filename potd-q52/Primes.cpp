#include <vector>
#include <iostream>
#include "Primes.h"

std::vector<int> *genPrimes(int M) 
{
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> *t = new std::vector<int>(M);
    int i=0;
    int nextPrime = 2;

    for(i=0; i<M; i++)
        (*t)[i] = 1;

    (*t)[0]=0;
    (*t)[1]=0;

    v->push_back(2);

    while (nextPrime < M) {
        for(i=nextPrime*nextPrime;
                i < M;
                i+=nextPrime)
            (*t)[i] = 0;
        for(++nextPrime; nextPrime<M; nextPrime++)
            if ((*t)[nextPrime] == 1) {
                v->push_back(nextPrime);
                break;
            }
    }

    delete t;
    return v;
}

int numSequences(std::vector<int> *primes, int num) 
{
  int count = 0;

  static std::vector<int> sums;
  static bool init = false;

  if(!init)
  {
    init = true;
    sums.reserve(primes->size());

    int sum = 0;

    for(size_t i = 0; i < primes->size(); i++)
    {
      sum += primes->at(i);
      sums[i] = sum;
      //std::cout << sums[i] << std::endl;
    }
  }

  size_t start = 0;

  while(start < primes->size() && primes->at(start) <= num)
  {

    if(sums[start] == num) count++;

    size_t end = start + 1;

    while(end < primes->size() && sums[end] - sums[start] <= num)
    {
      if(sums[end]-sums[start] == num)
      {
        count++;
        break;
      }

      end++;
    }

    start++;
  }

  return count;
}
