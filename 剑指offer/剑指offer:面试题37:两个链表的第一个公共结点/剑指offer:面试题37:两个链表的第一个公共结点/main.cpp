//
//  main.cpp
//  剑指offer:面试题37:两个链表的第一个公共结点
//
//  Created by 郑钦洪 on 16/6/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};
int GetLinkLength(ListNode *L) {
    if (L == NULL) {
        return 0;
    }
    ListNode *p = L;
    int count = 0;
    if (p != NULL) {
        p = p->m_pNext;
        count++;
    }
    return count;
}

ListNode *FindFirstCommonNode (ListNode *pHead1, ListNode *pHead2) {
    int lengthHead1 = GetLinkLength(pHead1);
    int lengthHead2 = GetLinkLength(pHead2);
    ListNode *pLongNode;
    ListNode *pShortNode;
    int nLengthDif = 0;
    if (lengthHead2 > lengthHead1) {
        pLongNode = pHead2;
        pShortNode = pHead1;
        nLengthDif = lengthHead2 - lengthHead1;
    }
    else {
        pLongNode = pHead1;
        pShortNode = pHead2;
        nLengthDif = lengthHead1 - lengthHead2;
    }
    
    while (nLengthDif) {
        pLongNode = pLongNode->m_pNext;
        nLengthDif--;
    }
    
    while (pLongNode != NULL && pShortNode != NULL && pShortNode != pLongNode) {
        pLongNode = pLongNode->m_pNext;
        pShortNode = pShortNode->m_pNext;
    }
    
    return pLongNode;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
