// BigInteger.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>

using namespace std;

struct BigInteger {
	static const int BASE = 100000000;
	static const int WIDTH = 8;

	vector<int> s;
	BigInteger(long long num = 0)
	{
		//���캯��
		*this = num;
	}
	//��ֵ�����Ķ���
	BigInteger operator = (long long num)
	{
		s.clear();//�����
		do
		{
			s.push_back(num % BASE);//ȡ����ļ�λpush
			num /= BASE;
		} while (num > 0);
		return *this;
	}

	
};


int main()
{
    return 0;
}

