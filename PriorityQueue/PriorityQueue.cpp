//
//  PriorityQueue.cpp
//  PriorityQueue
//
//  Created by Brenna Olson on 10/11/17.
//  Copyright © 2017 Brenna Olson. All rights reserved.
//
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <cstdlib>
#include "PriorityQueue.h"
using namespace std;


void PriorityQueue::increaseKey(int index, Customer key) {
    if (key.priority < heap.at(index).priority) {
        cerr << "New key is smaller than current key" << endl;
        exit(3);
    }
    
    // make sure the current index's priority is set to the key's priority
    heap.at(index).priority = key.priority;
    
    // swap the new element with its parent(s) if greater than its parent(s)
    while (heap.size() > 1 && index > 0 && heap.at(parent(index)).priority < heap.at(index).priority) {
        Customer swap = heap.at(index);
        heap.at(index) = heap.at(parent(index));
        heap.at(parent(index)) = swap;
        index = parent(index);
    }
}

void PriorityQueue::maxHeapify(int index) {
    // children of the index passed in
    int leftChild = left(index);
    int rightChild = right(index);
    int largest;
    
    // determine largest value
    if (leftChild < heap.size() && heap.at(leftChild).priority > heap.at(index).priority) {
        largest = leftChild;
    } else {
        largest = index;
    }
    
    if (rightChild < heap.size() && heap.at(rightChild).priority > heap.at(largest).priority) {
        largest = rightChild;
    }
    
    if (largest != index) {
        // swap the current element with the largest
        Customer currentIndex = heap.at(index);
        heap.at(index) = heap.at(largest);
        heap.at(largest) = currentIndex;
        
        maxHeapify(largest);
    }
}


void PriorityQueue::insert(Customer element) {
    heap.push_back(element);
    increaseKey(heap.size() - 1, element);
}

Customer PriorityQueue::maximum() {
    return heap.at(0);
}

Customer PriorityQueue::extractMax() {
    if (heap.size() < 1) {
        cerr << "Heap underflow" << endl;
        exit(4);
    }
    
    Customer max = maximum();
    heap.at(0) = heap.at(heap.size() - 1);
    
    // remove last element (that's set to the max value) from the heap
    heap.pop_back();
    maxHeapify(0);
    
    return max;
}


