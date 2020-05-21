// intbst.cpp
// Implements class IntBST
// Shuo Wang 
// 9438425
// 2 May 2020

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() : root(0) {}

// destructor deletes all nodes
IntBST::~IntBST(){
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n){
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value){
    // handle special case of empty tree first
    if (!root){
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n){
    if (value == n->info)
        return false;
    if (value < n->info){
        if (n->left){
            return insert(value, n->left);
        }
        else{
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else
    {
        if (n->right){
            return insert(value, n->right);
        }
        else
        {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const
{
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const
{
    if (n){
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void IntBST::printInOrder() const{
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const{
    // IMPLEMENT HERE
    if (n) {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const{
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const{
    // IMPLEMENT HERE
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

// return sum of values in tree
int IntBST::sum() const{
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const{
    if (n) {
        return n->info + sum(n->left) + sum(n->right);
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const{
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const{
    if (n) {
        return 1 + count(n->left) + count(n->right);
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node *IntBST::getNodeFor(int value, Node *n) const{
    if (n) {
        if (n->info == value) {
            return n;
        } else if (n->info > value){
            return getNodeFor(value, n->left);
        } else {
            return getNodeFor(value, n->right);
        }
    }
    return nullptr;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const{
    if (getNodeFor(value, root))
        return true; 
    return false;
}

// returns the Node containing the predecessor of the given value
IntBST::Node *IntBST::getPredecessorNode(int value) const { 
    Node *tmp = getNodeFor(value, root);
    Node *n = root;
    if (tmp->left) {
        tmp = tmp->left;
        while(tmp->right) {
            tmp = tmp->right;
        }
        return tmp;
    } else {
        Node *pre = 0;
        while (tmp != n) {
            if (n->info > value) {
                n = n->left;
            } else {
                pre = n;
                n = n->right;
            }
        }
        return pre;
    }
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if (!getPredecessorNode(value)) 
        return 0;
    return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
IntBST::Node *IntBST::getSuccessorNode(int value) const {
    Node *tmp = getNodeFor(value, root);
    Node *n = root;
    if (tmp->right) {
        tmp = tmp->right;
        while(tmp->left) {
            tmp = tmp->left;
        }
        return tmp;
    } else {
        Node *suc = 0;
        while (tmp != n) {
            if (n->info > value) {
                suc = n;
                n = n->left;
            } else {
                n = n->right;
            }
        }
        return suc;
    }
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const {
    if (!getSuccessorNode(value)) 
        return 0;
    return getSuccessorNode(value)->info; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value) {
    // check if this node exists
    if (!contains(value)) return false;

    Node *n = getNodeFor(value, root);
    // Case 1: Leaf node
    if (!(n->left) && !(n->right)) {
        // check if it is a root
        if (n != root) {
            if (n->parent->left == n) {
                n->parent->left = 0;
            } else {
                n->parent->right = 0;
            }
        } else {
            root = 0;
        }
        delete n;
    } 
    // Case 2: Node with two children
    else if (n->left && n->right) {
        int tmp = getSuccessor(value);
        remove(tmp); // recursively check its successor once
                     // since its successor won't have any left subtree
        n->info = tmp;
    }
    // Case 3: Node with only one child
    else {
        // if it has left child
        if (n->left) {
            if (n != root) {
                if (n->parent->left == n) {
                    n->parent->left = n->left;
                } else {
                    n->parent->right = n->left;
                }
            } else {
                root = n->left;
            }
        }
        // if it has right child 
        else {
            if (n != root) {
                if (n->parent->left == n) {
                    n->parent->left = n->right;
                } else {
                    n->parent->right = n->right;
                }
            } else {
                root = n->right;
            }
        }
        delete n;
    }
    return true;
}
