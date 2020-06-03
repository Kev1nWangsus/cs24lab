// intbst.cpp
// Implements class BST
// Shuo Wang 
// 9438425
// 2 Jun 2020

#include <iostream>
using std::cout;

// constructor sets up empty tree
template <class T>
IntBST<T>::IntBST() : root(0) {}

// destructor deletes all nodes
template <class T>
IntBST<T>::~IntBST(){
    clear(root);
}

// recursive helper for destructor
template <class T>
void IntBST<T>::clear(IntBST<T>::Node *n){
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
template <class T>
bool IntBST<T>::insert(T value){
    // handle special case of empty tree first
    if (!root){
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
template <class T>
bool IntBST<T>::insert(T value, Node *n){
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

// prT tree data pre-order
template <class T>
void IntBST<T>::printPreOrder() const
{
    printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T>
void IntBST<T>::printPreOrder(Node *n) const
{
    if (n){
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// prT tree data in-order, with helper
template <class T>
void IntBST<T>::printInOrder() const{
    printInOrder(root);
}
template <class T>
void IntBST<T>::printInOrder(Node *n) const{
    // IMPLEMENT HERE
    if (n) {
        printInOrder(n->left);
        cout << n->info << " ";
        printInOrder(n->right);
    }
}

// prints tree data post-order, with helper
template <class T>
void IntBST<T>::printPostOrder() const{
    printPostOrder(root);
}
template <class T>
void IntBST<T>::printPostOrder(Node *n) const{
    // IMPLEMENT HERE
    if (n) {
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->info << " ";
    }
}

// return sum of values in tree
template <class T>
T IntBST<T>::sum() const{
    return sum(root);
}

// recursive helper for sum
template <class T>
T IntBST<T>::sum(Node *n) const{
    if (n) {
        return n->info + sum(n->left) + sum(n->right);
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// return count of values
template <class T>
int IntBST<T>::count() const{
    return count(root);
}

// recursive helper for count
template <class T>
int IntBST<T>::count(Node *n) const{
    if (n) {
        return 1 + count(n->left) + count(n->right);
    }
    return 0; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// T value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
template <class T>
typename IntBST<T>::Node* IntBST<T>::getNodeFor(T value, Node *n) const{
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
template <class T>
bool IntBST<T>::contains(T value) const{
    if (getNodeFor(value, root))
        return true; 
    return false;
}

// returns the Node containing the predecessor of the given value
template <class T>
typename IntBST<T>::Node* IntBST<T>::getPredecessorNode(T value) const { 
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
template <class T>
T IntBST<T>::getPredecessor(T value) const{
    if (!getPredecessorNode(value)) 
        return 0;
    return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
template <class T>
typename IntBST<T>::Node* IntBST<T>::getSuccessorNode(T value) const {
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
template <class T>
T IntBST<T>::getSuccessor(T value) const {
    if (!getSuccessorNode(value)) 
        return 0;
    return getSuccessorNode(value)->info; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T>
bool IntBST<T>::remove(T value) {
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
        T tmp = getSuccessor(value);
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
