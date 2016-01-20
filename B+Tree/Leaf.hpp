//
//  Leaf.hpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#ifndef Leaf_hpp
#define Leaf_hpp

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "TreeNode.hpp"
#include "IndexNode.hpp"

class Leaf : public TreeNode {
    Leaf *m_prev;
    Leaf *m_next;
    
    
public:
    Leaf(int order);
    Leaf(int order, Leaf *prev, Leaf *next);
    ~Leaf();
    Leaf * getPrev(){return m_prev;};
    Leaf * getNext(){return m_next;};
    
    void setPrev(Leaf * prev) {m_prev = prev;};
    void setNext(Leaf * next) {m_next = next;};
    void insert(int key);
    TreeNode * search(int key);
    Leaf * split(int key);
    void traverse();
};

#endif /* Leaf_hpp */
