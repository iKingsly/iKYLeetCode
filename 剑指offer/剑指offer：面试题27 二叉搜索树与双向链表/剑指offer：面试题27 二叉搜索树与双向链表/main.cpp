//
//  main.cpp
//  剑指offer：面试题27 二叉搜索树与双向链表
//
//  Created by 郑钦洪 on 16/6/15.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void ConvertNode (BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList) {
    if (pNode == NULL) {
        return;
    }
    BinaryTreeNode *pCurrent = pNode;
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList) {
        (*pLastNodeInList)->m_pRight = pCurrent;
    }
    
    *pLastNodeInList = pCurrent;
    
    if (pCurrent->m_pRight != NULL) {
        ConvertNode(pCurrent->m_pRight,pLastNodeInList);
    }
}
BinaryTreeNode * Convert (BinaryTreeNode * pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = NULL;
    ConvertNode(pRootOfTree, &pLastNodeInList);
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    
    while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL) {
        pHeadOfList = pHeadOfList->m_pLeft;
    }
    return pHeadOfList;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
