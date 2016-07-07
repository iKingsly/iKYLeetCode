//
//  main.cpp
//  剑指offer:面试题58:二叉树的下一个节点
//
//  Created by 郑钦洪 on 16/7/7.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct BinaryTreeNode{
    int data;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
    BinaryTreeNode *pParent;
} BinaryTreeNode;

BinaryTreeNode *GetNext(BinaryTreeNode *pNode) {
    if (pNode == NULL) {
        return NULL;
    }
    
    BinaryTreeNode *pNext = NULL;
    // 如果有右子树则遍历右子树的左节点
    if (pNode->pRight != NULL) {
        BinaryTreeNode *pRight = pNode->pRight;
        while (pRight->pLeft != NULL) {
            pRight = pRight->pLeft;
        }
        pNext = pRight;
    } else if(pNode->pParent != NULL) { // 如果有父节点
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->pParent;
        while (pParent != NULL && pCurrent == pParent->pRight) { // 一直便利 直到找到当前的点为左子树 或者为根节点
            pCurrent = pParent;
            pParent = pParent->pParent;
        }
        
        pNext = pParent;
    }
    return pNext;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
