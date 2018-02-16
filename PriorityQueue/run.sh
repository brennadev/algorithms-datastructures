#!/bin/sh

#  run.sh
#  PriorityQueue
#
#  Created by Brenna Olson on 10/14/17.
#  Copyright © 2017 Brenna Olson. All rights reserved.
#
#  REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.

g++ main.cpp PriorityQueue.h PriorityQueue.cpp Customer.cpp
./a.out $1
