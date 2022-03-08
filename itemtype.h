#pragma once
#define START 0
#define AFTER_FIRST 1
#define AFTER_SECOND 2
#define AFTER_THIRD 3
#include <iostream>
#include <cstring>

using namespace std;

class ItemType
{
private:
	int _n;
	int* _xrr;
	int* _yrr;
	int* _arr;
	int* _brr;
	int* _crr;
	int* _drr;
	int _sizeOfarr;
	int* _aPlusb;
	int* _cPlusd;
	int _sizeOfSumArr;
	int* _ac;
	int _sizeOfac;
	int* _aPbMcPd;
	int _sizeOfaPbMcPd;
	int* _bd;
	int _sizeOfbd;
	int _line;
	bool _isEven;
public:
	ItemType(int n = 0, int* x = nullptr, int* y = nullptr, int* arr = nullptr, int* brr = nullptr, int* crr = nullptr, int* drr = nullptr, int sizeOfarr = 0, int* aPlusb = nullptr, int* cPlusd = nullptr,
		int sizeOfSumArr = 0, int* ac = nullptr, int sizeOfac = 0, int* aPbMcPd = nullptr, int sizeOfaPbMcPd = 0, int* bd = nullptr, int sizeOfbd = 0, int line = 0,bool _isEven=true);
	ItemType(const ItemType &other);
	void Set_line(const int line) { _line = line; }
	void Set_Xrr(const int* x, const int size);

	void Set_Yrr(const int* y, const int size);
	void Set_n(const int n) { _n=n; }
	
	void Set_sizeofarr(const int sizeofarr) { _sizeOfarr = sizeofarr; }
	void Set_sizeofsum(const int sumofarr) { _sizeOfSumArr = sumofarr; }

	void Set_arr(const int* arr);
	void Set_brr(const int* brr);
	void Set_crr(const int* crr);
	void Set_drr(const int* drr);
	void Set_aPlusb(const int* aPlusb);
	void Set_cPlusd(const int* cPlusd);
	void Set_isEven(const bool isEven);


	void Set_sizeOfac(const int sizeofac);
	void Set_sizeOfaPbMcPd(const int sizeofapbmcpd);
	void Set_sizeofbd(const int sizeofbd);


	void Set_ac(const int* ac);
	void Set_aPbMcPd(const int* aPbMcPd);
	void Set_bd(const int* bd);

	int get_n()const { return _n; }
	int* get_xrr()const { return _xrr; }
	int* get_yrr()const { return _yrr; }
	int* get_arr()const { return _arr; }
	int* get_brr()const {return _brr; }
	int* get_crr()const {return _crr; }
	int* get_drr()const {return _drr; }
	int get_sizeOfarr()const {return _sizeOfarr; }
	int* get_aPlusb()const {return _aPlusb; }
	int* get_cPlusd()const {return _cPlusd; }
	int get_sizeOfSumArr()const {return _sizeOfSumArr; }
	int* get_ac()const {return _ac; }
	int get_sizeOfac()const {return _sizeOfac; }
	int* get_aPbMcPd()const {return _aPbMcPd; }
	int get_sizeOfaPbMcPd()const {return _sizeOfaPbMcPd; }
	int* get_bd()const {return _bd; }
	int get_sizeOfbd()const {return _sizeOfbd; }
	int get_line()const {return _line; }
	bool get_isEven()const { return _isEven; }
};

