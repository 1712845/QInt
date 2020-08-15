#include "CConvert.h"



CConvert::CConvert()
{
}

CConvert::~CConvert()
{
	if (m_Instance != NULL)
	{
		delete m_Instance;
	}
}

CConvert* CConvert::m_Instance = NULL;


CConvert* CConvert::getInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CConvert;
	}
	return m_Instance;
}

//Hàm chia một chuỗi số thập phân cho 2.
//Source: https://www.geeksforgeeks.org/divide-large-number-represented-string/
string StrDivTwo(string &number)
{
	string Result;
	int Temp = 0;

	for (int i = 0; i < number.size(); i++)
	{
		Temp = Temp * 10 + (number[i] - '0');

		if (i > 0 || (i == 0 && Temp >= 2))
		{
			Result.push_back((Temp / 2) + '0');
		}

		Temp = Temp % 2;
	}

	return Result;
}

//Kiểm tra số âm.
bool CheckNegative(string &s)
{
	if (s[0] == '-')
	{
		s.erase(s.begin());
		return true;
	}
	return false;
}

string CConvert::StrDectoBin(string&  strDec)
{
	string result;
	//Kiểm tra số có âm không?
	bool negative = CheckNegative(strDec);
	//Chuyển đổi chuỗi số nguyên sang dãy bit
	//Source: https://www.quora.com/How-do-I-convert-a-large-decimal-number-into-binary-using-string-type-array-in-C-programming
	while (strDec != "")
	{
		result.push_back(((strDec[strDec.size() - 1] - '0') % 2) + '0');
		strDec = StrDivTwo(strDec);
	}
	reverse(result.begin(), result.end());

	//Nếu là chuỗi ban đầu là số âm.
	if (negative == true)
	{
		CQInt QInt(result); //Đưa vào số kiểu CQInt.
		QInt = CQInttoTwosComplement(QInt); //Chuyển sang dạng bù 2.
		result = CQInttoBinaryString(QInt); //Đưa lại về nhị phân.
	}
	/*while (result.size() % 4 != 0 || result.size() < 8)       // thêm 0 cho đủ 8 bit
	{
		result.insert(result.begin(), '0');
	}*/
	return result;
}

CQInt CConvert::CQInttoTwosComplement(CQInt QInt)
{
	return (~QInt + CQInt("1"));
}

