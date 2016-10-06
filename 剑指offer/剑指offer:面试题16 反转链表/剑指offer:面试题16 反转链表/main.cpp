//
//  main.cpp
//  剑指offer:面试题16 反转链表
//
//  Created by 郑钦洪 on 16/6/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct ListNode{
    int m_value;
    ListNode *m_next;
};

ListNode * ReverseList(ListNode *pHead){
    if (pHead == NULL) {
        return NULL;
    }
    ListNode *pPre = NULL;
    ListNode *pNode = pHead;
    ListNode *pReverseHead = NULL;
    while (pNode!=NULL) {
        ListNode *pNext = pNode->m_next;
        if (pNext == NULL) {
            pReverseHead = pNode;
        }
        pNode->m_next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
