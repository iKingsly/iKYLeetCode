//
//  main.cpp
//  剑指offer:面试题25 二叉树种和为某一值的路径
//
//  Created by 郑钦洪 on 16/6/13.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct BinaryTreeNode {
    int m_value;
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
};
void FindPath(BinaryTreeNode *pRoot, int expectedSum, vector<int> path, int currentSum) {
    currentSum += pRoot->m_value;
    path.push_back(pRoot->m_value);
    
    // 如果是叶结点，并且路径之和等于输入的值
    bool isLeave = pRoot->m_left == NULL && pRoot->m_right;
    if (expectedSum == currentSum && isLeave) {
        printf("A path is found : ");
        std::vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); ++iter) {
            printf("%d\t", iter);
        }
        printf("\n");
    }
    
    // 如果有左结点
    if (pRoot->m_left) {
        FindPath(pRoot->m_left, expectedSum, path, currentSum);
    }
    // 如果有右结点
    if (pRoot->m_right) {
        FindPath(pRoot->m_right, expectedSum, path, currentSum);
    }
}

void FindPath(BinaryTreeNode *pRoot, int expectedSum) {
    if (pRoot == NULL) {
        return;
    }
    
    vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
