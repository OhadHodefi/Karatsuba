#include <iostream>
#include <string>
#include "multiplication.h"
#include <chrono>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	bool isInputOk = true;
	int n;
	string numOfDigits = "";
	std::cin >> numOfDigits;
	bool firstNumber = false;
	int i = 0;
	for (i = 0; i < numOfDigits.size(); i++)
	{
		if (numOfDigits[i] == '0' && firstNumber == false) {
			std::cout << "wrong output" << std::endl;
			isInputOk = false;
			break;
		}
		if (numOfDigits[i] >= '0' && numOfDigits[i] <= '9') {
			firstNumber = true;
		}
		else {
			isInputOk = false;
			std::cout << "wrong output" << std::endl;
			break;
		}
	}

	if (isInputOk == false) {
		exit(1);
	}
	n = std::stoi(numOfDigits);

	string xStr = "";
	string yStr = "";

	int* x = new int[n];
	std::cin >> xStr;
	if (xStr.size() < n || xStr.size() > n) {
		std::cout << "wrong output" << std::endl;
		exit(1);
	}

	for (i = 0; i < xStr.size(); i++)
	{
		if (xStr[i] < '0' || xStr[i] > '9') {

			isInputOk = false;
			std::cout << "wrong output" << std::endl;
			break;
		}
		else
		{
			x[i] = xStr[i] - '0';
		}
	}


	int* y = new int[n];
	if (isInputOk == false)
	{
		exit(1);
	}

	std::cin >> yStr;
	if (yStr.size() < n || yStr.size() > n) {
		std::cout << "wrong output" << std::endl;
		exit(1);
	}

	for (i = 0; i < yStr.size(); i++)
	{
		if (yStr[i] < '0' || yStr[i] > '9') {

			isInputOk = false;
			std::cout << "wrong output" << std::endl;
			break;
		}
		else
		{
			y[i] = yStr[i] - '0';
		}
	}

	if (isInputOk == false)
	{
		exit(1);
	}

	multiplication arr(n, x, y);

	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	arr.mult1();
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
	chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function <mult1> is : " << fixed
	<< time_taken << setprecision(9);
	myfile << " sec" << endl;





	start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	arr.mult2Rec();
	end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	time_taken =
	chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function <mult2Rec> is : " << fixed
	<< time_taken << setprecision(9);
	myfile << " sec" << endl;






	start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	arr.mult3();
	end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	time_taken =
	chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	myfile << "Time taken by function <mult3> is : " << fixed
	<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();


	delete[] x;
	delete[] y;








}