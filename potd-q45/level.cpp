#include "MinHeap.h"
#include <cmath>

vector<int> lastLevel(MinHeap & heap)
{
        int m = heap.elements.size() - 1;
        int i = std::log2(m);
        i = std::pow(2, i);
        std::vector<int> elem;
        elem.assign(heap.elements.begin() + i, heap.elements.end());
        return elem;
}

