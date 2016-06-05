//
//  main.cpp
//  剑指offer 面试题11 数值的整数次方
//
//  Created by 郑钦洪 on 16/6/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
// 对于浮点型的判断不能直接用相等来进行处理
bool g_InvalidInput = false;
bool equal(double num1, double num2){
    if ((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001)) {
        return true;
    }else{
        return false;
    }
}

double PowerWithUnsignedExponent(double base, unsigned int exponent){
    if (exponent == 0) {
        return 1;
    }else if(exponent == 1){
        return base;
    }
    
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1) { // 判断是否为奇数
        result *= base; // 如果是奇数的话还要乘一次底数
    }
    return result;
}

double Power(double base, int exponent){
    // 判断是否是一个合法的base 0，1
    g_InvalidInput = false;
    if (equal(base, 0.0) || exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }
    
    // 判断exponent的正负
    unsigned int absExponent = (unsigned int) exponent;
    if (exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
