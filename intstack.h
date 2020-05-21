// intstack.h - stack class for CS 24 lab practice

// The class is implemented here too. All very bare bones,
// with no error-checking nor even pre-condition stating.
// But know two things: (1) don't push on full stack, which
// is a stack currently holding 10 ints; (2) don't pop or
// top from empty stack - use bool empty() to check.

#ifndef INTSTACK_H
#define INTSTACK_H

#define CAPACITY 10

class Stack {

public:
    Stack();
    void push(int n);
    void pop();
    int top() const;
    bool empty() const;
    bool full() const;
private:
    int next, data[CAPACITY];
};

#endif
