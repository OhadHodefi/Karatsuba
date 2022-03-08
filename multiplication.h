#pragma once
#include <iostream>
#include "stack.h"
#include <cstring>

class multiplication
{
private:
	int _n;
	const int* X_arr;
	const int* Y_arr;
	int* _res;

	int* recHelper(int n, int* xrr, int* yrr);
	void copyArr(int* toArr, int sizeofTo, const int* fromArr);
	void sum2Arr(int* arr1, int* arr2, int size1, int size2, int* sumArr, int sizeOfSumArr);
	void carrysolver(int* arr, int size);
	void insertToZero(int* arr, int size);
	void sub3Arr(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int* subArr, int sizeOfSubArr);
	void move(int* sorce, int sizeOfSorce, int* MoveArr, int sizeOfMoveArr, int sizeOfMoves);
	void sum3Arr(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int* res, int sizeOfRes);

public:
	multiplication(int n ,int* xrr = nullptr, int* yrr = nullptr);
	~multiplication();
	void mult1();
	void mult2Rec();
	void mult3();
	void print(int val);
	void printArr(int size, int* arr);



};

