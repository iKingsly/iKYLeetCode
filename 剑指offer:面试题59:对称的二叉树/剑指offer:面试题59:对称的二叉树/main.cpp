//
//  main.cpp
//  剑指offer:面试题59:对称的二叉树
//
//  Created by 郑钦洪 on 16/7/11.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct BinaryTreeNode {
    int m_valuel;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
}BinaryTreeNode;

bool isSymmetrial(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
    if (pRoot1 == NULL && pRoot2 == NULL) {
        return true;
    }
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }
    
    if (pRoot1->m_valuel != pRoot2->m_valuel) {
        return false;
    }
    return isSymmetrial(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrial(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical (BinaryTreeNode *pRoot) {
   return isSymmetrial(pRoot, pRoot);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
