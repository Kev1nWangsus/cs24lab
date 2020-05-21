#include "intstack.h"
#include <iostream>

using namespace std;

Stack::Stack() : next(0) {};

void Stack::push(int n) {
    data[next++] = n;
}

void Stack::pop() {
    if (empty()) return;
    --next;
}

int Stack::top() const {
    if (empty())
        throw string("empty stack");
    return data[next-1];
}

bool Stack::empty() const {
    return next <= 0;
}

bool Stack::full() const {
    return next >= 10;
}