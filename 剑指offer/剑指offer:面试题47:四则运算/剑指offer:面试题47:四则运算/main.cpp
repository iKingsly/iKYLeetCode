//
//  main.cpp
//  剑指offer:面试题47:四则运算
//
//  Created by 郑钦洪 on 16/7/2.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int getResultOfAdd(int num1, int num2) {
    int sum, carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (num2 != 0);
    return sum;
}
int main(int argc, const char * argv[]) {
    //
    int result = getResultOfAdd(10,22);
    printf("%d \n", result);
    std::cout << "Hello, World!\n";
    return 0;
}
