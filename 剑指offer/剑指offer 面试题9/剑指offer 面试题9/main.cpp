//
//  main.cpp
//  剑指offer 面试题9
//
//  Created by 郑钦洪 on 16/6/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
long long Fibonacci(unsigned n){
    int result[2] = {0,1};
    if (n < 2) {
        return result[n];
    }
    long long resultA = result[0];
    long long resultB = result[1];
    long long resultF = 0;
    for (int i = 2 ; i <= n; i++) {
        resultF = resultA + resultB;
        resultA = resultB;
        resultB = resultF;
    }
    return resultF;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