string CConvert::CQInttoBinaryString(CQInt &QInt)
{
	_int64* data = QInt.getData();
	string binary;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < _BIT_INT64_; j++)
		{
			long long y = 1;
			binary.push_back(((data[i] & (1 << j)) >> j) + '0');
		}
	}
	reverse(binary.begin(), binary.end());
	if (binary.find('1') != -1)
	{
		binary.erase(binary.begin(), binary.begin() + binary.find('1'));
	}
	else
	{
		binary = "";
	}
	/*while (binary.size() % 4 != 0 || binary.size() < 8)         // thêm 0 cho đủ 8 bit
	{
		binary.insert(binary.begin(), '0');
	}*/
	return binary;

}
string CConvert::StrHextoBin(string& strDec)
{
	string binary;

	for (int i = 0; i < strDec.size(); i++)
	{
		if (strDec[i] == '0') { binary += "0000"; }  // 0 từ Hex -> Bin
		else if (strDec[i] == '1') { binary += "0001"; } //
		else if (strDec[i] == '2') { binary += "0010"; }//
		else if (strDec[i] == '3') { binary += "0011"; }//				 	
		else if (strDec[i] == '4') { binary += "0100"; }//            
		else if (strDec[i] == '5') { binary += "0101"; }//
		else if (strDec[i] == '6') { binary += "0110"; }//
		else if (strDec[i] == '7') { binary += "0111"; }//
		else if (strDec[i] == '8') { binary += "1000"; }//
		else if (strDec[i] == '9') { binary += "1001"; }//
		else if (strDec[i] == 'A' || strDec[i] == 'a') { binary += "1010"; }//
		else if (strDec[i] == 'B' || strDec[i] == 'b') { binary += "1011"; }//
		else if (strDec[i] == 'C' || strDec[i] == 'c') { binary += "1100"; }//
		else if (strDec[i] == 'D' || strDec[i] == 'd') { binary += "1101"; }//
		else if (strDec[i] == 'E' || strDec[i] == 'e') { binary += "1110"; }//
		else if (strDec[i] == 'F' || strDec[i] == 'f') { binary += "1111"; } // F từ Hex -> Bin
	}
	return binary;
}
string CConvert::StrBintoHex(string& strHex)
{
	string Temp;
	string Result;
	while (strHex.size() % 4 != 0)
	{
		strHex.insert(strHex.begin(), '0'); // Thêm số không để đủ 4 bit
	}
	for (int i = 0; i < strHex.size(); i++)
	{
		Temp.push_back(strHex[i]);
		if (i % 4 == 3) //Đã nhận được 4 bit.
		{
			if (Temp == "0000") { Result.push_back('0'); }
			else if (Temp == "0001") { Result.push_back('1'); }
			else if (Temp == "0010") { Result.push_back('2'); }
			else if (Temp == "0011") { Result.push_back('3'); }
			else if (Temp == "0100") { Result.push_back('4'); }
			else if (Temp == "0101") { Result.push_back('5'); }
			else if (Temp == "0110") { Result.push_back('6'); }
			else if (Temp == "0111") { Result.push_back('7'); }
			else if (Temp == "1000") { Result.push_back('8'); }
			else if (Temp == "1001") { Result.push_back('9'); }
			else if (Temp == "1010") { Result.push_back('A'); }
			else if (Temp == "1011") { Result.push_back('B'); }
			else if (Temp == "1100") { Result.push_back('C'); }
			else if (Temp == "1101") { Result.push_back('D'); }
			else if (Temp == "1110") { Result.push_back('E'); }
			else if (Temp == "1111") { Result.push_back('F'); }
			Temp = ""; // khởi tạo lại chuỗi
		}
	}
	return Result;
}
string CConvert::StrInttoTwosComplement(string& strBin)
{
	string Temp = strBin;
	char temp;
	// Đảo bit
	for (int i = 0; i < strBin.size(); i++)
	{	if (Temp[i] == '0')
		{
			Temp[i] = '1';
		}
		else if(Temp[i] == '1')
		{
			Temp[i] ='0';
		}
	}
	// Cộng 1
	for (int i = strBin.size(); i > 0; i--)
	{
		if (Temp[i] == '0')
		{
			Temp[i] = '1';
			return Temp;
		}
		Temp[i] = '0';
	}
	return Temp ;
}
string CConvert::SubNumberString(string a, string b)
{
	int remember = 0;
	bool Negative = false;

	//Thêm các số 0 vào đầu mỗi chuỗi.
	if (a.size() > b.size())
	{
		while (a.size() != b.size())
		{
			b.insert(b.begin(), '0');
		}
	}
	else
	{
		while (a.size() != b.size())
		{
			a.insert(a.begin(), '0');
		}
	}

	//Kiểm tra a hay b lớn hơn và chuyển a thành số lớn hơn.
	if (strcmp(a.c_str(), b.c_str()) < 0)
	{
		string TempStr = a;
		a = b;
		b = TempStr;
		Negative = true; //a < b => a - b < 0
	}
	//Thực hiện phép trừ.
	for (int i = a.size() - 1; i > -1; i--)
	{
		if ((a[i] - remember) < b[i])
		{
			a[i] = (10 + a[i] - b[i] - remember) + '0';
			remember = 1;
		}
		else
		{
			a[i] = a[i] - b[i] - remember + '0';
			remember = 0;
		}
	}

	//Xóa các số 0 thừa.
	while (a[0] == '0')
	{
		a.erase(a.begin());
	}
	//Nếu vẫn còn dư (Temp != 0)
	if (Negative == true)
	{
		a.insert(a.begin(), '-');
	}
	return a;
}
string CConvert::StrBintoDec(string& strBin)         // Chưa xét trường hợp số âm
{
	string dec;
	int temp = 0;
	for (int i = strBin.size(); i > 0; i--)
	{
		temp = temp + (strBin[strBin.size() - i] - '0')*pow(2, i-1);
	}
	while (temp != 0)
	{
		dec.insert(dec.begin(),(temp % 10 + '0'));
		temp = temp / 10;
	}
	return dec;
}
string CConvert::AddNumberString(string a, string b)
{
	if (a[0] == '-' && b[0] != '-')
	{
		a.erase(a.begin());
		a = CConvert::getInstance()->SubNumberString(b, a);
	}
	else
	{
		if (b[0] == '-' && a[0] != '-')
		{
			b.erase(b.begin());
			a = CConvert::getInstance()->SubNumberString(a, b);
		}
		else
		{
			int Temp = 0;
			bool Negative = false;

			if (a[0] == '-' && b[0] == '-')
			{
				Negative = true;
			}

			//Thêm các số 0 vào đầu mỗi chuỗi.
			if (a.size() > b.size())
			{
				while (a.size() != b.size())
				{
					b.insert(b.begin(),'0');
				}
			}
			else
			{
				while (a.size() != b.size())
				{
					a.insert(a.begin(),'0');
				}
			}

			//Tiến hành cộng.
			for (int i = a.size() - 1; i > -1; i--)
			{
				Temp = Temp + a[i] + b[i] - 2*'0';
				a[i] = (Temp%10) + '0';
				Temp = Temp/10;
			}

			//Nếu vẫn còn dư (Temp != 0)
			if (Temp != 0)
			{
				a.insert(a.begin(), Temp + '0');
				Temp = 0;
			}
		}
	}

	//Xóa các số 0 thừa.
	while (a[0] == '0')
	{
		a.erase(a.begin());
	}

	return a;
}
string CConvert::MultiplyNumberString(string a, string b)
{
	string Result = "0";
	string TempStr;
	int Temp = 0;
	bool Negative = false;

	if (a[0] == '-')
	{
		if (b[0] != '-')
		{
			Negative = true;
		}
		a.erase(a.begin());
	}
	if (b[0] == '-')
	{
		if (a[0] != '-')
		{
			Negative = true;
		}
		b.erase(b.begin());
	}

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = a.size() - 1; j > -1; j--)
		{
			Temp = Temp + (a[j] - '0') * (b[b.size() - i - 1] - '0');
			TempStr.push_back((Temp % 10) + '0');
			Temp = Temp / 10;
		}
		if (Temp != 0) //Nếu vẫn còn Temp.
		{
			TempStr.push_back(Temp + '0');
			Temp = 0;
		}

		//Đảo chuỗi.
		reverse(TempStr.begin(), TempStr.end());

		//Thêm các số 0 cần thiết vào sau.
		for (int j = 0; j < i; j++)
		{
			TempStr.push_back('0');
		}

		//Cộng Result và Temp.
		Result = CConvert::getInstance()->AddNumberString(Result, TempStr);
		TempStr.clear(); //Dọn chuỗi tạm để dùng cho các bước tiếp theo.
	}

	if (Negative == true)
	{
		Result.insert(Result.begin(), '-');
	}

	return Result;
}
//string CConvert::DivisionNumberString(string number, string divisor)
//{
//	// As result can be very large store it in string 
//	string ans;
//
//	// Find prefix of number that is larger 
//	// than divisor. 
//	int idx = 0;
//	int temp = number[idx] - '0';
//	while (temp < divisor )
//		temp = temp * 10 + (number[++idx] - '0');
//
//	// Repeatedly divide divisor with temp. After  
//	// every division, update temp to include one  
//	// more digit. 
//	while (number.size() > idx)
//	{
//		// Store result in answer i.e. temp / divisor 
//		ans += (temp / divisor) + '0';
//
//		// Take next digit of number 
//		temp = (temp % divisor) * 10 + number[++idx] - '0';
//	}
//
//	// If divisor is greater than number 
//	if (ans.length() == 0)
//		return "0";
//
//	// else return ans 
//	return ans;
//}
