//
//  main.cpp
//  剑指offer:面试题29 数组中超过一半的数
//
//  Created by 郑钦洪 on 16/6/16.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int MoreThanHalfNum (int *numbers, int length) {
    int result = numbers[0];
    int count = 1;
    
    for (int i = 1; i < length; i++) {
        if (count == 0) {
            result = numbers[i];
            count = 1;
            continue;
        }
        if (result == numbers[i]) {
            count++;
        } else {
            count--;
        }
    }
    
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
