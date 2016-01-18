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

void TreeNode::increment(){
    m_count++;
}

void TreeNode::decrement(){
    m_count--;
}

TreeNode * TreeNode::getParent(){
    return m_parent;
}

void TreeNode::setParent(TreeNode *p){
    m_parent = p;
}

int TreeNode::indexOfKey(int key){
    int i = 0;
    while (i <= m_count && m_keys[i] < key) {
        i++;
    }
    return i;
}