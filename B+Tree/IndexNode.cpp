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
}

IndexNode::~IndexNode(){
    delete [] m_children;
}

void IndexNode::insert(int key){
    
}

TreeNode * IndexNode::search(int key){
    int index = indexOfKey(key);
    return m_children[index]->search(key);
}