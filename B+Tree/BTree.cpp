//
//  BTree.cpp
//  B+Tree
//
//  Created by James on 2016-01-17.
//  Copyright © 2016 James. All rights reserved.
//

#include "BTree.hpp"

BTree::BTree(int order){
    m_order = order;
    m_root = nullptr;
}

BTree::~BTree(){
    delete m_root;
}

void BTree::insert(int key){
    if (m_root == nullptr){
        m_root = new Leaf(m_order, nullptr, nullptr);
        m_root->insert(key);
    } else {
        m_root->insert(key);
        if (m_root->getParent() != nullptr){
            m_root = m_root->getParent();
        }
    }
}

TreeNode * BTree::search(int key) {
    if (m_root){
        return m_root->search(key);
    } else {
        return nullptr;
    }
}

void BTree::traverse(){
    m_root->traverse();
}