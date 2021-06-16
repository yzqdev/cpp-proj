//
// Created by yanni on 2019/6/21.
//

#include "Dogspointer.h"
#include <iostream>


using namespace std;

void Dogspointer::showpointers2() {

}

void Dogspointer::showpointers1() {
    int a = 3;
    int *pa = &a;
    cout << pa << "\t" << &a << endl;
    cout << *pa << "\t" << a << endl;

#if 0
    cout << "hellow pointer";
#endif
#if 0
    int arr[] = {12, 13, 14, 15, 16};
    int *pInt = arr;//这里看出arr等于&(arr[0])   p[i]就是*(p+i);
    cout << *(pInt + 2) << "\t" << pInt[2] << "\t" << arr[2] << endl;
    for (int *q = pInt + 4; pInt < q; ++pInt) {
        cout << *pInt << "\t";
    }
    cout << "\n";
#endif
#if 0
    int *p=new int;
    *p=3;
    cout <<p<<"\t"<<*p<<endl;
    delete p;//内存泄漏
    p=new int;
    *p=5;
    cout <<p<<"\t"<<*p<<endl;
    delete p;
#endif
#if 0
    int n=4;
    int *p=new int[n];
    for (int i = 0; i < n; ++i) {
        p[i]=2*i+1;
    }
    for (int *q = p+n;p<q;p++) {
        cout <<*p <<"\t";
    }
    cout <<"\n";
#endif
#if 1
    int n = 4;
    int *p = new int[n];
    char *s = (char *) p;
    char ch = 'a';
    int n2 = n * sizeof(int) / sizeof(char);
    cout << n2 << "\t" << sizeof(int) << endl;
    for (int i = 0; i < n2; ++i) {
        s[i] = ch + i;
    }
    for (char *r = s + n2; s < r; s++) {
        cout << *s;
    }
    delete[] p;
#endif
}
