#include <vector>
#include "Primes.h"

std::vector<int> *genPrimes(int M)
{
  std::vector<int> *v = new std::vector<int>();

  std::vector<bool> prime(M);

  for (int i = 2; i < M; i++)
  {
    prime[i] = true;
  }

  for (int p = 2; p * p <= M; p++)
  {
    if (prime[p])
    {
      for (int i = p * p; i <= M; i += p)
      {
        prime[i] = false;
      }
    }
  }

  for (int i = 2; i < M; i++)
  {
    if (prime[i])
    {
      v->push_back(i);
    }
  }

  return v;
}
