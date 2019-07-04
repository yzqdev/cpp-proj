//
// Created by yanni on 2019/6/17.
//
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <malloc.h>
#include "Clang.h"

using namespace std;

void Clang::clang1() {
    double x = 2.1;
    printf("%lf,%lf", sqrt(x), sin(x));
    char s[10] = "hello";
    puts(s);
    char ss[6];
    strcpy(s, ss);
    puts(ss);
    puts("hellowordl");
    cout << ss;
}

void Clang::clang2() {
    char s[10] = "hello";
    puts(s);
    char ss[6];
    printf("%d,%d\n", s, ss);
    strcat(s, "world");
    cout << strlen(s) << s << endl;
}

void Clang::clang3() {
    char *s = (char *) malloc(12 * sizeof(char));
    strcpy(s, "helloworld");
    puts(s);
}

void Clang::clang5() {
    string name;
    cin >> name;
    cout << "name=" << name;
}

void Clang::clang4() {

}

void Clang::clangp1() {

}
