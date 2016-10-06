//
//  main.cpp
//  剑指offer:面试题39-2:判断是否为平衡二叉树
//
//  Created by 郑钦洪 on 16/6/27.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct BinaryTree {
    int m_value;
    BinaryTree *m_left;
    BinaryTree *m_right;
};
bool IsBalanced(BinaryTree *root, int *pDepth) {
    if (root == NULL) {
        *pDepth = 0;
        return true;
    }
    
    int left, right;
    if (IsBalanced(root->m_left, &left) && IsBalanced(root->m_right, &right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}
bool IsBalanced(BinaryTree *root) {
    int depth = 0;
    return IsBalanced(root, &depth);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
