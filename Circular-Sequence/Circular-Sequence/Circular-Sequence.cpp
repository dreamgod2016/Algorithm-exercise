// Circular-Sequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "string.h"
#define maxn 105

/*
����Ϊn�Ļ�״����n�ֱ�ʾ�����ֱ�Ϊ��ĳ
��λ�ÿ�ʼ˳ʱ��õ������磬ͼ3-4�Ļ�״��
��10�ֱ�ʾ��
CGAGTCAGCT��GAGTCAGCTC��AGTCAGCTCG�ȡ�����Щ��ʾ���У��ֵ�����С�ĳ�
Ϊ"��С��ʾ"��
����һ������Ϊn��n��100���Ļ�״DNA����ֻ����A��C��G��T��4���ַ�����һ�ֱ�
ʾ�����������������û�״������С��ʾ�����磬CTCC����С��ʾ��
CCCT��CGAGTCAGCT����С��ʾΪAGCTCGAGTC��
*/

int isLess(const char* s, int p, int q)
{
	//�ж��ֵ����˳��p��q�ǻ�״��ʼ��λ��
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		//��ͬ������͹�����ͬ����������жϡ�
		if (s[(p + i)% length]  != s[(q + i) % length] )
			return s[(p + i) % length]  < s[(q + i) % length];
	}
	//������
	return 0;
}

int main()
{
	int Time;
	char s[maxn];
	scanf_s("%d", &Time);
	while (Time--)
	{
		scanf_s("%s", s,sizeof(s));
		int result = 0;
		int length = strlen(s);
		for (int i = 1; i < length; i++)
		{
			//�ӵڶ���Ԫ�ؿ�ʼ
			if (isLess(s, i, result))
				result = i;
		}
		//�����������
		for (int i = 0; i < length; i++)
		{
			putchar(s[(result + i) % length]);
		}
		putchar('\n');
	}
    return 0;
}

