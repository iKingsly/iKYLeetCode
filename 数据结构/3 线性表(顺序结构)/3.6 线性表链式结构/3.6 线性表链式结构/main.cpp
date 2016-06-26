//
//  main.cpp
//  3.6 线性表链式结构
//
//  Created by 郑钦洪 on 16/6/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#define MAXSIZE 20
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

Status GetElem (LinkList L, int i, ElemType *e) {
    if (L == NULL) {
        return ERROR;
    }
    
    LinkList p = L->next;
    int j = 1;
    while (j < i && p) {
        p = p->next;
        j++;
    }
    
    // 遍历到线性表的最后，j仍然小于i
    if (!p || j < i) {
        return ERROR;
    }
    
    *e = p->data;
    return OK;
}

// 找到i的前一个元素进行插入操作
Status ListInsert (LinkList *L, int i, ElemType e) {
    LinkList p = *L;
    int j = 1;
    
    // 在i的前一个位置后停止
    while (p || j < i) {
        p = p->next;
        ++j;
    }
    // 遍历到线性表的最后，j仍然小于i
    if (!p || j < i) {
        return ERROR;
    }
    
    // new 一个新的s
    LinkList s = (LinkList )malloc(sizeof(LinkList));
    
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete (LinkList *L, int i , ElemType *e) {
    LinkList p = *L;
    int j = 1;
    while (j < i || p) {
        p = p->next;
        ++j;
    }

    // 找到要删除的前一个节点，判断要删除的结点是否为空
    if (!(p->next) || j > i) {
        return ERROR;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void CreateListHead (LinkList *L, int n) {
    srand(time(0));
    *L = (LinkList )malloc(sizeof(LinkList));
    (*L)->next = NULL;
    for (int i = 0 ; i < n; i++) {
        LinkList p = (LinkList )malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail (LinkList *L , int n) {
    srand(time(0));
    *L = (LinkList )malloc(sizeof(LinkList));
    LinkList r = *L;
    for (int i = 0 ; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(LinkList));
        p->data = rand() % 100 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;

}

Status ClearList (LinkList *L) {
    LinkList p,q;
    p = (*L)->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    
    // 将头指针的next指向null
    (*L)->next = NULL;
    return OK;
}
int main(int argc, const char * argv[]) {
    LinkList L;
    CreateListHead(&L, 5);
    for (int i = 1; i <= 5; i++) {
        ElemType e;
        GetElem(L, i, &e);
        printf("%d \t",e);
    }
    return 0;
}
