// the-best-excavator.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int school[100005] = { 0 };
int main()
{
	int T, school_num, scores;
	scanf("%d", &T);
	while (T--)
	{
		cin >> school_num;
		cin >> scores;
		school[school_num] += scores;
	}
	scores = 0;//�������������ܳɼ�
	for (int i = 0; i < 100005; i++)
	{
		if (school[i] > scores)
		{
			scores = school[i];
			school_num = i;
		}
		//�п�����ѧ��һֱ��0�����Ա����������β��
	}
	cout << school_num << " " << scores;
    return 0;
}

