//
//  main.cpp
//  剑指offer:面试题32从1到证书中1出现的次数
//
//  Created by 郑钦洪 on 16/6/22.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int count(unsigned int n) {
    // 1 的个数
    int count = 0;
    // 当前位
    int Factor = 1;
    // 当前位数字
    int CurrNum = 0;
    // 低位数字
    int LowerNum = 0;
    // 高位数字
    int HigherNum = 0;
    if (n <= 0) {
        return 0;
    }
    while (n / Factor != 0) {
        // 低位数字
        LowerNum = n - (n/Factor) * Factor;
        // 当前数字
        CurrNum = (n / Factor) % 10;
        // 高位数字
        HigherNum = (n / (Factor * 10));
        
        // 如果当前数字为0 则出现1的次数又高位决定
        if (CurrNum == 0) {
            // 等于高位数字 ＊ 当前数位
            count += HigherNum * Factor;
        } else if (CurrNum == 1) { // 如果味1 出现1的次数由高位和低位决定
            count += HigherNum * Factor + LowerNum + 1;
        } else { // 如果大于1 出现次数由高位决定
            count += (HigherNum + 1) * Factor;
        }
        Factor *= 10;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int result = count(12);
    printf("%d\n", result);
    std::cout << "Hello, World!\n";
    return 0;
}
