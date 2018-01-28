// change-print-format.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num, hundred, ten, bit;
	cin >> num;
	bit = num % 10;
	ten = (num / 10) % 10;
	hundred = num / 100;

	string sHundred(hundred, 'B');
	string sTen(ten, 'S');
	string sBit;
	for (int i = 1; i <= bit; i++)
	{
		sBit = sBit + to_string(i);
	}
	cout << (sHundred + sTen + sBit);

    return 0;
}

