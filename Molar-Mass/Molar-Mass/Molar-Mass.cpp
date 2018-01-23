// Molar-Mass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "string.h"
#include "ctype.h"

#define maxn 50

/*
��������Molar Mass, ACM/ICPC Seoul 2007, UVa1586��
����һ�����ʵķ���ʽ���������ţ�����������������еķ���ʽֻ����4��ԭ�ӣ���
��ΪC, H, O, N��ԭ�����ֱ�Ϊ12.01, 1.008, 16.00, 14.01����λ��g/mol�������磬C6H5OH��
������Ϊ94.108g/mol��
*/

int main()
{
	char molecular[maxn];
	int number = 0;
	double mass = 0.0;
	//������ɡ�
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
			//���ǵ������ж��λ
			num = num * 10 + molecular[number] - '0';
			number++;
		}
		if (num == 0)
			num++;//û�����ֵ����
		mass += num * alphaToNumber[element];
	}
	printf("%lfg/mol\n", mass);
	getchar();
    return 0;
}

