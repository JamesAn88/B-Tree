//
//  IndexNode.cpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#include "IndexNode.hpp"

IndexNode::IndexNode(int order): TreeNode(order){
    m_children = new TreeNode*[order+1];
    for (int i = 0; i < order+1; i++){
        m_children[i] = nullptr;
    }
}

IndexNode::~IndexNode(){
    delete [] m_children;
}

void IndexNode::insert(int key){
    TreeNode * l = search(key);
    l->insert(key);
}

void IndexNode::insert(int key, TreeNode *leftNode, TreeNode *rightNode){
    if (getCount() < getOrder()){
        int index = indexOfKey(key);
        shiftAndInsert(key);
        m_children[index] = leftNode;
        m_children[index+1]=rightNode;
    } else {
        int mid;
        IndexNode *s_node = split(key, leftNode, rightNode, mid);
        TreeNode *p = getParent();
        if (p == nullptr){
            p = new IndexNode(getOrder());
            setParent(p);
        }
        s_node->setParent(p);
        p->insert(mid, this, s_node);
    }
}

TreeNode * IndexNode::search(int key){
    int index = indexOfKey(key);
    return m_children[index]->search(key);
}

void IndexNode::shiftAndInsert(int key){
   
    int index = indexOfKey(key);
    TreeNode::shiftAndInsert(key);
    
    for (int i = getCount() - 1; i > index; i--){
        m_children[i + 1] = m_children[i];
    }
    
}

IndexNode * IndexNode::split(int key, TreeNode *left, TreeNode *right, int &middle){
    assert(getCount() == getOrder());
    
    //merge keys and children together
    int order = getOrder();
    int *merged = new int[order + 1];
    int index = indexOfKey(key);
    int * keys = getKeys();
    TreeNode **mergedNodes = new TreeNode*[order + 2];
    for (int i = 0 ; i < index; i ++){
        merged[i] = keys[i];
        mergedNodes[i] = m_children[i];
    }
    merged[index] = key;
    mergedNodes[index] = left;
    mergedNodes[index+1] = right;
    for (int i = index + 1; i < order + 1; i ++){
        merged[i] = keys[i-1];
        mergedNodes[i+1] = m_children[i];
    }
    int half = (order + 1) / 2;
    //half is returned to be pushed up
    middle = merged[half];
    
    //split keys and children for left node
    for (int i = 0; i < half + 1; i++){
        m_children[i] = mergedNodes[i];
    }
    
    for (int i = half + 1; i < order+1; i++){
        m_children[i] = nullptr;
    }
    
    setCount(half);
    
    //split keys and children for second node
    IndexNode * sibling = new IndexNode(order);
    int * s_keys = sibling->getKeys();
    TreeNode **s_children = sibling->m_children;
    for (int i = half + 1; i < order + 1; i++){
        s_keys[i - (half + 1)] = merged[i];
        s_children[i - (half + 1)] = mergedNodes[i];
        sibling->increment();
    }
    s_children[order + 1 - (half + 1)] = mergedNodes[order+1];
    
    delete[] merged;
    delete mergedNodes;
    return sibling;
}

void IndexNode::traverse(){
    for (int i = 0; i < getCount() + 1; i++){
        m_children[i]->traverse();
    }
}
