//
//  Customer.cpp
//  PriorityQueue
//
//  Created by Brenna Olson on 10/11/17.
//  Copyright © 2017 Brenna Olson. All rights reserved.
//
// REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

#include <iostream>
#include <string>
using namespace std;

// Represents a person waiting in line
struct Customer {
    string name; // name of the person
    int priority; // priority in the queue
};
