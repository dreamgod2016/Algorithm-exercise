// 1062-simplest-fraction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int gcd(int a, int b);

int main()
{
	int n1, n2, m1, m2, k, i = 1, num = 0;
	double range1, range2, result = 0.0;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	//ͻȻ���ĸ���᲻�������
	range1 = (double)n1 / m1;
	range2 = (double)n2 / m2;
	//����Ľ����һ������ԭ�е�˳��
	if (n1*m2 > n2*m1)
	{
		swap(n1, n2);
		swap(m1, m2);
		//	swap(range1, range2);

	}
	while (i*m2 < k*n2)
	{
		//result = (double)i / k;
		//���Ի���
		//ע�⣡���ﲻ��������ȵģ���Ȼ���Ե�3����ȥ@��@
		if (gcd(k, i) == 1 && i * m1 > k*n1 && i*m2 < k*n2)
		{
			//���������Ļ�
			//������ô���
			if (num != 0)
				cout << " ";
			cout << i << "/" << k;
			num++;
		}
		//������ǻ��ʵĻ�
		i++;
	}

    return 0;
}

//�д�����
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}