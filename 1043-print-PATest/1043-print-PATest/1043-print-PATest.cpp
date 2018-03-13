// 1043-print-PATest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>	

using namespace std;

int main()
{
	char temp;
	//map������ʼ��Ϊ0�������Ҫ��ʼ����ô��
	map<char, int> symbols;
	while ((temp = cin.get()) != '\n')
	{
		symbols[temp]++;
	}
	while (symbols['P'] > 0 || symbols['A'] > 0 || symbols['T'] > 0 || symbols['e'] > 0 || symbols['s'] > 0 || symbols['t'] > 0)
	{
		//���--����Ȥ��~
		if (symbols['P']-- > 0)
			cout << 'P';
		if (symbols['A']-- > 0)
			cout << 'A';
		if (symbols['T']-- > 0)
			cout << 'T';
		if (symbols['e']-- > 0)
			cout << 'e';
		if (symbols['s']-- > 0)
			cout << 's';
		if (symbols['t']-- > 0)
			cout << 't';
	}
	return 0;
}

