#pragma warning(disable:4996)
#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <string>
using namespace std;


#define _BIT_INT64_		64
#define _POSITION		((Binary.size() - 1 - i) / _BIT_INT64_) //Vị trí Vùng 4 Byte cần ghi vào.
#define _SHIFT_OFFSET	(((Binary.size() - 1) % _BIT_INT64_) - (i % _BIT_INT64_)) //Số bit cần dời.

class CQInt
{
protected:
	__int64 ArrayBits[2] = { 0,0 };
public:
	//Hàm khỏi tạo bằng cách truyền vào chuỗi bit nhị phân.
	CQInt();
	CQInt(const string&);
	//Hàm hủy dữ liệu của kiểu QInt.
	~CQInt();

	//Hàm lấy data.
	__int64* getData();


	//Phép phủ định.
	CQInt& operator ~ ();

	//Kiểm tra =0.
	bool isZero();

	void Init();                        //Khoi Tao Bang 0
	void operator = (const string &K);  //Gan Truc Tiep 1 Chuoi [[NEED TO FIX]]]
	void operator = (const CQInt &K);    //Gan 1 CQInt Khac
	//___________________________________________________________________
	int GetBit(int K);                  //Lay Bit Khu K
	void TurnOnBit(int K);              //Bat bit 1 Tai vi Tri K
	void TurnOffBit(int K);				//Tat bit Tai vi Tri K
	void Get_Data();					//Xuat //[[[[[NEED TO FIX]]]]]]
	//___________________________________________________________________

	//___________________________________________________________________
	CQInt operator & (CQInt K);			//Operator AND
	CQInt operator | (CQInt K);			//Operator OR
	CQInt operator ^ (CQInt K);			//Operaror XOR
	//___________________________________________________________________
	CQInt operator <<(const int &K);		//Operator Shift Left Logical 
	CQInt operator >>(const int &K);		//Operator Shift Arithmetic Right 
	//___________________________________________________________________
	CQInt ROL();							//Rotate Left 
	CQInt ROR();							//Rotate Right
	CQInt operator-(CQInt); // Phép trừ
	CQInt operator+(CQInt); // Phép cộng
	CQInt operator*(CQInt); // Phép nhân
};

#endif 

