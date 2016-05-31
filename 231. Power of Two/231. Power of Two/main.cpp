//
//  main.cpp
//  231. Power of Two
//
//  Created by 郑钦洪 on 16/5/31.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool isPowerOfTwo(int n) {
    long long result =  4294967296;
    if (result % 2 == n) {
        return true;
    }else{
        return false;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
