// BigInteger.cpp : 定义控制台应用程序的入口点。
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
		//构造函数
		*this = num;
	}
	//赋值操作的定义
	BigInteger operator = (long long num)
	{
		s.clear();//先清空
		do
		{
			s.push_back(num % BASE);//取后面的几位push
			num /= BASE;
		} while (num > 0);
		return *this;
	}

	
};


int main()
{
    return 0;
}

