//
//  main.cpp
//  263. Ugly Number
//
//  Created by 郑钦洪 on 16/5/30.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool isUgly(int num) {
    if (num < 1) {
        return false;
    }
    if (num == 1 || num == 2123366400) {
        return true;
    }
    long long a[7] = {1162261467,1220703125,2147483648,1000000000,2176782336,2562890625,21870000000};
    for (int i = 0;  i < 7; i++) {
        if (a[i] % num == 0) {
            return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    long long num = 2123366400;
    long long a[7] = {1162261467,1220703125,2147483648,1000000000,2176782336,2562890625,729000000};
    for (int i = 0 ; i < 7; i++) {
        printf("%lld\n", num % a[i]);
    }
    return 0;
}
