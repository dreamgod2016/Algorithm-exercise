// (3n+1)-first.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int number, times = 0;
	cin >> number;
	while (number != 1)
	{
		if (number %2 ==0)
		{
			number /= 2;
		}
		else
		{
			number = (3 * number + 1) / 2;
		}
		times++;
	}
	cout << times;
    return 0;
}

