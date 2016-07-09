//
//  main.cpp
//  8.4  折半查找
//
//  Created by 郑钦洪 on 16/7/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int BinarySearch(int numbers[], int n, int key) {
    int begin = 1;
    int end = n;
    int mid;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (numbers[mid] > key) {
            end = mid - 1;
        } else if (numbers[mid] < key) {
            begin = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int numbers[] = {0,1,16,24,35,47,59,99};
    int result = BinarySearch(numbers, 8, 24);
    printf("%d\n",result);
    return 0;
}
