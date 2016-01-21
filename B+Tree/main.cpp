//
//  main.cpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "BTree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int order = 4;
    BTree t(order);
    for (int i = 0; i<100; i++){
        int inserted = rand() % 10000;
        t.insert(inserted);
    }
    t.traverse();
    return 0;
}
