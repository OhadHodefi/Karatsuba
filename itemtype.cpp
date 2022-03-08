#include "itemtype.h"

ItemType::ItemType(int n, int* x, int* y, int* arr, int* brr, int* crr, int* drr, int sizeOfarr, int* aPlusb, int* cPlusd,
	int sizeOfSumArr, int* ac, int sizeOfac, int* aPbMcPd, int sizeOfaPbMcPd, int* bd, int sizeOfbd, int line, bool isEven)
	:_xrr(x),_yrr(y),_arr(arr), _brr(brr), _crr(crr), _drr(drr), _aPlusb(aPlusb), _cPlusd(cPlusd), _ac(ac), _aPbMcPd(aPbMcPd),
	_bd(bd), _n(n), _sizeOfarr(sizeOfarr), _sizeOfSumArr(sizeOfSumArr), _sizeOfac(sizeOfac), _sizeOfaPbMcPd(sizeOfaPbMcPd), _sizeOfbd(sizeOfbd), _line(line),_isEven(isEven)
{}

ItemType::ItemType(const ItemType &other) {
	_xrr = _yrr = _arr =_brr = _crr = _drr = _aPlusb = _cPlusd = _ac = _aPbMcPd = _bd = nullptr;
	_sizeOfarr = other._sizeOfarr;
	_sizeOfSumArr = other._sizeOfSumArr;
	_sizeOfac = other._sizeOfac;
	_sizeOfaPbMcPd = other._sizeOfaPbMcPd;
	_sizeOfbd = other._sizeOfbd;
	_line = other._line;
	_isEven = other._isEven;
	_n = other._n;
	Set_Xrr(other._xrr, other.get_n());
	Set_Yrr(other._yrr, other.get_n());
	Set_arr(other._arr);
	Set_brr(other._brr);
	Set_crr(other._crr);
	Set_drr(other._drr);
	Set_aPlusb(other._aPlusb);
	Set_cPlusd(other._cPlusd);
	Set_ac(other._ac);
	Set_aPbMcPd(other._aPbMcPd);
	Set_bd(other._bd);
}

void ItemType::Set_sizeOfac(const int sizeofac)
{
	_sizeOfac = sizeofac;
}

void ItemType::Set_sizeOfaPbMcPd(const int sizeofapbmcpd)
{
	_sizeOfaPbMcPd = sizeofapbmcpd;
}

void ItemType::Set_sizeofbd(const int sizeofbd)
{
	_sizeOfbd = sizeofbd;
}

void ItemType::Set_ac(const int* ac)
{
	if(ac != nullptr)
	{
		if (_ac != nullptr)
		{
			delete[] _ac;
		}
		_ac = new int[_sizeOfac];
		memcpy(_ac, ac, sizeof(int)*_sizeOfac);
	}
}

void ItemType::Set_aPbMcPd(const int* aPbMcPd)
{
	if (aPbMcPd != nullptr)
	{
		if (_aPbMcPd != nullptr)
		{
			delete[] _aPbMcPd;
		}
		_aPbMcPd = new int[_sizeOfaPbMcPd];
		memcpy(_aPbMcPd, aPbMcPd, sizeof(int)*_sizeOfaPbMcPd);
	}
}

void ItemType::Set_bd(const int* bd)//////////////////לעדכן
{
	if (bd != nullptr)
	{
		if (_bd != nullptr)
		{
			delete[] _bd;
		}
		_bd = new int[_sizeOfbd];
		memcpy(_bd, bd, sizeof(int)*_sizeOfbd);
	}
}

void ItemType::Set_Xrr(const int* x,const int size)
{	
	if (x!=nullptr)
	{
		if (_xrr != nullptr)
		{
			delete[] _xrr;
		}
		_xrr = new int[size];
		memcpy(_xrr, x, sizeof(int)*size);
	}

}

void ItemType::Set_Yrr(const int* y,const int size)
{
	if (y != nullptr)
	{
		if (_yrr != nullptr)
		{
			delete[] _yrr;
		}
		_yrr = new int[size];
		memcpy(_yrr, y, sizeof(int)*size);
	}

}


void ItemType::Set_arr(const int* arr)
{
	if (arr != nullptr)
	{
		if (_arr != nullptr)
		{
			delete[] _arr;
		}
		_arr = new int[_sizeOfarr];
		memcpy(_arr, arr, sizeof(int)*_sizeOfarr);
	}

}
void ItemType::Set_brr(const int* brr)
{
	if (brr != nullptr)
	{
		if (_brr != nullptr)
		{
			delete[] _brr;
		}
		_brr = new int[_sizeOfarr];
		memcpy(_brr, brr, sizeof(int)*_sizeOfarr);
	}
}
void ItemType::Set_crr(const int* crr)
{
	if (crr != nullptr)
	{
		if (_crr != nullptr)
		{
			delete[] _crr;
		}
		_crr = new int[_sizeOfarr];
		memcpy(_crr, crr, sizeof(int)*_sizeOfarr);
	}

}
void ItemType::Set_drr(const int* drr)
{
	if (drr != nullptr)
	{
		if (_drr != nullptr)
		{
			delete[] _drr;
		}
		_drr = new int[_sizeOfarr];
		memcpy(_drr, drr, sizeof(int)*_sizeOfarr);
	}

}
void ItemType::Set_aPlusb(const int* aPlusb)
{
	if (aPlusb != nullptr)
	{
		if (_aPlusb != nullptr)
		{
			delete[] _aPlusb;
		}
		_aPlusb = new int[_sizeOfSumArr];
		memcpy(_aPlusb, aPlusb, sizeof(int)*_sizeOfSumArr);
	}

}
void ItemType::Set_cPlusd(const int* cPlusd)
{
	if (cPlusd != nullptr)
	{
		if (_cPlusd != nullptr)
		{
			delete[] _cPlusd;
		}
		_cPlusd = new int[_sizeOfSumArr];
		memcpy(_cPlusd, cPlusd, sizeof(int)*_sizeOfSumArr);

	}

}
void ItemType::Set_isEven(const bool isEven)
{
	_isEven = isEven;
}



