//
//  main.cpp
//  剑指offer: 面试题24：二叉搜索树的后续遍历序列
//
//  Created by 郑钦洪 on 16/6/12.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool VerifySquenceOfBST(int sequence[], int length) {
    if (sequence == NULL || length < 1) {
        return false;
    }
    
    // 取得根结点
    int root = sequence[length - 1];

    int i = 0;
    for (; i < length - 1; i++) {
        if (sequence[i] > root) {
            break;
        }
    }
    
    int j = i;
    for (; j < length - 1; j++) {
        if (sequence[j] < root) { // 搜索二叉树右子树比根结点小 说明肯定出错
            return false;
        }
    }
    
    // 遍历左子树
    bool left = true;
    if (i > 0) {
        left = VerifySquenceOfBST(sequence, i);
    }
    
    // 遍历右子树
    bool right = true;
    if (i < length - 1) {
        right = VerifySquenceOfBST(sequence + i, length - 1 - i);
    }
    
    return (left && right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
