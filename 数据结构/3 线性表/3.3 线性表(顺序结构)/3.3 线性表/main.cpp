//
//  main.cpp
//  3.3 线性表
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
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;


/**
 *  用e返回线性表中第i个元素的值
 *
 *  @param L 线性表
 *  @param i i下标
 *  @param e 元素
 *
 *  @return 状态码
 */
Status GetElem (SqList L, int i, ElemType *e) {
    if (L.length == 0 || L.length < i) {
        return ERROR;
    }
    *e = L.data[i];
    return OK;
}

/**
 *  插入线性表
 *
 *  @param L 线性表
 *  @param i 插入的下标
 *  @param e 元素e
 *
 *  @return 状态码
 */
Status ListInsert (SqList *L, int i, ElemType e) {
    if (L->length < i || i < 1) {
        return ERROR;
    }
    if (L->length == MAXSIZE) { // 线性表已经满了
        return ERROR;
    }
    if (i <= L->length) { // 若插入数据位置不在表尾
        for (int k = L->length - 1; k > i - 1; k--) {
            // 把插入位置后面的元素往后移一个位置
            L->data[k + 1] = L->data[k];
        }
    }
    
    // 插入e
    L->data[i - 1] = e;
    // 需要记得更新长度
    L->length++;
    return OK;
}

/**
 *  在线性表中删除下标为i的元素，并且把下标的元素赋予e
 *
 *  @param L 线性表
 *  @param i 下标
 *  @param e 元素e
 *
 *  @return 状态码
 */
Status ListDelete (SqList *L, int i, ElemType *e) {
    // 健壮性
    if (L == NULL || i > L->length || i < 1 || L->length == 0) {
        return ERROR;
    }
    // 取得将要被删除的元素
    *e = L->data[i - 1];
    
    if (i < L->length) { // 不是在队尾
        for (int k = L->length - 1; k <= i; k--) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
