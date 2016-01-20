//
//  TreeNode.hpp
//  B+Tree
//
//  Created by James on 2016-01-16.
//  Copyright © 2016 James. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <assert.h>

class TreeNode {
    int m_order; //order of the tree/node
    int m_count; //how many entries in the node
    
    TreeNode *m_parent;
    int *m_keys;
    
protected:
    virtual void shiftAndInsert(int key);
    
public:
    TreeNode(int order);
    virtual ~TreeNode();
    int getOrder();
    int getCount();
    void increment();
    void decrement();
    void setCount(int count);
    TreeNode * getParent();
    void setParent(TreeNode *p);
    virtual void insert(int key) = 0;
    virtual TreeNode * search(int key) = 0;
    virtual void insert(int key, TreeNode * oldNode, TreeNode * newNode);
    int indexOfKey(int key);
    int * getKeys();
    virtual void traverse() = 0;
    
};

#endif /* TreeNode_hpp */
