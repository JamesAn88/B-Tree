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

class TreeNode {
    int m_order; //order of the tree/node
    int m_count; //how many entries in the node
    
    TreeNode *m_parent;
    int *m_keys;
    
public:
    TreeNode(int order);
    virtual ~TreeNode();
    int getOrder();
    void increment();
    void decrement();
    TreeNode * getParent();
    void setParent(TreeNode *p);
    virtual void insert(int key) = 0;
    virtual TreeNode * search(int key) = 0;
    int indexOfKey(int key);
    
};

#endif /* TreeNode_hpp */
