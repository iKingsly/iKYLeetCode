//
//  main.cpp
//  剑指offer:面试题43:n个骰子点数
//
//  Created by 郑钦洪 on 16/6/30.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <math.h>
int g_maxValue = 6;
void Probability (int original, int current, int sum, int *pProbabilities) {
    if (current == 1) {
        pProbabilities[sum - original]++;
    } else {
        for (int i = 1; i <= g_maxValue; i++) {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
}

void Probability (int number, int *pProbabilities) {
    for (int i = 1; i <= g_maxValue; i++) {
        Probability(number, number, i, pProbabilities);
    }
}

void PrintProbability (int number) {
    if (number < 1) {
        return;
    }
    
    int maxSum = number * g_maxValue;
    int * pProbabilities = new int[maxSum - number + 1];
    for (int i = number; i <= maxSum; i++) {
        pProbabilities[i - number] = 0;
    }
    
    Probability(number, pProbabilities);
    
    int total = pow(double(g_maxValue), number);
    
    for (int i = number; i <= maxSum; i++) {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d : %e\n", i, ratio);
    }
    
    delete [] pProbabilities;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    PrintProbability(2);
    std::cout << "Hello, World!\n";
    return 0;
}
