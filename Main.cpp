#include <iostream>
#include "NumOperate.h"
#include "FileOperate.h"
#include "func/Pointers.h"
#include "MyExcetion.h"
#include "Peektest.h"
#include "langpack/Clang.h"
#include "langpack/Cpplang.h"
#include "Student.h"
#include "Datatype.h"
#include "Pointers/Dogspointer.h"
#include "Temp.h"

using namespace std;


// 程序的主函数
int main() {
    Clang clang;
    Cpplang cpplang;
    cpplang.transfer();
//    cpplang.print('4',5);
//    cpplang.ctemplate();
//    cpplang.cpplang2();
//    cpplang.cpplang4();
    Student stdent;
//    stdent.showarraystudent();
    Datatype datatype;
//    datatype.showdatatype();
    Dogspointer dogs;
//    dogs.showpointers1();
    Temp tEmp;
    tEmp.study();
}