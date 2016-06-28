//
//  main.cpp
//  4.13 队列的链式结构
//
//  Created by 郑钦洪 on 16/6/28.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#define MAXSIZE 5
#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
typedef int Status;
typedef int QElemType;

// 结点结构
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

// 队列的链表结构
typedef struct {
    // 队头 队尾指针
    QueuePtr front, rear;
} LinkQueue;

Status EnQueue (LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr) malloc(sizeof(QNode));
    if (!s) {
        exit(EOVERFLOW);
    }
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
    return OK;
}

Status DeQueue (LinkQueue *Q, QElemType *e) {
    QueuePtr s;
    if (Q->front == Q->rear) { // 队列为空
        return ERROR;
    }
    
    s = Q->front->next;
    Q->front = s->next;
    
    *e = s->data;
    
    if (Q->rear == s) { // 如果队列中只有一个元素， 需要把尾指针也指向头指针
        Q->rear = Q->front;
    }
    free(s);
    return OK;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
