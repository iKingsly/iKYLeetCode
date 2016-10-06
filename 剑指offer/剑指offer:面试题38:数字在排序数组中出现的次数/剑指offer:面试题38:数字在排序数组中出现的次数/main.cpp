//
//  main.cpp
//  剑指offer:面试题38:数字在排序数组中出现的次数
//
//  Created by 郑钦洪 on 16/6/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int GetFirstk (int *data, int length, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    
    if (middleData == k) {
        if ((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0) {
            return middleIndex;
        } else {
            end = middleIndex - 1;
        }
    }
    else if(middleData > k){
        end = middleIndex - 1;
    } else {
        start = middleIndex + 1;
    }
    return GetFirstk(data, length, k, start, end);
}

int GetLastK (int *data, int length, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int middleIndex = (start + end) / 2;
    int middleData  = data[middleIndex];
    
    if (middleData == k) {
        if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1) {
            return middleIndex;
        } else {
            start = middleIndex + 1;
        }
    }
    else if (middleData < k) {
        start = middleIndex + 1;
    } else {
        end = middleIndex - 1;
    }
    return GetLastK(data, length, k, start, end);
}

int GetNumberOfK (int * data, int length, int k) {
    int number = 0;
    if (data != NULL && length > 0) {
        int first = GetFirstk(data, length, k, 0, length - 1);
        int end   = GetLastK(data, length, k, 0, length - 1);
        if (first > -1 && end > -1) {
            number = end - first;
        }
    }
    return number;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int numbers[] = {1,2,3,3,3,3,4,5};
    int result = GetNumberOfK(numbers, 8, 3);
    printf("%d\n",result);
    return 0;
}
