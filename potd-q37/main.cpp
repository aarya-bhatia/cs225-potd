#include "functions.h"
#include <iostream>
#include <assert.h>
#include <cmath>

#include "../acutest.hpp"

bool isPrime(unsigned n) {
  if(n < 2) { return false; }
  if(n == 2) { return true; }
  for(unsigned i = 2; i < n; i++)
  {
    if(n % i == 0) {
      return false;
    }
  }

  return true;
}

void testValidUsername()
{
  TEST_CHECK(validUsername("f_jlhf@#1A")); // Correct
  TEST_CHECK(validUsername("f8j")); // Correct
  TEST_CHECK(validUsername("777")); // Correct
  TEST_CHECK(!validUsername("fijj")); // Does not have 1 number
  TEST_CHECK(!validUsername("fj")); // Too short
}

void testIsPrime()
{
  unsigned c = 0;
  for (unsigned i = 0; i <= 50; i++)
  {
    if (isPrime(i))
    {
      c++;
    }
  }
  TEST_CHECK(countPrimes(50) == c);
}

void testFactorial()
{
  TEST_CHECK(factorial(5) == 5 * 4 * 3 * 2 * 1);
  TEST_CHECK(factorial(0) == 1);
  TEST_CHECK(factorial(1) == 1);
}

void testSamesies()
{
  TEST_CHECK(samesies(5, 5));
  TEST_CHECK(samesies(-1, -1));
  TEST_CHECK(!samesies(0, 5));
  TEST_CHECK(samesies(99999, 99999));
}

void testAbsolutely()
{
  TEST_CHECK(absolutely(-99999) == 99999);
  TEST_CHECK(absolutely(99999) == 99999);
}

void testMagnaCalca()
{
  TEST_CHECK(magnaCalca(-50, 50) == 50 + 50);
  TEST_CHECK(magnaCalca(20, 30) == 10);
}

TEST_LIST = {
  {"test valid username", testValidUsername},
  {"test is prime", testIsPrime},
  {"test factorial", testFactorial},
  {"test samesies", testSamesies},
  {"test absolutely", testAbsolutely},
  {"test magna calca", testMagnaCalca},
  {0, 0}
};