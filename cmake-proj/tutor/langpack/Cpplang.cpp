//
// Created by yanni on 2019/6/17.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "Cpplang.h"

using namespace std;

void Cpplang::openFile() {
    string s = "hello", s2("world");
    cout << s.size() << endl;
    string s3 = s.substr(1, 3);
    cout << s3 << endl;
    string s4 = "helloworld";
    int pos = s4.find("llo");
    s4.insert(3, "aaa");
    cout << pos << s4 << endl;
}

void Cpplang::cpplang2() {
int arr[4]={10,20,30,40};
    for (int i : arr) {
        cout <<i<<endl;
    }
}


void Cpplang::cpplang3() {
vector<int> vector={4,5,6,23};
vector.push_back(34);
vector.push_back(4);
    for (int i : vector) {
        cout<<i<<"\t";

    }
    vector.pop_back();
    vector.resize(3);

}

void Cpplang::cpplang4() {
int a=6;
int *p=&a;
cout <<*p<<a<<endl;
cout <<p<<&a<<endl;
}

void Cpplang::openTxt() {
    ifstream readFile;
    readFile.open("D:\\Documents\\a.log", ios::in);

    if (readFile.is_open())
    {
        cout << "文件打开成功！" << endl;
        char buff[1000] = { 0 };
        while (readFile >>buff)
        {
            cout << buff << endl;
        }
    }
    else
    {
        cout << "文件打开失败！" << endl;
    }

}


void Cpplang::cpplang6() {

}

void Cpplang::fileoperate1() {
    ofstream ofstream1("input.txt");
    ofstream1 << 123 << "" << "hello workd";
    ofstream1.close();
    cout << "out sucess" << endl;
    ifstream ifstream1("input.txt");
    string string1;
    double d;
    ifstream1 >> d >> string1;
    cout << d << "" << string1;
}

void Cpplang::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Cpplang::transfer() {
    int a = 5, b = 3;
    cout << "a=" << a << "" << "b=" << b << endl;
    swap(&a, &b);
    cout << "a=" << a << "" << "b=" << b << endl;
}

void Cpplang::overload() {

}

void Cpplang::print(char c, int i) {
    for (int j = 0; j < i; ++j) {
        cout << c << endl;
    }
}

/**
 * 这个是非常好用的模板
 * @tparam tname
 * @param x
 * @param y
 * @return
 */
template<typename tname>
tname add(tname x, tname y) {
    return x + y;
}

void Cpplang::ctemplate() {
    cout << add(3, 4) << endl;
    cout << add(3.4, 5.4) << endl;
}

void Cpplang::sendpocket() {

}


