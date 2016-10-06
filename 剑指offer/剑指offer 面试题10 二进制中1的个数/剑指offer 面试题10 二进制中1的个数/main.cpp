//
//  main.cpp
//  剑指offer 面试题10 二进制中1的个数
//
//  Created by 郑钦洪 on 16/6/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int NumberOf1(int n){
    int count = 0;
    while (n) {
        count++;
        // 这个操作会换掉n中最右边的一个1
        n = (n-1) & n;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int number = NumberOf1(7);
    printf("%d\n",number);
    return 0;
}
