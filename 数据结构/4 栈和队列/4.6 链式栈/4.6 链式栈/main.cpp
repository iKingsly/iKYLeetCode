//
//  main.cpp
//  4.6 链式栈
//
//  Created by 郑钦洪 on 16/6/27.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#define MAXSIZE 5
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
    
}*LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

Status Push (LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr) malloc(sizeof(LinkStackPtr));
    s->data = e;
    s->next = S->top;
    S->top = s->next;
    S->count++;
    return OK;
}

Status Pop (LinkStack *S, SElemType *e) {
    if (S == NULL) {
        return ERROR;
    }
    
    LinkStackPtr p = S->top;
    *e = p->data;
    S->count--;
    S->top = p->next;
    free(p);
    return OK;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
