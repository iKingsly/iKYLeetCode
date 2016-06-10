//
//  main.cpp
//  剑指offer:面试题19 镜面树
//
//  Created by 郑钦洪 on 16/6/10.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct BinaryTreeNode{
    int m_value;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};
void MirrorRecursively (BinaryTreeNode * pNode){
    if (pNode == NULL) {
        return;
    }
    
    if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL) {
        return;
    }
    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    
    if (pTemp->m_pLeft) {
        MirrorRecursively(pNode->m_pLeft);
    }
    if (pNode->m_pRight) {
        MirrorRecursively(pNode->m_pRight);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
