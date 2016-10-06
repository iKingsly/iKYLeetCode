//
//  main.cpp
//  剑指offer:面试题63:二叉搜索树的第k个结点
//
//  Created by 郑钦洪 on 16/7/13.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct BinaryTreeNode {
    int m_data;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}BinaryTreeNode;

BinaryTreeNode * KthNodeCore(BinaryTreeNode *pRoot, unsigned int &k) {
    BinaryTreeNode *target = NULL;
    
    if (pRoot->m_pLeft != NULL) {
        target = KthNodeCore(pRoot->m_pLeft,k);
    }
    if (target == NULL) {
        if (k == 1) {
            target = pRoot;
        }
        k--;
    }
    
    if (target == NULL && pRoot->m_pRight != NULL) {
        target = KthNodeCore(pRoot->m_pRight,k);
    }
    return target;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
