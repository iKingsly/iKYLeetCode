//
//  main.cpp
//  剑指offer:面试题17 合并两个排序的链表
//
//  Created by 郑钦洪 on 16/6/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct ListNode{
    int m_value;
    ListNode *m_next;
};

ListNode *Merge(ListNode *pHead1, ListNode *pHead2){
    if (pHead1 == NULL) {
        return pHead2;
    }else if (pHead2 == NULL) {
        return pHead1;
    }
    
    ListNode *pMergeHead = NULL;
    if (pHead1->m_value < pHead2->m_value) {
        pMergeHead = pHead1;
        pMergeHead->m_next = Merge(pHead1->m_next, pHead2);
    }else{
        pMergeHead = pHead2;
        pMergeHead->m_next = Merge(pHead1, pHead2->m_next);
    }
    return pMergeHead;
}

ListNode *MergeWithLoop(ListNode *pHead1, ListNode *pHead2){
    if (pHead1 == NULL) {
        return pHead2;
    }else if (pHead2 == NULL) {
        return pHead1;
    }
    ListNode *pMergeHead = NULL;
    ListNode *pHead = NULL;
    while (pHead1 && pHead2) {
        if (pHead1->m_value < pHead2->m_value) {
            if (pMergeHead == NULL) {
               pHead = pMergeHead = pHead1;
            }else{
                pHead->m_next = pHead1;
                pHead = pHead->m_next;
            }
            pHead1 = pHead1->m_next;
        }else{
            if (pMergeHead == NULL) {
               pHead = pMergeHead = pHead2;
            }else{
                pHead->m_next = pHead2;
                pHead = pHead->m_next;
            }
            pHead2 = pHead2->m_next;
        }
    }
    if (pHead1) {
        pHead->m_next = pHead1;
    }else if(pHead2){
        pHead->m_next = pHead2;
    }
    return pMergeHead;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
