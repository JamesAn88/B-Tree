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
        if (p == nullptr){
            p = new IndexNode(getOrder());
            setParent(p);
        }
        l->setParent(p);
        
        //copy up l->getKeys()[0] to parent along with l
        p->insert(l->getKeys()[0], this, l);
    }
}

TreeNode * Leaf::search(int key){
    return this;
}

Leaf * Leaf::split(int key){
    //split the leaf node caused by insert of key
    assert(getCount() == getOrder());
    int * keys = getKeys();
    int order = getOrder();
    int * merged = new int[order + 1];
    int index = indexOfKey(key);
    
    for(int i = 0; i < index; i++){
        merged[i] = keys[i];
    }
    merged[index] = key;
    
    for (int i = index + 1; i < order + 1; i++){
        merged[i] = keys[i - 1];
    }
    
    Leaf * L = new Leaf(order);
    int half = (order + 1) / 2;
    setCount(half);
    
    for (int i = 0; i < half; i++){
        keys[i] = merged[i];
    }
    
    int * newNodeKeys = L->getKeys();
    for (int i = half; i < order+1; i++){
        newNodeKeys[i - half] = merged[i];
        L->increment();
    }
    delete[] merged;
    return L;
}

void Leaf::traverse(){
    int * keys = getKeys();
    for (int i = 0 ; i < getCount(); i++){
        std::cout << keys[i] << " ";
    }
}

