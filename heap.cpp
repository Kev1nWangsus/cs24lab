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

void swap(int& a, int& b) {
    // std::cout << "Exchanging " << a << " & " << b << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}

int min(int a, int b) {
    if (a <= b) return 1;
    return 2;
}

void Heap::push(int value) {
    // if (vdata.empty()) {
    //     vdata.push_back(value);
    //     return;
    // } else {
    //     int len = vdata.size();
    //     int pos = findPos(vdata, len, value);
    //     vdata.insert(vdata.begin()+pos, value);
    // }
    vdata.push_back(value);
    int i = vdata.size()-1;
    while(i > 0 && vdata[i] < vdata[(i-1)/2]) {
        swap(vdata[i], vdata[(i-1)/2]);
        i = (i-1) / 2;
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    int i = vdata.size()-1;
    swap(vdata[0], vdata[i]);
    vdata.pop_back();
    i = i - 1;
    if (vdata.size() <= 2) {
        if (vdata.size() == 1) return;
        if (vdata[0] > vdata[1]) swap(vdata[0], vdata[1]);
    } else {
        int b = 0;
        int child = min(vdata[1], vdata[2]);
        while ((vdata[b] > vdata[2*b+child]) && b < i) {
            if (2*b+child > i) return;
            else {
                swap(vdata[b], vdata[2*b+child]);
                b = 2*b+child;
                if (2*b+2 > i) child = 1;
                else child = min(vdata[2*b+1], vdata[2*b+2]);
            }
        }
    }
}

// Returns the minimum element in the heap
int Heap::top(){
  	return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.empty();
}
    
