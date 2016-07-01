//
//  main.cpp
//  KMP
//
//  Created by 郑钦洪 on 16/7/1.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
// 返回子串T的next数组
void get_next (string T, int *next) {
    int i, j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0]) { // T[0] 存放的是字符串的长度
        
        if (j == 0 || T[i] == T[j]) { // T[i] 表示后缀的单个字符 T[j]表示前缀的单个字符
            i ++;
            j ++;
            next[i] = j;
        } else {
            j = next[j]; // 如果不线程 则 j 进行回溯
        }
    }
}

int Index_KMP (string S, string T, int pos) {
    int i = pos;
    int j = 1; // T当前的位置下标
    int next[255];
    get_next(T, next);
    
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            ++ i;
            ++ j;
        } else { // 指针后退重新开始匹配
            j = next[j];
        }
    }
    if (j > T[0]) {
        return i-T[0];
    } else {
        return 0;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
