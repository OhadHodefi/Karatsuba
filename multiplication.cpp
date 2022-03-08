#include "multiplication.h"

using namespace std;
multiplication::multiplication(int n, int* xrr, int* yrr) :_n(n)
{
	X_arr = new int[n];
	Y_arr = new int[n];
	_res = new int[2 * n];
	for (int i = 0; i < n; i++)
	{
		const_cast<int&>(X_arr[i]) = xrr[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		const_cast<int&>(Y_arr[i]) = yrr[i];
	}
}

multiplication::~multiplication()
{
	delete[] X_arr;
	delete[] Y_arr;
}

void multiplication::mult1()
{
	cout << endl << endl;
	int multX = _n, multY = _n, temp, carry = 0;
		
	for (int i = 0; i < 2 * _n; i++)
	{
		_res[i] = 0;
	}

	for (int i = _n-1; i >=0; i--)
	{
		for (int j = _n - 1; j >= 0; j--)
		{
			temp = X_arr[i] * Y_arr[j] + carry;
			_res[multX + multY-1] = _res[multX + multY-1] + temp % 10;
			carry = (temp / 10) + (_res[multX + multY-1] / 10);
			_res[multX + multY-1] = _res[multX + multY-1] % 10;
			multY--;
		}
		while (carry != 0)
		{
			_res[multX + multY-1] = _res[multX + multY-1] + (carry % 10);
			carry = carry / 10;
			multY--;
		}
		multX--;
		multY = _n;
	}
	print(1);
}


void multiplication::mult2Rec()
{
	int* xrr = new int[_n];
	int* yrr = new int[_n];
	int* res;
	copyArr(xrr,_n,X_arr);
	copyArr(yrr,_n,Y_arr);
	_res = recHelper(_n, xrr, yrr);
	print(2);

}

int* multiplication::recHelper(int n, int* xrr, int* yrr)
{
	if (n == 1)
	{
		int* res = new int[2];
		res[0] = (xrr[0] * yrr[0]) / 10;
		res[1] = (xrr[0] * yrr[0]) % 10;
		return res;
	}
	else
		if (n % 2 == 0)
		{
			//sizeof(arr) = sizeof(brr) = sizeof(crr) = sizeof(drr)
			int sizeOfArr = n / 2;
			int* arr = new int[sizeOfArr];
			int* brr = new int[sizeOfArr];
			int* crr = new int[sizeOfArr];
			int* drr = new int[sizeOfArr];

			//input data in arr, brr, crr, drr
			copyArr(arr, sizeOfArr, xrr);
			copyArr(brr, sizeOfArr, xrr + sizeOfArr);
			copyArr(crr, sizeOfArr, yrr);
			copyArr(drr, sizeOfArr, yrr + sizeOfArr);
			int sizeOfSumArr = sizeOfArr + 1;
			int*aPlusB = new int[sizeOfSumArr];
			int*cPlusd = new int[sizeOfSumArr];

			//aPlusB = arr + brr
			//cPlusd = crr + drr
			sum2Arr(arr, brr, sizeOfArr, sizeOfArr, aPlusB, sizeOfSumArr);
			sum2Arr(crr, drr, sizeOfArr, sizeOfArr, cPlusd, sizeOfSumArr);

			int sizeOfac = sizeOfArr * 2, sizeOfaPbMcPd = sizeOfSumArr * 2, sizeofbd = sizeOfArr * 2;
			int* ac = new int[sizeOfac];
			int* aPbMcPd;
			int* bd = new int[sizeofbd];


						// call to recursion
			ac = recHelper(sizeOfArr, arr, crr);
			if (aPlusB[0] == 0 && cPlusd[0] == 0)
			{
				sizeOfaPbMcPd = sizeOfaPbMcPd - 2;
				aPbMcPd = new int[sizeOfaPbMcPd];
				aPbMcPd = recHelper(sizeOfSumArr - 1, aPlusB + 1, cPlusd + 1);
			}
			else
			{
				aPbMcPd = new int[sizeOfaPbMcPd];
				aPbMcPd = recHelper(sizeOfSumArr, aPlusB, cPlusd);
			}
			bd = recHelper(sizeOfArr, brr, drr);


			//subArr = (arr + brr)*(crr + drr) - ac - bd
			int sizeOfSubArr = sizeOfaPbMcPd;
			int* subArr = new int[sizeOfSubArr];
			sub3Arr(aPbMcPd, sizeOfaPbMcPd, ac, sizeOfac, bd, sizeofbd, subArr, sizeOfSubArr);

			int sizeOfacMove = sizeOfac + n, sizeOfsubArrMove = sizeOfSubArr + (n / 2);
			int* acMove = new int[sizeOfacMove];
			int* subArrMove = new int[sizeOfsubArrMove];

			//moving the arr n cells, and n/2 cells
			move(ac, sizeOfac, acMove, sizeOfacMove, n);
			move(subArr, sizeOfSubArr, subArrMove, sizeOfsubArrMove, n / 2);

			int sizeOfRes = 2 * n;
			int* res = new int[sizeOfRes];
			sum3Arr(acMove, sizeOfacMove, subArrMove, sizeOfsubArrMove, bd, sizeofbd, res, sizeOfRes);
	
			delete[] arr;
			delete[] brr;
			delete[] crr;
			delete[] drr;
			delete[] aPlusB;
			delete[] cPlusd;
			delete[] ac;
			delete[] bd;
			delete[] aPbMcPd;
			delete[] subArr;
			delete[] acMove;
			delete[] subArrMove;

			return res;
		}
		else
		{
			//we want n even so we can do 10^(n/2)
			n++;
			int sizeOfArr = n / 2;
			//sizeof(arr) = sizeof(brr) = sizeof(crr) = sizeof(drr)

			int* arr = new int[sizeOfArr];
			int* brr = new int[sizeOfArr];
			int* crr = new int[sizeOfArr];
			int* drr = new int[sizeOfArr];
			
			//input data in arr, brr, crr, drr
			//becose n was odd, we ant in arr[0] = 0, crr[0] = 0
			arr[0] = crr[0] = 0;
			copyArr(arr + 1, sizeOfArr - 1, xrr);
			copyArr(brr, sizeOfArr, xrr + sizeOfArr - 1);
			copyArr(crr + 1, sizeOfArr - 1, yrr);
			copyArr(drr, sizeOfArr, yrr + sizeOfArr - 1);

			int sizeOfSumArr = sizeOfArr + 1;
			int*aPlusB = new int[sizeOfSumArr];
			int*cPlusd = new int[sizeOfSumArr];

			//aPlusB = arr + brr
			//cPlusd = crr + drr
			sum2Arr(arr, brr, sizeOfArr, sizeOfArr, aPlusB, sizeOfSumArr);
			sum2Arr(crr, drr, sizeOfArr, sizeOfArr, cPlusd, sizeOfSumArr);

			int sizeOfac = sizeOfArr * 2, sizeOfaPbMcPd = sizeOfSumArr * 2, sizeofbd = sizeOfArr * 2;
			int* ac = new int[sizeOfac];
			int* aPbMcPd;
			int* bd = new int[sizeofbd];

			// call to recursion
			ac = recHelper(sizeOfArr, arr, crr);
			if (aPlusB[0] == 0 && cPlusd[0] == 0)
			{
				sizeOfaPbMcPd = sizeOfaPbMcPd - 2;
				aPbMcPd = new int[sizeOfaPbMcPd];
				aPbMcPd = recHelper(sizeOfSumArr - 1, aPlusB + 1, cPlusd + 1);
			}
			else
			{
				aPbMcPd = new int[sizeOfaPbMcPd];
				aPbMcPd = recHelper(sizeOfSumArr, aPlusB, cPlusd);
			}
			bd = recHelper(sizeOfArr, brr, drr);

			//subArr = (arr + brr)*(crr + drr) - ac - bd
			int sizeOfSubArr = sizeOfaPbMcPd;
			int* subArr = new int[sizeOfSubArr];
			sub3Arr(aPbMcPd, sizeOfaPbMcPd, ac, sizeOfac, bd, sizeofbd, subArr, sizeOfSubArr);

			int sizeOfacMove = sizeOfac + n, sizeOfsubArrMove = sizeOfSubArr + (n / 2);
			int* acMove = new int[sizeOfacMove];
			int* subArrMove = new int[sizeOfsubArrMove];

			//moving the arr n cells, and n/2 cells
			move(ac, sizeOfac, acMove, sizeOfacMove, n);
			move(subArr, sizeOfSubArr, subArrMove, sizeOfsubArrMove, n / 2);

			int sizeOfPreRes = 2 * n;
			int* PreRes = new int[sizeOfPreRes];
			sum3Arr(acMove, sizeOfacMove, subArrMove, sizeOfsubArrMove, bd, sizeofbd, PreRes, sizeOfPreRes);

			n--;
			int sizeOfRes = 2 * n;
			int* res = new int[sizeOfRes];
			copyArr(res, sizeOfRes, PreRes + 2);//preRes is biger from the reail result in 2 cells cous we make n++

			//delete all arrays Except from res
			delete[] arr;
			delete[] brr;
			delete[] crr;
			delete[] drr;
			delete[] aPlusB;
			delete[] cPlusd;
			delete[] ac;
			delete[] bd;
			delete[] aPbMcPd;
			delete[] subArr;
			delete[] acMove;
			delete[] subArrMove;
			delete[] PreRes;

			return res;
		}
}

void multiplication::copyArr(int* toArr, int sizeofTo, const int* fromArr)
{
	for (int i = 0; i < sizeofTo; i++)
	{
		toArr[i] = fromArr[i];// const_cast<int&>(fromArr[i]);
	}
}

void multiplication::sum2Arr(int* arr1, int* arr2, int size1, int size2, int* sumArr, int sizeOfSumArr)
{
	insertToZero(sumArr,sizeOfSumArr);

	for (int i = sizeOfSumArr - 1; i >= 0; i--)
	{
		if (size1 - 1 >= 0)
		{
			sumArr[i] = sumArr[i] + arr1[size1 - 1];
			size1--;
		}
		if (size2 - 1 >= 0)
		{
			sumArr[i] = sumArr[i] + arr2[size2 - 1];
			size2--;
		}
	}
	carrysolver(sumArr, sizeOfSumArr);
}

void multiplication::carrysolver(int* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] >= 10)
		{
			arr[i - 1] = arr[i - 1] + (arr[i] / 10);
			arr[i] = arr[i] % 10;
		}
	}
}

