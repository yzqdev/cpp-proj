//
// Created by yanni on 2019/6/17.
//
#include <iostream>
#include <exception>

using namespace std;
#ifndef CPP1_MYEXCETION_H
#define CPP1_MYEXCETION_H

struct MyException : public exception {
    const char *what() const noexcept override;

    void throwecp();
};


#endif //CPP1_MYEXCETION_H
