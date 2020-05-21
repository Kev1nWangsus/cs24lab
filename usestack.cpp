// usestack.cpp - for CS 24 lab practice using stacks
// Shuo Wang
// 21 May 2020

#include "intstack.h"
#include <iostream>
using namespace std;

// evaluating "5 2 1 * +"
int main() {
    Stack numbers;

    numbers.push(5);
    numbers.push(2);
    numbers.push(1);

    // fourth token is *
    int right = numbers.top();
    numbers.pop();
    int left = numbers.top();
    numbers.pop();
    numbers.push(left * right);

    // last token is +
    right = numbers.top();
    numbers.pop();
    left = numbers.top();
    numbers.pop();
    numbers.push(left + right);


    cout << numbers.top() << endl;

    // testing top()
    numbers.pop();
    try {
        int result = numbers.top();
        cout << "result: " << result << endl;
    }
    catch(string error) {
        cerr << "Error: " << error << endl;
        return 1;
    }

    return 0;
}
