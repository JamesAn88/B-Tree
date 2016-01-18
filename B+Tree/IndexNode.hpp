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
#include "TreeNode.hpp"

class IndexNode : public TreeNode {
    TreeNode **m_children;
    
public:
    IndexNode(int order);
    ~IndexNode();
    void insert(int key);
    TreeNode * search(int key);
    
};

#endif /* IndexNode_hpp */
