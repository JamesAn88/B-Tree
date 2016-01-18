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

Leaf::~Leaf(){
    delete m_prev;
    delete m_next;
}

void Leaf::insert(int key){
    if (getCount() < getOrder()){
        //just insert
        shiftAndInsert(key);
    } else {
        //split
        Leaf * l = split(key);
        l->setPrev(this);
        setNext(l);
        TreeNode * p = getParent();
        l->setParent(p);
        
        //copy up l->getKeys()[0] to parent
    }
}

TreeNode * Leaf::search(int key){
    return this;
}

Leaf * Leaf::split(int key){
    //split the leaf node caused by insert of key
    assert(getCount() == getOrder());
    int * keys = getKeys();
    
    Leaf * L = new Leaf(getOrder());
    int half = getOrder() / 2;
    for (int i = half; i < getOrder(); i ++){
        L->insert(keys[i]);
    }
    setCount(half);
    int index = indexOfKey(key);
    if (index < half){
        //new key belongs in first node
        shiftAndInsert(key);
    } else {
        L->shiftAndInsert(key);
    }
    
    return L;
}

