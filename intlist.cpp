// intlist.cpp
// Implements class IntList
// Shuo Wang    16 April 2020

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if (!source.first) return;

    Node* tmp = source.first;

    first = new Node;
    first->info = tmp->info;
    first->next = 0;

    tmp = tmp->next;
    while (tmp) {
        append(tmp->info);
        tmp = tmp->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *n = first;
    while (n) {
        n = n->next;
        delete first;
        first = n;
    }
}


// return sum of values in list
int IntList::sum() const {
    int result = 0;
    Node *n = first;
    while (n) {
        result += n->info;
        n = n->next;
    }
    return result;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n) {
        if (n->info == value) {
            return true;
        }
        n = n->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node *n = first;
    int result = 0;
    while (n) {
        if (n->info > result) {
            result = n->info;
        }
        n = n->next;
    }
    return result; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!first) return 0;
    double totalSum = sum();
    double totalCount = count();
    return totalSum / totalCount;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    if (!first) {
        first = new Node;
        first->info = value;
        first->next = 0;
    } else {
        Node *newfirst = new Node{value, first};
        first = newfirst;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    this->~IntList();

    Node* tmp = source.first;
    while (tmp) {
        append(tmp->info);
        tmp = tmp->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
