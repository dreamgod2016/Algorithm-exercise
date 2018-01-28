// prime-pair.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"
#include <iostream>
#include <set>

using namespace std;

bool isPrime(int num);
int getNextPrime(int nowPrime);

set<int> prime_pair;
int main()
{
	for (int nowPrime = 2; nowPrime <= 100000; )
	{
		int nextPrime = getNextPrime(nowPrime);
		if (nextPrime - nowPrime == 2)
		{
			//这里存较大的数
			prime_pair.insert(nextPrime);
		}
		nowPrime = nextPrime;//继续移动。
	}

	int num, count = 0;
	cin >> num;
	for (set<int>::iterator it = prime_pair.begin(); it != prime_pair.end() && *it<=num; it++)
	{
		//有一个条件不满足，就不进行下去了。
		count += 1;
	}
	cout << count;
    return 0;
}

int getNextPrime(int nowPrime)
{
	//死循环，总会找到下一个素数的。
	do
	{
		nowPrime++;
		if (isPrime(nowPrime))
			return nowPrime;
	} while (true);
}

bool isPrime(int num)
{
	//判断是否是素数
	if (num == 2)
		return true;
	int numSqrt = sqrt(num)+1;
	for (int i = 2; i <= numSqrt; i++)
	{
		//有整除就不是啦
		if (num % i == 0)
			return false;
	}
	return true;
}

