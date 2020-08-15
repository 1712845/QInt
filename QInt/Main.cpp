#include"CQInt.h"
#include"CConvert.h"
int main()
{
	//string A = "11101100";
	string A = "1100";
	string B = "1000";
	string C;
	CQInt D(A);
	CQInt E(B);
	A = CConvert::getInstance()->StrBintoDec(A);
	B = CConvert::getInstance()->StrBintoDec(B);
	//C = CConvert::getInstance()->SubNumberString(A,B);
	E*D;
	system("pause");
	return 0;
}