//
//  main.cpp
//  剑指offer:面试题46:求1+2+...+n
//
//  Created by 郑钦洪 on 16/7/2.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef unsigned int (*fun) (unsigned int);
unsigned int Solution3_Teminator (unsigned int n) {
    return 0;
}
unsigned int Sum_Solution3 (unsigned int n) {
    static fun f[2] = {Solution3_Teminator, Sum_Solution3};
    // 只有当n ＝ 0的时候 才会运行Solution3_Teminator 这样做到了递归退出的效果 
    return n + f[!!n](n - 1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int result = Sum_Solution3(100);
    printf("%d \n", result);
    return 0;
}
