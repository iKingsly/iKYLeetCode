//
//  main.cpp
//  剑指offer:面试题51:数组中的重复数字
//
//  Created by 郑钦洪 on 16/7/4.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool duplicate(int numbers[], int length, int *duplication) {
    if (numbers == NULL || length <= 0) {
        return false;
    }
    
    for (int i = 0 ; i < length; i++) {
        if (numbers[i] < 0 || numbers[i] > length - 1 ){
            return false;
        }
    }
    
    for (int i = 0; i < length; i++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            } else {
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
