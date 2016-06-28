//
//  main.cpp
//  4.12 循环队列
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
typedef struct {
    QElemType data[MAXSIZE];
    /* 头指针 */
    int front;
    /* 尾指针 */
    int rear;
} SqQueue;

/**
 *  初始化一个循环队列
 *
 *  @param Q 循环队列
 *
 *  @return 状态码
 */
Status InitQueue (SqQueue *Q) {
    Q->front = 0;
    Q->rear  = 0;
    return OK;
}

int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE ) % MAXSIZE;
}

/**
 *  若队列不满，在队尾插入新元素
 *
 */
Status EnQueue (SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) { // 队列已经满了
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

/**
 *  若队列不为空，删除队头的元素
 */
Status DeQueue (SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) { // 队列不为空
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
