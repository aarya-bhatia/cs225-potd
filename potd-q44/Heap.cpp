#include "Heap.h"
#include <iostream>

void Heap::_percolateDown(int hole) {
    while(hole > 0 && hole < _data.size())
    {
        int leftIdx = 2 * hole;
        int rightIdx = 2 * hole + 1;
        int maxIdx = -1;
        int maxElement = _data[hole];

        if(leftIdx < _data.size())
        {
            if(maxElement < _data[leftIdx])
            {
                maxElement = _data[leftIdx];
                maxIdx = leftIdx;
            }
        }

        if(rightIdx < _data.size())
        {
            if(maxElement < _data[rightIdx])
            {
                maxElement = _data[rightIdx];
                maxIdx = rightIdx;
            }
        }

        if(maxIdx > 0)
        {
            std::swap(_data[hole], _data[maxIdx]);
        }

        hole = maxIdx;
    }
}

int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
