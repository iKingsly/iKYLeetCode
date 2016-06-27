//
//  main.cpp
//  剑指offer:面试题39:二叉树的深度
//
//  Created by 郑钦洪 on 16/6/27.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct BinaryTreeNode {
    int m_nValuel;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

int TreeDepth(BinaryTreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left = TreeDepth(root->m_pLeft);
    int right = TreeDepth(root->m_pRight);
    return left > right ? (left + 1) : (right + 1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
