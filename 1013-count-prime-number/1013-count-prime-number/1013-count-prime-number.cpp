// 1013-count-prime-number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <cstdio>
#include <iostream>

using namespace std;

bool isPrime(long long a);

int main()
{
	int begin_num, end_num, count = 0;
	int flag = 0;
	long long i = 2;
	cin >> begin_num >> end_num;
	while (count <= end_num)
	{
		if (isPrime(i))
		{
			//如果是素数，第几个素数
			count++;
			if (count >= begin_num && count <= end_num)
			{
				//进行输出
				flag++;
				if (count != end_num && flag != 10)
					cout << i << " ";
				else
					cout << i;
				if (flag == 10)
				{
					//决定是否换行
					cout << endl;
					flag = 0;
				}
			}
		}
		i++;
	}
    return 0;
}

bool isPrime(long long a)
{
	//之前写的素数好像有点问题
	for (int i = 2; i*i <= a; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

