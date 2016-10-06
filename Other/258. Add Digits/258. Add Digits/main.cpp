//
//  main.cpp
//  258. Add Digits
//
//  Created by 郑钦洪 on 16/5/31.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int addDigits(int num) {
    int result = 10;
    while (result/10 > 0) {
        result = 0;
        while (num > 0) {
            result += num % 10;
            num = num / 10;
        }
        num = result;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a = addDigits(38);
    printf("%d",a);
    return 0;
}
