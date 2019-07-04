//
// Created by yanni on 2019/6/21.
//
#include <iostream>
#include <windows.h>
#include <cstdio>
#include "String.h"

char *data;
int n;
using namespace std;

void String::showasm() {
    int a = 111;
    int b = 222;
    int sum = 0;
    int &a1 = a;
    cout << a << "," << a1 << endl;

}
