// heap.cpp
// Shuo Wang
// 9438425
// 30 May 2020

#include "heap.h"
#include <vector>
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged

int findPos(std::vector<int>& v1, int length, int value) {
    int begin = 0; 
    int end = length;
    int mid;
    while (begin < end) {
        mid = (begin + end) / 2;
        if (value > v1[mid]) {
            begin = mid + 1;
        }
        else if (value < v1[mid]) {
            end = mid;
        }
        else {
            return mid;
        }
    }
    return begin;
}

void Heap::push(int value) {
    if (vdata.empty()) {
        vdata.push_back(value);
        return;
    } else {
        int len = vdata.size();
        int pos = findPos(vdata, len, value);
        vdata.insert(vdata.begin()+pos, value);
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    vdata.erase(vdata.begin());
}

// Returns the minimum element in the heap
int Heap::top(){
  	return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.empty();
}
    
