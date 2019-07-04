#include <fstream>
#include <iostream>
using namespace std;

#include "FileOperate.h"
/**
 *
 * @return
 */
int FileOperate::showfile(){

    char data[10];
    ofstream outfile;
    outfile.open("1.txt");
    cout <<"writing" <<endl;
    cout <<"enter you name";
    cin.getline(data,10);
    outfile <<data <<endl;
    cout <<"enter age";
    cin >>data;
    cin.ignore();
    outfile <<data <<endl;
    outfile.close();
    return  0;
}
int FileOperate::openfile() {
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("NumOperate.cpp");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("NumOperate.cpp");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

    return 0;
}
