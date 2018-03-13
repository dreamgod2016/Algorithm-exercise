// 1043-print-PATest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>	

using namespace std;

int main()
{
	char temp;
	//map这里会初始化为0吗？如果想要初始化怎么办
	map<char, int> symbols;
	while ((temp = cin.get()) != '\n')
	{
		symbols[temp]++;
	}
	while (symbols['P'] > 0 || symbols['A'] > 0 || symbols['T'] > 0 || symbols['e'] > 0 || symbols['s'] > 0 || symbols['t'] > 0)
	{
		//这个--很有趣诶~
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

