//
// Created by yanni on 2019/6/17.
//
#include <iostream>
#include <ctime>
#include "NumOperate.h"

using namespace std;

int NumOperate::numbershow() {

    int i, j;

    // 设置种子
    srand((unsigned) time(NULL));

    /* 生成 10 个随机数 */
    for (i = 0; i < 10; i++) {
        // 生成实际的随机数
        j = rand();
        cout << "随机数： " << j << endl;
    }

    return 0;
}


double NumOperate::division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int NumOperate::mainoperate() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const char *msg) {
        cerr << msg << endl;
    }

    return 0;
}