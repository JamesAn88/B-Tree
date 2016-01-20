//
//  main.cpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#include <iostream>
#include "BTree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int order = 6;
    BTree t(order);
    for (int i = 0; i < 100; i++){
        t.insert(99 - i);
    }
    t.traverse();
    return 0;
}
