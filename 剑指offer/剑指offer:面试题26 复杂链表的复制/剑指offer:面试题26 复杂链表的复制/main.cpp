//
//  main.cpp
//  剑指offer:面试题26 复杂链表的复制
//
//  Created by 郑钦洪 on 16/6/13.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct ComplexListNode {
    int m_value;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
};


void CloneNodes (ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode * pCloned = new ComplexListNode();
        pCloned->m_value = pNode->m_value;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;
        
        pNode->m_pNext = pCloned;
        
        pNode = pCloned->m_pNext;
    }
}

void ConnectSiblingNodes (ComplexListNode *pHead) {
    ComplexListNode *pNode = pHead;
    while (pNode != NULL) {
        ComplexListNode * pClone = pNode->m_pNext;
        if (pNode->m_pSibling != NULL) {
            pClone->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pClone->m_pNext;
    }
}

ComplexListNode* ReconnectNodes (ComplexListNode * pHead) {
    ComplexListNode *pNode = pHead;
    ComplexListNode *pCloneHead = pHead->m_pNext;
    ComplexListNode *pCloneNode = NULL;
    
    if (pNode != NULL) {
        pCloneHead = pCloneNode = pNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    while (pNode != NULL) {
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pCloneHead;
}

ComplexListNode * Clone (ComplexListNode *pHead) {
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
