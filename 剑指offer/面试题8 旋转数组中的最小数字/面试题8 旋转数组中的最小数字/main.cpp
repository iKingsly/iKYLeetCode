//
//  main.cpp
//  面试题8 旋转数组中的最小数字
//
//  Created by 郑钦洪 on 16/6/2.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int Min(int * numbers, int length){
    if (numbers == NULL) {
        return -1;
    }
    int start = 0;
    int end = length - 1;
    int mid = start+1;
    while (start < end) {
        mid = (start + end)/2;
        if (numbers[start] >= numbers[mid]) {
            end = mid;
        }
        if (numbers[mid] >= numbers[end]) {
            start = mid;
        }
    }
    return numbers[mid];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int numbers[5] = {4,5,6,2,3};
    int a = Min(numbers, 5);
    printf("%d\n",a);
    return 0;
}
