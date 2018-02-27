// 1019-digit-black-hole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool getNumber(int num, int& the_max, int& the_min);


int main()
{
	int the_num, the_max, the_min, result = -1;
	cin >> the_num;
	while (result != 0000 && result != 6174)
	{
		getNumber(the_num, the_max, the_min);
		//接下来作差
		result = the_max - the_min;
		printf("%04d - %04d = %04d\n",the_max, the_min, result);
		//cout << the_max << " - " << the_min << " = " << result << endl;
		the_num = result;
	}
    return 0;
}

bool getNumber(int num, int& the_max, int& the_min)
{
	int numbers[4] = { 0 };
	the_max = 0, the_min = 0;
	for (int i = 0; i < 4; i++)
	{
		numbers[i] = num % 10;
		num /= 10;
	}
	sort(numbers, numbers+4);
	for (int i = 0; i < 4; i++)
	{
		the_max = the_max * 10 + numbers[3-i];
		the_min = the_min * 10 + numbers[i];
	}
	return true;
}