//
//  main.cpp
//  剑指offer:面试题45:圆圈中最后剩下的数字
//
//  Created by 郑钦洪 on 16/7/1.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int LastRemaining (unsigned int n, unsigned int m) {
    if (n < 1 || m < 1) {
        return -1;
    }
    
    int last = 0;
    for (int i = 2; i <= n; i++) {
        last = (last + m) % i;
    }
    return last;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
