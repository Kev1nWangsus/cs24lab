// usestack.cpp - for CS 24 lab practice using stacks
// Shuo Wang
// 21 May 2020

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
