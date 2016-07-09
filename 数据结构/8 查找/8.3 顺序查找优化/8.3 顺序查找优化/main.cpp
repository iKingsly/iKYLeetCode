//
//  main.cpp
//  8.3 顺序查找优化
//
//  Created by 郑钦洪 on 16/7/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int sequentialSearch(int numbers[], int n, int key) {
    numbers[0] = key;
    int i = n;
    while (key != numbers[i]) {
        i--;
    }
    return i;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
