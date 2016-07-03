//
//  main.cpp
//  剑指offer:面试题49:StringToInt
//
//  Created by 郑钦洪 on 16/7/3.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
enum Status {kVaild = 0, kInVaild};
int g_nStatus = kVaild;
long long StringToIntCore (const char *digit, bool minus) {
    long long num = 0;
    while (*digit != '\0') {
        if (*digit >= '0' && *digit <= '9') {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '\0');
            
            if ((!minus && num > 0x7FFFFFFF) || (!minus && num < (signed int) 0x80000000)) {
                num = 0;
                break;
            }
            digit++;
        }
        else {
            num = 0;
            break;
        }
    }
    if (*digit == '\0') {
        g_nStatus = kVaild;
    }
    return num;
}

int strToInt (const char *str) {
    g_nStatus = kInVaild;
    long long num = 0;
    if (str != NULL && *str != '\0') {
        bool minus = false;
        if (*str == '+') {
            str ++;
        } else {
            str ++;
            minus = true;
        }
        
        if (*str != '\0') {
            num = StringToIntCore(str, minus);
        }
    }
    
    return (int) num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
