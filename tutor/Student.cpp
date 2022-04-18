//
// Created by yanni on 2019/6/18.
//
#include <vector>
#include <iostream>
#include "Student.h"

using namespace std;


void Student::showarraystudent() {
    vector<Student> students;
//    cout << students.size();
    cout << "输入姓名分数:"<<endl;
    while (1) {
        Student s;
        cin >> s.name >> s.score;
        students.push_back(s);
        if (s.score < 0) { break; }
        for (auto &i : students) {
            i.showpointers();
        }
        double min = 100, max = 0, average = 0;
        for (auto &everyst : students) {
            if (everyst.score < min) {
                min = everyst.score;
            }
            if (everyst.score > max) {
                max = everyst.score;
            }
average=everyst.score+average;
        }
        average=average/students.size();
        cout<<"平均分,最高分,最低分是"<<average<<","<<max<<","<<min<<endl;
    }

}

void Student::showpointers() {
    cout << name << score;
}
