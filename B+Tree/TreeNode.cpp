//
//  TreeNode.cpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#include "TreeNode.hpp"

TreeNode::TreeNode(int order){
    m_parent = nullptr;
    m_order = order;
    m_keys = new int[m_order];
}

TreeNode::~TreeNode(){
    delete m_parent;
    delete[] m_keys;
}

int TreeNode::getOrder(){
    return m_order;
}

int TreeNode::getCount(){
    return m_count;
}

void TreeNode::increment(){
    m_count++;
}

void TreeNode::decrement(){
    m_count--;
}

void TreeNode::setCount(int count){
    m_count = count;
}

TreeNode * TreeNode::getParent(){
    return m_parent;
}

void TreeNode::setParent(TreeNode *p){
    m_parent = p;
}

int TreeNode::indexOfKey(int key){
    int i = 0;
    while (i < m_count && m_keys[i] < key) {
        i++;
    }
    return i;
}

int * TreeNode::getKeys(){
    return m_keys;
}

void TreeNode::shiftAndInsert(int key){
    assert(m_count < m_order);
    int index = indexOfKey(key);
    for (int i = m_count - 1; i >= index; i--){
        m_keys[i+1] = m_keys[i];
    }
    m_keys[index] = key;
    increment();
    return;
    
}