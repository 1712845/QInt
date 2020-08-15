#pragma once
#include "CQInt.h"
#include<math.h>
#define _MAX_BIT_	128


//Áp dụng design patter: singleton cho lớp chuyển đổi này
class CConvert
{
protected:
	static CConvert *m_Instance;
	//Hàm tạo.
	CConvert();
	//Hàm hủy.
	~CConvert();
public:
	//Hàm lấy đối tượng.
	
	static CConvert* getInstance();
	string StrDectoBin(string&);
	static CQInt CQInttoTwosComplement(CQInt);
	string CQInttoBinaryString(CQInt&);
	string StrHextoBin(string&);
	string StrBintoHex(string&);
	string StrInttoTwosComplement(string&);
	string SubNumberString(string a, string b);
	string StrBintoDec(string&);
	string AddNumberString(string a, string b);
	string MultiplyNumberString(string a, string b);
	//string DivisionNumberString(string a, string b);
};
bool CheckNegative(string &s);