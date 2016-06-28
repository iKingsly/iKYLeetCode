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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
