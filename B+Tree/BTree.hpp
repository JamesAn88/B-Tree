//
//  BTree.hpp
//  B+Tree
//
//  Created by James on 2016-01-17.
//  Copyright © 2016 James. All rights reserved.
//

#ifndef BTree_hpp
#define BTree_hpp

#include <stdio.h>
#include <assert.h>
#include "TreeNode.hpp"
#include "IndexNode.hpp"
#include "Leaf.hpp"

class BTree {
    TreeNode *m_root;
    int m_order;
    
public:
    BTree(int order);
    ~BTree();
    void insert(int key);
    void remove(int key);
    TreeNode * search(int key); //get the leaf node the key should belong in
    
};
#endif /* BTree_hpp */
