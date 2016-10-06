//
//  main.cpp
//  326. Power of Three
//
//  Created by 郑钦洪 on 16/5/30.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool isPowerOfThree(int n) {
    if(n <= 0) return false;
    if(1162261467 % n == 0){
        return true;
    }else{
        return false;
        
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 1 % 4;
    printf("%d",a);
    return 0;
}
