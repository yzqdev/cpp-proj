//
// Created by yanni on 2019/6/18.
//

#include "AddScore.h"
#include "Student.h"
#include <iostream>

using namespace std;

void AddScore::showscores() {
    Student student;
    Student *p = &student;//*p指向student
    (*p).name = 'l';//p指向类对象成员score
    p->score = 34;
    Student students[3];
    p = students + 3;//指向第四个student对象
    p->name = '3';
}
