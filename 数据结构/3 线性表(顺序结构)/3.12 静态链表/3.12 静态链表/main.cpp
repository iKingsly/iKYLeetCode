//
//  main.cpp
//  3.12 静态链表
//
//  Created by 郑钦洪 on 16/6/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#define MAXSIZE 100
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];
// 静态链表的0元素的下标指向第一个空闲空间元素的下标
// 静态链表的最后一个元素的下标指向第一个元素的下标
Status ListInit (StaticLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    return OK;
}

int Malloc_SLL (StaticLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) { // 如果有剩余的闲置空间，把新的剩余的闲置空间下标进行更新
        space[0].cur = space[i].cur;
    }
    return i;
}

Status ListInsert (StaticLinkList L, int i, ElemType e) {
    if (i < 1) {
        return ERROR;
    }
    
    int k = MAXSIZE - 1;
    int j = Malloc_SLL(L);
    if (j) {
        L[j].data = e;
        
        for (int l = 1; l < i; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
