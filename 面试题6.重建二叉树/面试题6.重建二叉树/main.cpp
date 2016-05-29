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
    // 前序遍历的第一个结点就是根结点
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_value = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        }else{
            return NULL;
        }
    }
    
    // 中序遍历中找到根节点的值
    int *rootInOrder = startInorder;
    while (rootInOrder <= endInorder && *rootInOrder != rootValue) {
        rootInOrder++;
    }
    
    int leftLength = rootInOrder - startInorder;
    int *leftPreOrderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreOrderEnd, startInorder, rootInOrder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ConstructCore(leftPreOrderEnd + 1, endPreorder, rootInOrder + 1, endInorder);
    }
    
    return root;
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