void multiplication::insertToZero(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

void multiplication::sub3Arr(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int* subArr, int sizeOfSubArr)
{
	insertToZero(subArr, sizeOfSubArr);

	for (int i = sizeOfSubArr - 1; i >= 0; i--)
	{
		subArr[i] = arr1[size1 - 1];
		size1--;
		if (size2 - 1 >= 0)
		{
			subArr[i] = subArr[i] - arr2[size2 - 1];
			size2--;
		}

		if (size3 - 1 >= 0)
		{
			subArr[i] = subArr[i] - arr3[size3 - 1];
			size3--;
		}
	}

	for (int i = sizeOfSubArr - 1; i >= 0; i--)
	{
		if (subArr[i] < -10)
		{
			subArr[i - 1] = subArr[i-1] - 2;
			subArr[i] = subArr[i] + 20;
		}
		if ((subArr[i] < 0) && (subArr[i] >= -10))
		{
			subArr[i - 1] = subArr[i - 1] - 1;
			subArr[i] = subArr[i] + 10;
		}
	}
}

void multiplication::move(int* sorce, int sizeOfSorce, int* MoveArr, int sizeOfMoveArr, int sizeOfMoves)
{
	insertToZero(MoveArr, sizeOfMoveArr);

	for (int i = 0; i < sizeOfSorce; i++)
	{
		MoveArr[i] = sorce[i];
	}
}

void multiplication::sum3Arr(int* arr1, int size1, int* arr2, int size2, int* arr3, int size3, int* res, int sizeOfRes)
{
	insertToZero(res, sizeOfRes);

	for (int i = sizeOfRes - 1; i >= 0; i--)
	{
		if (size1 - 1 >= 0)
		{
			res[i] = res[i] + arr1[size1 - 1];
			size1--;
		}
		if (size2 - 1 >= 0)
		{
			res[i] = res[i] + arr2[size2 - 1];
			size2--;
		}
		if (size3 - 1 >= 0)
		{
			res[i] = res[i] + arr3[size3 - 1];
			size3--;
		}
	}

	carrysolver(res, sizeOfRes);
}

void multiplication::print(int val)
{
	if (val == 1)
	{
		cout << "Long multiplication: x * y = ";
	
	
	}
	else
		if (val == 2)
		{
			cout << "Karatsuba (recursive): x * y = ";
		}
		else {
			cout << "Karatsuba(iterative) : x * y =";
		}
	bool flag = true;
	for (int i = 0; i < 2*_n; i++)
	{
		if ((_res[i] == 0) && (flag == true))
		{ }
		else
		{
			flag = false;
			cout << _res[i];
		}
	}
	if (flag == true)
	{
		cout << _res[0];
	}
	cout << endl;
}

void multiplication::mult3()
{
	stack S; // Stack which simulates the recursion.
	ItemType Curr; // Values of current “recursive call” // Values of next “recursive call”.
	Curr.Set_n(_n);
	Curr.Set_Xrr(X_arr, Curr.get_n());
	Curr.Set_Yrr(Y_arr, Curr.get_n());
	ItemType temp(Curr);
	S.Push(temp);
	

	int* res = nullptr;
	int returnFromRecursion = 0;


	do {
		if (returnFromRecursion)
			Curr = S.Pop();
		if (Curr.get_line() == START) {
			if (Curr.get_n() == 1) {
				res = new int[2];
				res[0] = (Curr.get_xrr()[0] * Curr.get_yrr()[0]) / 10;
				res[1] = (Curr.get_xrr()[0] * Curr.get_yrr()[0]) % 10;
				returnFromRecursion = 1;
			}
			else {
				if (Curr.get_n() % 2 == 0) //if the number is even
				{
					Curr.Set_isEven(true);
					int sizeOfArr = (Curr.get_n()) / 2;
					Curr.Set_sizeofarr(sizeOfArr);
					int sizeOfSumArr = sizeOfArr + 1;
					Curr.Set_sizeofsum(sizeOfSumArr);
				
					int* arr = new int[sizeOfArr];
					int* brr = new int[sizeOfArr];
					int* crr = new int[sizeOfArr];
					int* drr = new int[sizeOfArr];

					//input data in arr, brr, crr, drr
					copyArr(arr, sizeOfArr, Curr.get_xrr());
					copyArr(brr, sizeOfArr, Curr.get_xrr() + sizeOfArr);
					copyArr(crr, sizeOfArr, Curr.get_yrr());
					copyArr(drr, sizeOfArr, Curr.get_yrr() + sizeOfArr);
					Curr.Set_arr(arr);
					Curr.Set_brr(brr);
					Curr.Set_crr(crr);
					Curr.Set_drr(drr);

					int*aPlusB = new int[sizeOfSumArr];
					int*cPlusd = new int[sizeOfSumArr];

					sum2Arr(arr, brr, sizeOfArr, sizeOfArr, aPlusB, sizeOfSumArr);
					sum2Arr(crr, drr, sizeOfArr, sizeOfArr, cPlusd, sizeOfSumArr);

					Curr.Set_aPlusb(aPlusB);
					Curr.Set_cPlusd(cPlusd);

					Curr.Set_sizeOfac(sizeOfArr * 2);
					Curr.Set_sizeOfaPbMcPd(sizeOfSumArr * 2);
					Curr.Set_sizeofbd(sizeOfArr * 2);
				
					delete[] arr;
					delete[] brr;
					delete[] crr;
					delete[] drr;
					delete[] aPlusB;
					delete[] cPlusd;
				}
				else //if the number is odd
				{
					Curr.Set_isEven(false);
					int newN = 1 + Curr.get_n();
					Curr.Set_n(newN);
					int sizeOfArr = newN / 2;
					Curr.Set_sizeofarr(sizeOfArr);
					int sizeOfSumArr = sizeOfArr + 1;
					Curr.Set_sizeofsum(sizeOfSumArr);
					
					int* arr = new int[sizeOfArr];
					int* brr = new int[sizeOfArr];
					int* crr = new int[sizeOfArr];
					int* drr = new int[sizeOfArr];

					//input data in arr, brr, crr, drr
					arr[0] = crr[0] = 0;
					copyArr(arr + 1, sizeOfArr - 1, Curr.get_xrr());
					copyArr(brr, sizeOfArr, Curr.get_xrr() + sizeOfArr - 1);
					copyArr(crr + 1, sizeOfArr - 1, Curr.get_yrr());
					copyArr(drr, sizeOfArr, Curr.get_yrr() + sizeOfArr - 1);


					Curr.Set_arr(arr);
					Curr.Set_brr(brr);
					Curr.Set_crr(crr);
					Curr.Set_drr(drr);

					int*aPlusB = new int[sizeOfSumArr];
					int*cPlusd = new int[sizeOfSumArr];

					sum2Arr(arr, brr, sizeOfArr, sizeOfArr, aPlusB, sizeOfSumArr);
					sum2Arr(crr, drr, sizeOfArr, sizeOfArr, cPlusd, sizeOfSumArr);

					Curr.Set_aPlusb(aPlusB);
					Curr.Set_cPlusd(cPlusd);

					Curr.Set_sizeOfac(sizeOfArr * 2);
					Curr.Set_sizeOfaPbMcPd(sizeOfSumArr * 2);
					Curr.Set_sizeofbd(sizeOfArr * 2);

					delete[] arr;
					delete[] brr;
					delete[] crr;
					delete[] drr;
					delete[] aPlusB;
					delete[] cPlusd;

				}
				Curr.Set_line(AFTER_FIRST);
				S.Push(Curr);
				Curr.Set_n((Curr.get_n())/2);
				Curr.Set_Xrr(Curr.get_arr(), Curr.get_n());
				Curr.Set_Yrr(Curr.get_crr(), Curr.get_n());
				Curr.Set_line(START);

				returnFromRecursion = 0;
			}
		}
		else if (Curr.get_line() == AFTER_FIRST) 
		{
			Curr.Set_ac(res);
			delete[] res;
			Curr.Set_line(AFTER_SECOND);

			if (Curr.get_aPlusb()[0] == 0 && Curr.get_cPlusd()[0] == 0)
			{
				Curr.Set_sizeOfaPbMcPd(Curr.get_sizeOfaPbMcPd() - 2);
				S.Push(Curr);

				Curr.Set_n(Curr.get_sizeOfSumArr() - 1);
				Curr.Set_Xrr(Curr.get_aPlusb() +1, Curr.get_n());
				Curr.Set_Yrr(Curr.get_cPlusd() +1, Curr.get_n());
			}
			else
			{
				S.Push(Curr);
				Curr.Set_n(Curr.get_sizeOfSumArr());
				Curr.Set_Xrr(Curr.get_aPlusb(), Curr.get_n());
				Curr.Set_Yrr(Curr.get_cPlusd(), Curr.get_n());
			}

			Curr.Set_line(START);
			returnFromRecursion = 0;
		}
		else if (Curr.get_line() == AFTER_SECOND) 
		{
			Curr.Set_aPbMcPd(res);
			delete[] res;

			Curr.Set_line(AFTER_THIRD);
			S.Push(Curr);

			Curr.Set_n(Curr.get_sizeOfarr());
			Curr.Set_Xrr(Curr.get_brr(), Curr.get_n());
			Curr.Set_Yrr(Curr.get_drr(), Curr.get_n());
			Curr.Set_line(START);
			returnFromRecursion = 0;
		}
		else if (Curr.get_line() == AFTER_THIRD) 
		{
			Curr.Set_bd(res);
			delete[] res;
			returnFromRecursion = 1;

			//subArr = (arr + brr)*(crr + drr) - ac - bd
			int sizeOfSubArr = Curr.get_sizeOfaPbMcPd();
			int* subArr = new int[sizeOfSubArr];
			sub3Arr(Curr.get_aPbMcPd(), Curr.get_sizeOfaPbMcPd(), Curr.get_ac(), Curr.get_sizeOfac(), Curr.get_bd(), Curr.get_sizeOfbd(), subArr, sizeOfSubArr);

			int sizeOfacMove = Curr.get_sizeOfac() + Curr.get_n();
			int sizeOfsubArrMove = (sizeOfSubArr + Curr.get_n() / 2) ;
			int* acMove = new int[sizeOfacMove];
			int* subArrMove = new int[sizeOfsubArrMove];

			//moving the arr n cells, and n/2 cells
			move(Curr.get_ac(), Curr.get_sizeOfac(), acMove, sizeOfacMove, Curr.get_n());
			move(subArr, sizeOfSubArr, subArrMove, sizeOfsubArrMove, (Curr.get_n()) / 2);


			if (Curr.get_isEven() == true)
			{
				int sizeOfRes = 2 * Curr.get_n();
				res = new int[sizeOfRes];
				sum3Arr(acMove, sizeOfacMove, subArrMove, sizeOfsubArrMove, Curr.get_bd(), Curr.get_sizeOfbd(), res, sizeOfRes);
			}
			else
			{
				int sizeOfPreRes = 2 * Curr.get_n();
				int* PreRes = new int[sizeOfPreRes];
				sum3Arr(acMove, sizeOfacMove, subArrMove, sizeOfsubArrMove, Curr.get_bd(), Curr.get_sizeOfbd(), PreRes, sizeOfPreRes);
				Curr.Set_n(Curr.get_n() - 1);
				int sizeOfRes = 2 * Curr.get_n();
				res = new int[sizeOfRes];
				copyArr(res, sizeOfRes, PreRes + 2);//preRes is biger from the reail result in 2 cells cous we make n++
			}
			delete[] subArr;
			delete[] acMove;
			delete[] subArrMove;
		}
			
	}while (!S.isEmpty());
	copyArr(_res, 2*Curr.get_n() ,res);

	delete[] res;
	print(3);
}

