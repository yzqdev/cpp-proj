//
// Created by yanni on 2019/6/17.
//
#include <iostream>
#include "DynamicMemory.h"
using  namespace std;


int DynamicMemory::dynamic() {
    double* pvalue  = NULL; // 初始化为 null 的指针
    pvalue  = new double;   // 为变量请求内存

    *pvalue = 29494.99;     // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;

    delete pvalue;         // 释放内存

    return 0;
}


