//
//  main.cpp
//  剑指offer:面试题44:扑克牌的顺子
//
//  Created by 郑钦洪 on 16/7/1.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
int compare (const void *arg1, const void *arg2) {
    return *(int *)arg1 - *(int *)arg2;
}

// 0. 利用快排进行排序
// 1. 查找数组中小王的牌数 也就是0的数目
// 2. 判断是否有相等的数 有的话不可能是顺子
// 3. 判断排序完后的数组，相邻两数的间隔差是否会超过0的数目
bool IsContinuous (int *numbers ,int length) {
    if (numbers == NULL || length < 1) {
        return false;
    }
    
    qsort(numbers, length, sizeof(int), compare);
    
    int numberOfZero = 0;
    int numberOfGap = 0;
    
    for (int i = 0; i < length && numbers[i] == 0; i++) {
        numberOfZero++;
    }
    
    int index = numberOfZero;
    int nextIndex = index + 1;
    
    while (nextIndex < length) {
        if (numbers[nextIndex] > 12 || numbers[index] > 12) { // 没有大于12的牌
            return false;
        }
        if (numbers[index] == numbers[nextIndex]) {
            return false;
        }
        
        numberOfGap += numbers[nextIndex] - numbers[index] - 1;
        index++;
        nextIndex++;
    }
    
    return (numberOfGap <= numberOfZero) ? true : false;
}
int main(int argc, const char * argv[]) {
    
    int numbers [] = {1,2,4,4,0};
    bool result = IsContinuous(numbers, 5);
    printf("%d \n", result);
    return 0;
}
