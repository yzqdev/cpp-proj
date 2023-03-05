#include "MainMethod.h"
#include "Algorithm.h"
#include "DataStruct.h"
#include <iostream>
using namespace std;
MainMethod::MainMethod()
{
	cout << "mainmethod" << endl;
}

MainMethod::~MainMethod()
{
}

inline void MainMethod::exceAlgorithm()
{
	Algorithm algo;
	cout << "Hello World!\n";

	//algo.bucketSort();
	//a.bubbleSort();
	//a.quickSortMain();
	algo.getBooks();
}

void MainMethod::exceDatastruct()
{
	DataStruct datastruc;
	//datastruc.getQueue();
	datastruc.getPlalindrome();
}