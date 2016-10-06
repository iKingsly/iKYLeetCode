//
//  main.cpp
//  剑指offer:面试题36:数组中的逆序对
//
//  Created by 郑钦洪 on 16/6/26.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int InversePairsCore (int *data, int *copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    
    int length = (end - start) / 2;
    int left = InversePairsCore(data, copy, start, start + length);
    int right = InversePairsCore(data, copy, start + length + 1, end);
    
    // i 为前半段最后一个下标
    int i = start + length;
    // j 为后半段的最后一个下标
    int j = end;
    int indexCopy = end;
    
    int count = 0;
    // 对两边进行比较
    while (i >= start && j >= start + length + 1) {
        // 从左右两边的最后一个元素开始遍历 在辅助数组中从小到达排
        if (copy[i] > copy[j]) {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else {
            copy[indexCopy--] = data[j--];
        }
    }
    for (; i >= start; i--) { // 如果左边数组还没填充完
        copy[indexCopy--] = data[i];
    }
    
    for (; j >= start + length + 1; j--) { // 如果右边数组还没填充完
        copy[indexCopy--] = data[j];
    }
    return left + right + count;
}

int InversePairs(int *data, int length) {
    if (data == NULL || length < 0) {
        return 0;
    }
    int *copy = new int[length];
    for (int i = 0; i < length; i++) {
        copy[i] = data[i];
    }
    int count = InversePairsCore(data, copy, 0, length - 1);
    delete [] copy;
    return count;
}
int main(int argc, const char * argv[]) {
    int result[] = {7,4,6,5};
    int num = InversePairs(result, 4);
    
    std::cout << num << std::endl;
    return 0;
}
