//
//  main.cpp
//  剑指offer:面试题60:把二叉树打印成多行
//
//  Created by 郑钦洪 on 16/7/12.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef struct BinaryTreeNode {
    int m_value;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
} BinaryTreeNode;

void Print(BinaryTreeNode *pRoot) {
    if (pRoot == NULL) {
        return;
    }
    
    queue<BinaryTreeNode *> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while (!nodes.empty()) {
        BinaryTreeNode *pNode = nodes.front();
        printf("%d ",pNode->m_value);
        
        if (pNode->m_pLeft != NULL) {
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        
        if (pNode->m_pRight != NULL) {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }
        
        nodes.pop();
        --toBePrinted;
        if (toBePrinted == 0) {
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
