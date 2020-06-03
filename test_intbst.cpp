// test_intbst.cpp
// Shuo Wang
// 9438425
// 2 May 2020

#include "intbst.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void testAll();
void testSum();
void testCount();
void testContain();
void testRemove();
void testPredecessor();
void testSuccessor();

void testSum_1();
void testSum_2();
void testSum_3();

void testCount_1();
void testCount_2();
void testCount_3();

void testContain_1();
void testContain_2();
void testContain_3();

void testRemove_1();
void testRemove_2();
void testRemove_3();

void testPredecessor_1();
void testPredecessor_2();

void testSuccessor_1();
void testSuccessor_2();

void AssertEqual(int exp, int act, string testname);
void AssertEqual(bool exp, bool act, string testname);
bool Assert (bool exp, bool act, string testname);

int main(){
	testAll();
	return 0;
}

void testAll(){
    testSum();
    testCount();
    testContain();
    testRemove();
    testPredecessor();
    testSuccessor();
	return;
}

void testSum(){
	testSum_1();
	testSum_2();
	testSum_3();
}

void testCount(){
	testCount_1();
	testCount_2();
	testCount_3();
}

void testContain(){
	testContain_1();
	testContain_2();
	testContain_3();
}

void testRemove(){
	testRemove_1();
	testRemove_2();
	testRemove_3();
}

void testPredecessor(){
    testPredecessor_1();
    testPredecessor_2();
}

void testSuccessor(){
    testSuccessor_1();
    testSuccessor_2();
}



void testSum_1(){
	string testname = "testSum_Case_1: Empty tree";
	BST<int> bst;
	AssertEqual(0, bst.sum(), testname);
}

void testSum_2(){
	string testname = "testSum_Case_2: Root tree";
	BST<int> bst;
	bst.insert(16);
	AssertEqual(16, bst.sum(), testname);
}

void testSum_3(){
	string testname = "testSum_Case_3: Normal tree";
	BST<int> bst;
	bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
	AssertEqual(176, bst.sum(), testname);
}

void testCount_1(){
	string testname = "testCount_Case_1: Empty tree";
	BST<int> bst;
	AssertEqual(0, bst.count(), testname);
}

void testCount_2(){
	string testname = "testCount_Case_2: Root tree";
	BST<int> bst;
	bst.insert(16);
	AssertEqual(1, bst.count(), testname);
}

void testCount_3(){
	string testname = "testCount_Case_3: Normal tree";
	BST<int> bst;
	bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
	AssertEqual(5, bst.count(), testname);
}

void testContain_1(){
	string testname = "testContain_Case_1: Empty tree";
	BST<int> bst;
	AssertEqual(false, bst.contains(0), testname);
}

void testContain_2(){
	string testname = "testContain_Case_2: Root tree";
	BST<int> bst;
	bst.insert(16);
	AssertEqual(true, bst.contains(16), testname);
}
void testContain_3(){
	string testname_1 = "testContain_Case_3_1: Normal tree (contains)";
    string testname_2 = "testContain_Case_3_2: Normal tree (not contains)";
	BST<int> bst;
	bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
	AssertEqual(true, bst.contains(24), testname_1);
    AssertEqual(false, bst.contains(63), testname_2);
}

void testRemove_1(){
	string testname = "testRemove_Case_1: Empty tree";
	BST<int> bst;
	AssertEqual(false, bst.remove(2), testname);
}

void testRemove_2(){
	string testname_1 = "testRemove_Case_2_1: Root tree (remove element)";
    string testname_2 = "testRemove_Case_2_2: Root tree (not contains after remove)";
	BST<int> bst;
	bst.insert(16);
    AssertEqual(true, bst.remove(16), testname_1);
	AssertEqual(false, bst.contains(16), testname_2);
}

void testRemove_3(){
	string testname_1 = "testRemove_Case_3_1: Normal tree (remove element)";
    string testname_2 = "testRemove_Case_3_2: Normal tree (remove non-element)";
    string testname_3 = "testRemove_Case_3_3: Normal tree (not contains after remove)";
	BST<int> bst;
	bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
    AssertEqual(true, bst.remove(32), testname_1);
    AssertEqual(false, bst.remove(8), testname_2);
	AssertEqual(false, bst.contains(32), testname_3);
}

void testPredecessor_1(){
    string testname = "testPredecessor_Case_1: Root tree";
    BST<int> bst;
    bst.insert(16);
    AssertEqual(0, bst.getPredecessor(16), testname);
}

void testPredecessor_2(){
    string testname = "testPredecessor_Case_2: Normal tree";
    BST<int> bst;
    bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
    AssertEqual(24, bst.getPredecessor(32), testname);
}

void testSuccessor_1(){
    string testname = "testSuccessor_Case_1: Root tree";
    BST<int> bst;
    bst.insert(16);
    AssertEqual(0, bst.getSuccessor(16), testname);
}

void testSuccessor_2(){
    string testname = "testSuccessor_Case_2: Normal tree";
    BST<int> bst;
    bst.insert(16);
	bst.insert(24);
	bst.insert(64);
	bst.insert(32);
	bst.insert(40);
    AssertEqual(40, bst.getSuccessor(32), testname);
}

void AssertEqual(int exp, int act, string test){
	if (exp == act){
		cout << " Passed " << test<< endl;
	}
	else{
		cout << "*Failed " << test<< endl;
	}
}

void AssertEqual(bool exp, bool act, string test){
	if (exp == act){
		cout << " Passed " << test<<endl;
	}
	else{
		cout << "*Failed " << test<<endl;
	}
}