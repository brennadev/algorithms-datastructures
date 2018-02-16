//
//  main.cpp
//  Selection
//
//  Created by Brenna Olson on 10/12/17.
//  Copyright © 2017 Brenna Olson. All rights reserved.
//
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

int select(vector<int> v, int firstElementIndex, int lastElementIndex, int ithSmallest);
int partition(vector<int> &v, int firstElementIndex, int lastElementIndex);
void vectorElementSwap(vector<int> &v, int element1Index, int element2Index);

int main(int argc, const char * argv[]) {
    vector<int> numbers;
    
    // prepare input file
    ifstream infile;
    infile.open(argv[1]);
    
    if (infile.fail()) {
        cout << "ERROR: cannot open file!\n";
        return 0;
    }
    
    // prepare output file
    ofstream outfile;
    outfile.open("output.txt");
    
    if (!outfile) {
        cerr << "Unable to open output file - terminating program" << endl;
        exit(0);
    }
    
    // to know the value you need to get
    int ithSmallest;
    infile >> ithSmallest;
    
    // get all numbers
    int currentNumber;
    while (infile >> currentNumber) {
        numbers.push_back(currentNumber);
    }
    
    // store the value
    int value = select(numbers, 0, numbers.size() - 1, ithSmallest);
    outfile << value << endl;
    
    infile.close();
    outfile.close();
    
    return 0;
}

int select(vector<int> v, int firstElementIndex, int lastElementIndex, int ithSmallest) {
    // base case - only 1 element
    if (firstElementIndex == lastElementIndex) {
        return v.at(firstElementIndex);
    }
    
    int pivotLocation = partition(v, firstElementIndex, lastElementIndex);
    int numberOfElementsLowSide = pivotLocation - firstElementIndex;
    
    // ith smallest is the pivot
    if (ithSmallest == numberOfElementsLowSide/*pivotLocation*/ + 1) {
        return v.at(pivotLocation);
    } else if (ithSmallest < numberOfElementsLowSide + 1) {
        return select(v, firstElementIndex, pivotLocation - 1, ithSmallest);
    } else {
        return select(v, pivotLocation + 1, lastElementIndex, ithSmallest - numberOfElementsLowSide);
    }
}

int partition(vector<int> &v, int firstElementIndex, int lastElementIndex) {
    int pivotValue = v.at(lastElementIndex);
    int lastLessThanIndex = firstElementIndex - 1;
    
    for(int j = firstElementIndex; j < lastElementIndex; j++) {
        // when current element is less than the pivot
        if (v.at(j) <= pivotValue) {
            // create new location for pivot
            lastLessThanIndex++;
            // swap the current element with the one in the newly created last position for <= values
            vectorElementSwap(v, lastLessThanIndex, j);
        }
    }
    
    // get pivot in correct position
    vectorElementSwap(v, lastLessThanIndex + 1, lastElementIndex);
    return lastLessThanIndex + 1; // pivot index
}

// swap 2 elements contained in the same vector
void vectorElementSwap(vector<int> &v, int element1Index, int element2Index) {
    int toSwap = *(v.begin() + element1Index);
    *(v.begin() + element1Index) = *(v.begin() + element2Index);
    *(v.begin() + element2Index) = toSwap;
}
