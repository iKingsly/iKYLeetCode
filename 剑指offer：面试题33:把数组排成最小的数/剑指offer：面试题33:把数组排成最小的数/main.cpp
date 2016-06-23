//
//  main.cpp
//  剑指offer：面试题33:把数组排成最小的数
//
//  Created by 郑钦洪 on 16/6/23.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//bool compare(const string &src1, const string &src2) {
//    string s1 = src1 + src2;
//    string s2 = src2 + src1;
//    return s1 > s2;
//}
//
//void comArrayMin (int *pArray, int num) {
//    int i;
//    string *pStrArray = new string[num];
//    
//    for (i = 0 ; i < num; i++) {
//        stringstream stream;
//        stream<<pArray[i];
//        stream>>pStrArray[i];
//    }
//    
//    sort(pStrArray, pStrArray + num, compare);
//    
//    for (i = 0; i < num; i++) {
//        cout<<pStrArray[i];
//    }
//    cout<<endl;
//    
//    delete [] pStrArray;
//    
//}

//重新定义比较函数对象
struct compare
{
    bool operator() (const string &src1, const string &src2)
    {
        string s1 = src1 + src2;
        string s2 = src2 + src1;
        return s1 < s2;   //升序排列，如果改为s1 > s2则为逆序排列
    }
};
//函数功能 ： 把数组排成最小的数
//函数参数 ： pArray为数组,num为数组元素个数
//返回值 ：   无
void ComArrayMin(int *pArray, int num)
{
    int i;
    string *pStrArray = new string[num];
    
    for(i = 0; i < num; i++) //将数字转换为字符串
    {
        stringstream stream;
        stream<<pArray[i];
        stream>>pStrArray[i];
    }
    
    sort(pStrArray, pStrArray + num, compare()); //字符串数组排序
    
    for(i = 0; i < num; i++) //打印字符串数组
        cout<<pStrArray[i];
    cout<<endl;
    
    delete [] pStrArray;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int num[3] = {3,32,321};
    ComArrayMin(num, 3);
    return 0;
}
