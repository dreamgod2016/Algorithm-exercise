// Molar-Mass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "ctype.h"

#define maxn 50

/*
分子量（Molar Mass, ACM/ICPC Seoul 2007, UVa1586）
给出一种物质的分子式（不带括号），求分子量。本题中的分子式只包含4种原子，分
别为C, H, O, N，原子量分别为12.01, 1.008, 16.00, 14.01（单位：g/mol）。例如，C6H5OH的
分子量为94.108g/mol。
*/

int main()
{
	char molecular[maxn];
	int number = 0;
	double mass = 0.0;
	//这里存疑。
	double alphaToNumber[5];
	alphaToNumber['C'] = 12.01;
	alphaToNumber['H'] = 1.008;
	alphaToNumber['O'] = 16.00;
	alphaToNumber['N'] = 14.01;
	scanf_s("%s", molecular, sizeof(molecular));
	while (molecular[number] != '\0')
	{
		int num = 0;
		char element = molecular[number];
		number++;
		while (isdigit(molecular[number]))
		{
			//考虑到可能有多个位
			num = num * 10 + molecular[number] - '0';
			number++;
		}
		if (num == 0)
			num++;//没有数字的情况
		mass += num * alphaToNumber[element];
	}
	printf("%lfg/mol\n", mass);
	getchar();
    return 0;
}

