// insertion-and-merge.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	//��������
	int i, j;
	//Ѱ�ҵ��Ѿ��ź�����Ǹ���
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
	//��������û�������
	for (j = i + 1; a[j] == b[j] && j < n; j++);
	if (j == n)
	{
		cout << "Insertion Sort" << endl;
		//�ٲ���һ��Ԫ�ؽ�������
		sort(a, a + i + 2);
	}
	else 
	{
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1;
		while (flag)
		{
			flag = 0;
			for (i = 0; i < n; i++)
			{
				//ģ������Ѱ��b������λ�á�
				if (a[i] != b[i])
				{
					flag = 1;
					break;
				}
			}
			k = k * 2;//���ϱ�������
			for (i = 0; i < n / k; i++)
				//һ��һ��Ľ�������
				sort(a + i*k, a + (i + 1)*k);
			sort(a + n / k*k, a + n);
		}

	}
	//���
	for (j = 0; j < n; j++)
	{
		if (j != 0)
			cout << " ";//��β��ڽ�β����ո�
		cout << a[j];
	}
	delete [] a;
	delete [] b;

    return 0;
}

