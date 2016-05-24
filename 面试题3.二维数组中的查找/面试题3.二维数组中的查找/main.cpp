//
//  main.cpp
//  面试题3.二维数组中的查找
//
//  Created by 郑钦洪 on 16/5/24.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
bool Find(int *matrix, int rows, int columns , int number){
    bool Found = false;
    if (rows < 1 || columns < 1 || matrix == NULL ) {
        return false;
    }
    int row = 0, column = columns - 1;
    while (column > 0 && row < rows) {
        if (matrix[row * columns + column] > number){
            column--;
        }else if(matrix[row * columns + column] < number){
            row++;
        }else{
            Found = true;
            break;
        }
    }
    return Found;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[16] = {1,2,8,9,2,4,9,12,4,7,10,13};
    bool result = Find(a, 4, 4, 10);
    printf("%d",result);
    return 0;
}
