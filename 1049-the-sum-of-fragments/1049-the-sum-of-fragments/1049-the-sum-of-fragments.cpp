// 1049-the-sum-of-fragments.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include <stdio.h>
float nums[100005];
int main()
{
	int length;
	scanf("%d", &length);
	double result = 0.0;
	for (int i = 0; i < length; i++)
	{
		scanf("%f", &nums[i]);
	}
	for (int i = 0; i < length; i++)
	{
		//���ȼ�����ֵ��ܸ���
		int index = i, times = 0;
		if (index >= length / 2)
			index = length - i - 1;
		//index�Ƕ�Ӧ�Ĵ�����һ��
		times += ((index+1)*(index + 2)) / 2;
		//���ǽ��������ȵ����
		
		//��ѭ������ʱ�ˡ�����
		/*
		for (int j = index + 2; j <= length; j++)
		{
			times += (length - j + 1) > (index + 1) ? index+1 :length-j+1 ;
		}
		*/
		
		if (2 * index + 2 < length)
		{
			times += (length - 2 * index - 1) * (index + 1);
			times += (index * (index + 1)) / 2;
		}
		else
		{
			times += (2 * index - length + 3) * (index + 1);
			times += (index * (index + 1)) / 2;
		}
		
		//printf("%d-%d\n", i, times);
		result += nums[i] * times;
	}
	printf("%.2f\n", result);
    return 0;
}

