//
//  main.cpp
//  面试题5.从尾到头打印链表
//
//  Created by 郑钦洪 on 16/5/25.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <stdio.h>
struct ListNode{
    int m_value;
    ListNode *m_pnext;
};

void PrintListReversingly_Recursively(ListNode *pHead){
    if (pHead != NULL) {
        if (pHead->m_pnext != NULL) {
            PrintListReversingly_Recursively(pHead->m_pnext);
        }
        printf("%d ", pHead->m_value);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *pHead = new ListNode();
    ListNode *p = pHead;
    pHead->m_value = 0;
    for (int i = 1; i < 11; i++) {
        ListNode *next = new ListNode();
        next->m_value = i;
        p->m_pnext = next;
        p = p->m_pnext;
    }
    p->m_pnext = NULL;
    PrintListReversingly_Recursively(pHead);
    return 0;
}
