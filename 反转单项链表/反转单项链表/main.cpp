//
//  main.cpp
//  反转单项链表
//
//  Created by 郑钦洪 on 16/8/10.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef struct Node{
    int value;
    Node *next;
} Node;

Node* reverseList(Node *head) {
    Node *pre = NULL;
    Node *next = NULL;
    if (head == NULL) {
        return NULL;
    }
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    return pre;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Node *head = NULL;
    Node *node = head;
    for (int i = 1; i < 10 ; i++) {
        Node *next = new Node();
        next->value = i;
        next->next = NULL;
        if (head) {
            node->next = next;
            node = node->next;
        } else {
            head = node = next;
        }
    }

    head = reverseList(head);

    while (head != NULL) {
        printf("%d->", head->value);
        head = head->next;
    }
    return 0;
}
