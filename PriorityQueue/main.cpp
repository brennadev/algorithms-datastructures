//
//  main.cpp
//  PriorityQueue
//
//  Created by Brenna Olson on 10/9/17.
//  Copyright © 2017 Brenna Olson. All rights reserved.
//
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <string>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

int main(int argc, const char * argv[]) {
    PriorityQueue queue = PriorityQueue();
    
    // prepare input file
    ifstream infile;
    infile.open(argv[1]);
    
    if (infile.fail()) {
        cout << "ERROR: cannot open input file!\n";
        return 0;
    }
    
    // prepare output file
    ofstream outfile;
    outfile.open("output.txt");
    
    if (!outfile) {
        cout << "ERROR: cannot open output file!\n";
        return 0;
    }
    
    // input from file into priority queue
    string inputCustomer;
    int inputPriority;
    
    while(infile >> inputCustomer) {
        infile.ignore(3);
        infile >> inputPriority;
        Customer x = {inputCustomer, inputPriority};
        queue.insert(x);
    }
    
    // put output into output file
    while (queue.getHeap().size() > 0) {
        outfile << queue.extractMax().name;
        // put a space after the element only if it isn't the last
        if (queue.getHeap().size() > 0) {
            outfile << ' ';
        }
    }
    
    infile.close();
    outfile.close();

    return 0;
}

