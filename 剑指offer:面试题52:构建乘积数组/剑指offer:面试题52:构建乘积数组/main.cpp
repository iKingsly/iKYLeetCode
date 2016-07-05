//
//  main.cpp
//  剑指offer:面试题52:构建乘积数组
//
//  Created by 郑钦洪 on 16/7/5.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void multiply(const vector<double> &array1, vector<double> &array2) {
    int length1 = (int)array1.size();
    int length2 = (int)array2.size();
    
    if (length1 == length2 && length2 > 1) {
        array2[0] = 1;
        for (int i = 1; i < length1; ++i) {
            array2[i] = array2[i - 1] * array1[i-1];
        }
        
        double temp = 1;
        for (int i = length1 - 2; i >= 0; --i) {
            temp *= array1[i + 1];
            array2[1] *= temp;
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
