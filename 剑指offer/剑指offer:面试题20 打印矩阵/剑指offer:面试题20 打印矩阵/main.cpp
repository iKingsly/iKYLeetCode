//
//  main.cpp
//  剑指offer:面试题20 打印矩阵
//
//  Created by 郑钦洪 on 16/6/11.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
void PrintMatrixInCircle(int **numbers, int columns, int rows, int start){
    // endX 总的colums - 当前Y
    int endX = columns - 1 - start;
    // endY 总的rows - 当前Y
    int endY = rows - 1 - start;
    
    // 从左到右打印一行
    for (int i = start; i <= endX ; i++) {
        int number = numbers[start][i];
        printf("%d",number);
    }
    
    // 从上到下打印一行
    if (start < endY) {
        for (int i = start + 1; i <= endY; i++) {
            int number = numbers[i][endX];
            printf("%d",number);
        }
    }
    
    // 从右到左打印一行
    if (start<endX && start < endY) {
        for (int i = endX - 1; i >= start; i--) {
            int number = numbers[endY][i];
            printf("%d",number);
        }
    }

    // 从下到上打印一列
    if (start < endX && start < endY) {
        for (int i = endY - 1; i >= start; i--) {
            int number = numbers[i][start];
            printf("%d",number);
        }
    }
}

void PrintMatrixClookisely(int **numbers, int columns, int rows){
    if (numbers == NULL || columns <= 0 || rows <= 0) {
        return;
    }
    int start = 0;
    // 每次打印的起始点x与y都是相同的 所以用start来标记
    while (columns > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
