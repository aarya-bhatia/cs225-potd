// Your code here
#include "potd.h"

static const string map[] = {
    "As you wish!",
    "Nec spe nec metu!", "Do, or do not. There is no try.", "This fortune intentionally left blank.", "Amor Fati!"};

static unsigned n = 5;

string getFortune(const string &s)
{
    unsigned index = s.length() % n;
    return map[index];
}kj