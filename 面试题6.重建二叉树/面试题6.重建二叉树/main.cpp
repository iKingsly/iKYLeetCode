//
//  main.cpp
//  面试题6.重建二叉树
//
//  Created by 郑钦洪 on 16/5/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct BinaryTreeNode{
    int m_value;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConstructCore(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder){
    
}



BinaryTreeNode *Construct(int *preorder, int *inorder, int length){
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    return NULL;
}


int main(int argc, const char * argv[]) {
    return 0;
}
