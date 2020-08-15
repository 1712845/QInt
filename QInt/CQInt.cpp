#include "CQInt.h"
#include"CConvert.h"

CQInt::CQInt()
{

}

//Lớp số nguyên lớn được xây dụng cới dữ liệu được lưu theo Little Endian.
CQInt::CQInt(const string &Binary)
{
	for (size_t i = 0; i < Binary.size(); i++)
	{
		if (Binary[i] == '1')
		{
			long long y = 1;
			ArrayBits[_POSITION] = ArrayBits[_POSITION] | (y << _SHIFT_OFFSET);
			//Công thức này được tạo thành do chuỗi có vị trí bắt đầu ngược so với chuổi bit thực sự
		}
	}
}


CQInt::~CQInt()
{
}

__int64* CQInt::getData()
{
	return ArrayBits;
}



CQInt& CQInt::operator ~ ()
{
	for (int i = 0; i < 2; i++)
	{
		ArrayBits[i] = ~ArrayBits[i];
	}
	return *this;
}

bool CQInt::isZero()
{
	for (int i = 0; i < 2; i++)
	{
		if (ArrayBits[i] != 0)
		{
			return false;
		}
	}
	return true;
}

void CQInt::Init() //Khoi tao bang 0
{
	ArrayBits[0] = 0;
	ArrayBits[1] = 0;
}
//_____________________________________________
void CQInt :: operator =  (const string &K) //Operator Gan truc tiep 1 Chuoi //CAN XOA
{ //[[[NEED TO FIX]]]
	__int64 tamp = 0;
	for (int i = K.length() - 1; i >= 0; i--)
	{
		if (K[i] != '0') ArrayBits[0] += pow(2, tamp);
		tamp++;
	}
}
void CQInt :: operator =  (const CQInt &K) //Operator Gan CQInt
{
	ArrayBits[0] = K.ArrayBits[0];
	ArrayBits[1] = K.ArrayBits[1];
}
//_____________________________________________
int  CQInt::GetBit(int K) //Lay Bit Vi Tri k
{
	return (ArrayBits[K / 64] >> (K % 64)) & 1;
}
void CQInt::TurnOnBit(int K)//Bat Bit Vi Tri k Len 1
{
	__int64 tamp = 1;
	ArrayBits[K / 64] = ArrayBits[K / 64] | (tamp << (K % 64));
}
void CQInt::TurnOffBit(int K)//Tat Vi Tri Bit K=0
{
	__int64 tamp = 1;
	ArrayBits[K / 64] = ArrayBits[K / 64] & (~(tamp << (K % 64)));
}
void CQInt::Get_Data() //[[NEED TO FIX]]]
{
	for (int i = 8; i >= 0; i--) cout << this->GetBit(i) << " ";
	cout << endl;
}
//_____________________________________________

//_____________________________________________
CQInt CQInt :: operator &  (CQInt K) //Operator & (AND)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) & this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
CQInt CQInt :: operator |  (CQInt K) //Operator | (OR)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) | this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
CQInt CQInt :: operator ^  (CQInt K) //Operator ^ (XOR)
{
	CQInt tamp; tamp.Init();
	for (int i = 0; i < 128; i++)
	{
		if (K.GetBit(i) ^ this->GetBit(i)) tamp.TurnOnBit(i);
	}
	return tamp;
}
//_____________________________________________
CQInt CQInt :: operator <<(const int &K) //Operator Shift Left Logical
{
	CQInt tamp;
	tamp = *this;
	*tamp.ArrayBits = *tamp.ArrayBits << K;
	return tamp;
}
CQInt CQInt :: operator >>(const int &K) //Operator Shift Arithmetic Right
{
	CQInt tamp;
	tamp = *this;
	int Bit_127 = tamp.GetBit(127);
	*tamp.ArrayBits = *tamp.ArrayBits >> K;
	if (Bit_127 == 1) TurnOnBit(127); else TurnOffBit(127);
	return tamp;
}
//_____________________________________________
CQInt CQInt::ROL() //Rotate Left
{
	CQInt tamp;
	tamp = *this;
	int Bit_127 = tamp.GetBit(127);
	*tamp.ArrayBits = *tamp.ArrayBits << 1;
	if (Bit_127) tamp.TurnOnBit(0); else tamp.TurnOffBit(0);
	return tamp;
}
CQInt CQInt::ROR() //Rotate Right
{
	CQInt tamp;
	tamp = *this;
	int Bit_0 = tamp.GetBit(0);
	*tamp.ArrayBits = *tamp.ArrayBits >> 1;
	if (Bit_0) tamp.TurnOnBit(127); else tamp.TurnOffBit(127);
	return tamp;
}
CQInt CQInt :: operator-(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->SubNumberString(tempStr1, tempStr2);
	cout << StrResult << endl;
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	cout << StrResult << endl;
	CQInt Result(StrResult);
	return Result;
}
CQInt CQInt :: operator+(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->AddNumberString(tempStr1, tempStr2);
	cout << StrResult << endl;
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	cout << StrResult << endl;
	CQInt Result(StrResult);
	return Result;
}
CQInt CQInt :: operator*(CQInt A)
{
	string StrResult;
	string tempStr1, tempStr2;
	tempStr1 = CConvert::getInstance()->CQInttoBinaryString(*this);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr1 = CConvert::getInstance()->StrBintoDec(tempStr1);		// chuyển chuỗi nhị phân sang thập phân
	tempStr2 = CConvert::getInstance()->CQInttoBinaryString(A);       // chuyển từ CInt sang chuỗi nhị phân
	tempStr2 = CConvert::getInstance()->StrBintoDec(tempStr2);		// chuyển chuỗi nhị phân sang thập phân
	StrResult = CConvert::getInstance()->MultiplyNumberString(tempStr1, tempStr2);
	cout << StrResult << endl;
	StrResult = CConvert::getInstance()->StrDectoBin(StrResult);
	cout << StrResult << endl;
	CQInt Result(StrResult);
	return Result;
}
