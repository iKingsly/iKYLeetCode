//
//  main.m
//  9. 基础排序
//
//  Created by 郑钦洪 on 16/7/16.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#import <Foundation/Foundation.h>
#define MAXSIZE 10
typedef struct {
    int r[MAXSIZE+1];
    int length;
}SqList;

void swap (SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void BubbleSort(SqList *L) {
    int i,j;
    for (i = 1; i < L->length; i++) {
        for (j = L->length-1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                swap(L, j, j+1);
            }
        }
    }
}

void BubbleSort2(SqList *L) {
    int i,j;
    bool flag = true;
    for (i = 1; i < L->length && flag; i++) {
        flag = false; // 当不需要进行交换的时候，就退出
        for (j = L->length-1; j >= i; j--) {
            if (L->r[j] > L->r[j+1]) {
                swap(L, j, j+1);
                flag = true;
            }
        }
    }
}

// O(n^2)
void SelectSort (SqList *L) {
    int i,j,min = 0;
    for(i = 1; i <= L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[min] < L->r[j]) {
                min = j;
            }
        }
        if (i != min) {
            swap(L, i, min);
        }
    }
}

void InsertSort(SqList *L) {
    int i,j;
    for (i = 2 ; i < L->length; i++) {
        if (L->r[i] < L->r[i - 1]) {
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

void ShellSort(SqList *L) {
    int i, j;
    int increment=L->length;
    do {
        increment = increment / 3 + 1;
        for (i = increment + 1; i < L->length; i++) {
            if (L->r[i] < L->r[i-increment]) {
                L->r[0] = L->r[i];
                for (j = i - increment; j>0 && L->r[0]<L->r[j]; j-=increment) {
                    L->r[j+increment] = L->r[j];
                }
                L->r[j+increment] = L->r[0];
            }
        }
    } while (increment > 1);
}

// 堆排序
/// 调整堆排序的序列
void HeadAdjust (SqList *L, int s,int m) {
    int temp,j;
    temp = L->r[s];
    for (j = 2 * s; j < m ; j *= 2) {
        if (j < m && L->r[j] < L->r[j+1]) {
            ++j;
        }
        if (temp >= L->r[j]) {
            break;
        }
        L->r[s] = L->r[j];
    }
    L->r[s] = temp;
    
}

void HeapSort (SqList *L) {
    int i;
    for (i = L->length/2; i > 0 ; i--) {
        HeadAdjust(L, i, L->length);
    }
    
    for (i = L->length; i > 1; i--) {
        swap(L, 1, i);
        HeadAdjust(L, i, i-1);
    }
}


// 归并排序 递归算法
/// 将有序的SR[i...m] 和 SR[m+1...n] 归并为有序的TR[i...n]

void Merge (int SR[], int TR[], int i, int m, int n) {
    int j , k, l;
    for (j = m + 1 , k = i; i <= m && j <= n; k++) { // 将SR中记录由小到大归并入TR
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    if (i < m) {
        for (l = 0; l < m - i; l++) {
            TR[k+1] = SR[i+l];
        }
    }
    if (j < n) {
        for (l = 0; l <= n - j; l++) {
            TR[k+1] = SR[j+1];
        }
    }
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
