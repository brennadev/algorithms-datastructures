//
//  PriorityQueue.h
//  PriorityQueue
//
//  Created by Brenna Olson on 10/11/17.
//  Copyright © 2017 Brenna Olson. All rights reserved.
//
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <vector>
#include <math.h>
#include "Customer.cpp"
using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

class PriorityQueue {
private:
    // where the priorities and elements in the priority queue are stored
    vector<Customer> heap;
    
    void increaseKey(int index, Customer key);
    void maxHeapify(int index);
    
    // get vector index of left child
    int left(int index) {
        return 2 * index + 1;
    }
    
    // get vector index of right child
    int right(int index) {
        return 2 * index + 2;
    }
    
    // get vector index of parent
    int parent(int index) {
        return static_cast<int>(floor((index + 1) / 2.0) - 1);
    }
    
    // helper to swap vector elements
    void vectorElementSwap(vector<int> &v, int element1Index, int element2Index);
public:
    void insert(Customer element);
    Customer maximum();
    Customer extractMax();
    
    vector<Customer> getHeap() {
        return heap;
    }
};


#endif
