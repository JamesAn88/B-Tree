//
//  Leaf.cpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#include "Leaf.hpp"

Leaf::Leaf(int order): TreeNode(order){
    
}

Leaf::Leaf(int order, Leaf *prev, Leaf *next): TreeNode(order){
    m_prev = prev;
    m_next = next;
}

