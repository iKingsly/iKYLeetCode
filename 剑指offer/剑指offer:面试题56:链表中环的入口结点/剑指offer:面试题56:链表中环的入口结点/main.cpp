//
//  main.cpp
//  剑指offer:面试题56:链表中环的入口结点
//
//  Created by 郑钦洪 on 16/7/6.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct ListNode{
    int data;
    ListNode *next;
}ListNode;

ListNode * MeetingNode (ListNode *pHead) {
    if (pHead == NULL) {
        return NULL;
    }
    ListNode *pSlow = pHead;
    ListNode *pFast = pSlow->next;
    
    while (pSlow != NULL && pFast != NULL) {
        if (pFast == pSlow) {
            return pFast;
        }
        
        pFast = pFast->next;
        
        pSlow = pSlow->next;
        
        if (pFast->next != NULL) {
            pFast = pFast->next;
        }
    }
    
    return NULL;
}

ListNode *EntryNodeOfLoop (ListNode *pHead) {
    ListNode *meetNode = MeetingNode(pHead);
    if (meetNode == NULL) {
        return NULL;
    }
    
    int nodesInLoop = 1;
    ListNode *pNode = meetNode;
    
    while(pNode->next != meetNode) {
        pNode = pNode->next;
        ++nodesInLoop;
    }
    
    pNode = pHead;
    for (int i = 0; i < nodesInLoop; ++i) {
        pNode = pNode->next;
    }
    ListNode *pNode2 = pHead;
    
    while (pNode != pNode2) {
        pNode = pNode->next;
        pNode2 = pNode2->next;
    }
    
    return pNode;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
