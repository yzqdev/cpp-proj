#include <stdio.h>
#include <fileapi.h>
#include "main.h"

/* for 循环 */
int forLoop(int n) {
    int res = 0;
    // 循环求和 1, 2, ..., n-1, n
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}
void getData(){
    printf("hhh");
}
int main() {
    printf("Hello, World!\n");
    getData();
    printf(forLoop(33));
    return 0;
}