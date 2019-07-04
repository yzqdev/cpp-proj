//
// Created by yanni on 2019/6/17.
//
#include <iostream>
#include <exception>
#include "MyExcetion.h"

using namespace std;

void MyException::throwecp() {
    try {
        throw MyException();
    }
    catch (MyException &e) {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e) {
        //其他的错误
    }
}

const char *MyException::what() const noexcept {
    return "C++ Exception";
}
