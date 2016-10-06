//
//  main.cpp
//  剑指offer:面试题18:树的子结构
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
bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
    if (pRoot2 == NULL) {
        return true;
    }
    if (pRoot1 == NULL) {
        return false;
    }
    if (pRoot1->m_value != pRoot2->m_value) {
        return false;
    }
    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2){
    bool result = false;
    if (pRoot1 != NULL && pRoot2 == NULL) {
        if (pRoot1->m_value == pRoot2->m_value) {
            result = DoesTree1HaveTree2(pRoot1,pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot2->m_pRight, pRoot2);
        }
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
