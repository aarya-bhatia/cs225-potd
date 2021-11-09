#include "Friend.h"
#include <iostream>

int find(int x, std::vector<int>& parents) {
   if(parents[x] == -1) return x;
   parents[x] = find(parents[x], parents);
   return parents[x];
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    std::vector<int> parents(M.size());

    // init set
    for(size_t i = 0; i < parents.size(); i++)
    {
      parents[i] = -1;
    }

    // build disjoint set
    for(size_t i = 0; i < M.size(); i++)
    {
      for(size_t j = 0; j < M[i].size(); j++)
      {
        if(M[i][j])
        {
          if(find(i, parents) != find(j, parents)) {
            parents[i] = j;
          }
        }
      }
    }

    for(size_t i = 0; i < parents.size(); i++)
    {
      std::cout << parents[i] << " ";
    }

    std::cout << std::endl;

    // calculate number of friend circles
    // i.e. returns number of sets

    int c = 0;

    for(size_t i = 0; i < parents.size(); i++)
    {
      if(parents[i] <= 0) c++;
    }

    return c;
}


