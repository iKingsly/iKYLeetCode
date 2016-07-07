//
//  main.cpp
//  剑指offer:面试题57:删除链表中相同的节点
//
//  Created by 郑钦洪 on 16/7/7.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct ListNode{
    int m_data;
    ListNode* m_next;
}ListNode;
void deleteDuplication (ListNode ** pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return;
    }
    
    ListNode *pPreHead = NULL;
    ListNode *pNode = *pHead;
    
    while (pNode != NULL) {
        ListNode *pNext = pNode->m_next;
        
        if (pNext != NULL && pNext->m_data == pNode->m_data) {
            int value = pNode->m_data;
            
            // 需要删除的节点
            ListNode *pToBeDel = pNode;
            
            // 从前往后遍历是否有相同的节点 有的话从前往后删除
            while (pToBeDel != NULL && pToBeDel->m_data == value) {
                pNext = pToBeDel->m_next;
                delete pToBeDel;
                // 到最后pToBeDel得到的是与pNode不相同的点
                pToBeDel->m_next = pNext;
            }
            
            // pNode 指向的是最新的节点
            if (pNode == NULL) {
                *pHead = pNext;
            } else {
                // pPreHead指向删除之前的一个节点
                pPreHead->m_next = pNext;
            }
            // pNode指向所有删除后的节点
            pNode = pNext;
        } else {
            // 不相同直接都往前走
            pPreHead = pNode;
            pNode = pNode->m_next;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
