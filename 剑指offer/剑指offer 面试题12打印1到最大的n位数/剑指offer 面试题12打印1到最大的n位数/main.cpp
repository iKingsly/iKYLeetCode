//
//  main.cpp
//  剑指offer 面试题12打印1到最大的n位数
//
//  Created by 郑钦洪 on 16/6/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
void PrintNumber(char *numbers){
    char *result = numbers;
    while (*result == '0') {
        result++;
    }
    printf("%s\n",result);
}

bool Increment(char *numbers){
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = (int)strlen(numbers);
    for (int i = nLength - 1; i >= 0; i--) { // 这里犯了一个错,把－－变成了＋＋
        int nSum = numbers[i] - '0' + nTakeOver;
        if (i == nLength - 1) {
            nSum++;
        }
        if (nSum >= 10) {
            if(i == 0){
                isOverflow = true;
            }else{
                nTakeOver = 1;
                numbers[i] = '0' + (nSum-10);
            }
        }else{
            numbers[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void Print1ToMaxOfNDigtis (int n){
    if (n <= 0) {
        return;
    }
    
    char *numbers = new char(n+1);
    numbers[n] = '\0';
    memset(numbers, '0', n);
    while (!Increment(numbers)) {
        PrintNumber(numbers);
    }
}

// 用递归的方式来解决这个问题
void Print1ToMaxOfNDigtisRecursively(char *numbers, int length, int index){
    if (index >= length) {
        PrintNumber(numbers);
        return;
    }
    
    for (int i = 0; i <= 9; i ++) {
        numbers[index] = '0' + i;
        Print1ToMaxOfNDigtisRecursively(numbers,length,index+1);
    }
}

void Print1ToMaxOfNDigtisNew(int n){
    char *numbers = new char(n+1);
    numbers[n+1] = '\0';
    
    Print1ToMaxOfNDigtisRecursively(numbers, n, 0);
    delete numbers;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Print1ToMaxOfNDigtisNew(3);
    return 0;
}
