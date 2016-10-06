//
//  main.cpp
//  剑指offer:面试题41:和为s的两个数字VS和为s的连续正数序列
//
//  Created by 郑钦洪 on 16/6/28.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool FindAddOfArrayWithSum(int data[], int length, int sum) {
    if (data == NULL || length < 0) {
        return false;
    }
    
    int begin = 0;
    int end = length - 1;
    int result = 0;
    while (begin < end) {
        result = data[begin] + data[end];
        if(result == sum) {
            return true;
        } else if (result < end) {
            begin++;
            continue;
        } else {
            end--;
            continue;
        }
    }
    return false;
}


void PrintContinuousSequence (int small, int big) {
    for (int i = small; i <= big; i++) {
        printf("%d ", i);
    }
}

void FindContinuousSequence (int sum) {
    if (sum < 3) {
        return;
    }
    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    
    while (small < middle) {
        if (curSum == sum) {
            PrintContinuousSequence(small, big);
        }
        while (curSum > sum && small < middle) {
            curSum -= small;
            small++;
            if (curSum == sum) {
                PrintContinuousSequence(small, big);
            }
        }
        big++;
        curSum += big;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
