#include "potd.h"

double sum(vector<double>::iterator start, vector<double>::iterator end)
{
  double total = 0;

  for(vector<double>::iterator itr = start; itr != end; itr++)
  {
    total += *itr; 
  }

  return total;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end)
{ 
  double max = -9999;
  vector<double>::iterator max_it = start;

  for(vector<double>::iterator itr = start; itr != end; itr++)
  {
    if(*itr > max) {
      max = *itr;
      max_it = itr;
    }
  }

  return max_it;
}

void swap(vector<double>::iterator i, vector<double>::iterator j)
{
  double tmp = *i;
  *i = *j;
  *j = tmp;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end)
{
  for(vector<double>::iterator itr = start; itr != end-1; itr++)
  {
    swap(max_iter(itr,end),itr);
  }
}
