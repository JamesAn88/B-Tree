//
//  IndexNode.hpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#ifndef IndexNode_hpp
#define IndexNode_hpp

#include <stdio.h>
#include <assert.h>
#include "TreeNode.hpp"

class IndexNode : public TreeNode {
    TreeNode **m_children;
    
protected:
    virtual void shiftAndInsert(int key);
    
public:
    IndexNode(int order);
    ~IndexNode();
    TreeNode * search(int key);
    virtual void insert(int key);
    virtual void insert(int key, TreeNode *oldNode, TreeNode *newNode);
    IndexNode * split(int key, TreeNode *left, TreeNode *right, int &middle);
    void traverse();
};

#endif /* IndexNode_hpp */
