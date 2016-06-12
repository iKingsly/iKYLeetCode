//
//  main.cpp
//  剑指offer: 面试题23 从上往下打印数组
//
//  Created by 郑钦洪 on 16/6/12.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
struct BinaryTreeNode{
    int m_value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot){
    if (!pTreeRoot) {
        return;
    }
    deque<BinaryTreeNode *> dequeTreeNode;
    
    dequeTreeNode.push_back(pTreeRoot);
    while (dequeTreeNode.size()) {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();
        printf("%d ", pNode->m_value);
        
        if (pNode->left) { // 把左右结点压进队列
            dequeTreeNode.push_back(pNode->left);
        }
        
        if (pNode->right) { // 把左右结点压进队列
            dequeTreeNode.push_back(pNode->right);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
