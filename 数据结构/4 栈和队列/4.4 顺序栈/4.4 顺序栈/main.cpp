//
//  main.cpp
//  4.4 顺序栈
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

typedef struct {
    // 数据段
    SElemType data[MAXSIZE];
    // 栈顶
    int top;
}SqStack;

Status Push(SqStack *s, SElemType e) {
    if (s->top == MAXSIZE - 1) {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}

Status Pop(SqStack *s, SElemType *e) {
    if (s->top == -1) { // 栈为空
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
