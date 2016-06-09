//
//  main.cpp
//  剑指offer：面试题15 链表中倒数第K个结点
//
//  Created by 郑钦洪 on 16/6/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
struct ListNode{
    int m_value;
    ListNode *next;
};
ListNode* FindKthToTail(ListNode *pData, unsigned int K){
    if (pData == NULL || K < 1) {
        return NULL;
    }
    ListNode *pHead = pData;
    ListNode *pEnd = pData;
    
    for (int i = 0; i < K; i++) {
        if (pHead->next != NULL) {
            pHead = pHead->next;
        }else{
            return NULL;
        }
    }
    
    while(pHead->next != NULL){
        pHead = pHead->next;
        pEnd = pEnd->next;
    }
    return pEnd;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
