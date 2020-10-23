//
// Created by yanni on 2019/6/19.
//

#include "Temp.h"
#include <iostream>

using namespace std;

int Temp::study() {
#if 0
    int m = 5, n = 6;
    swapfunc(&m, &n);
    cout << m << "," << n;
    return 0;
#endif
#if 1
    int m = 5, n = 6;
    swapfun(m, n);
    cout << m << "," << n;
    return 0;
#endif
}

void Temp::swapfunc(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * 这里只是交换了a和b实参的副本，而它们本身没有交换
 * @param a
 * @param b
 */
void Temp::swapfun(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

