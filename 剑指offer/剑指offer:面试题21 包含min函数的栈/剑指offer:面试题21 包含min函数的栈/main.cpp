//
//  main.cpp
//  剑指offer:面试题21 包含min函数的栈
//
//  Created by 郑钦洪 on 16/6/11.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <stack>
using std::stack;
using namespace std;
bool IsPopOrder(const int *pPush, const int * pPop, int nLength){
    bool bPossible = false;
    if (pPush != NULL && pPop != NULL && nLength > 0) {
        const int * pNextPush = pPush;
        const int * pNextPop = pPop;
        
        std::stack<int>stackData;
        while (pNextPop - pPop < nLength) {
            while (stackData.empty() || stackData.top() != *pNextPop) {
                // 如果辅助栈的元素与弹出栈的不一样 就往下压元素到辅助栈种
                if (pNextPush - pPush == nLength) { // 如果栈到底了 说明是错误的顺序
                    break;
                }
                stackData.push(*pNextPush);
                pNextPush++;
            }
            if (stackData.top() != *pNextPop) { // 不相同就break
                break;
            }
            
            stackData.pop();
            pNextPop++;
        }
        
        if (stackData.empty() && pNextPop - pPop == nLength) {
            bPossible = true;
        }
    }
    return bPossible;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
