// heap.cpp
// Shuo Wang
// 9438425
// 30 May 2020

#include "heap.h"
#include <iostream>
#include <algorithm>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    sort(vdata.begin(), vdata.end());
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
    
