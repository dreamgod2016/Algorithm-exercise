// prime-pair.cpp : �������̨Ӧ�ó������ڵ㡣
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
			//�����ϴ����
			prime_pair.insert(nextPrime);
		}
		nowPrime = nextPrime;//�����ƶ���
	}

	int num, count = 0;
	cin >> num;
	for (set<int>::iterator it = prime_pair.begin(); it != prime_pair.end() && *it<=num; it++)
	{
		//��һ�����������㣬�Ͳ�������ȥ�ˡ�
		count += 1;
	}
	cout << count;
    return 0;
}

int getNextPrime(int nowPrime)
{
	//��ѭ�����ܻ��ҵ���һ�������ġ�
	do
	{
		nowPrime++;
		if (isPrime(nowPrime))
			return nowPrime;
	} while (true);
}

bool isPrime(int num)
{
	//�ж��Ƿ�������
	if (num == 2)
		return true;
	int numSqrt = sqrt(num)+1;
	for (int i = 2; i <= numSqrt; i++)
	{
		//�������Ͳ�����
		if (num % i == 0)
			return false;
	}
	return true;
}

