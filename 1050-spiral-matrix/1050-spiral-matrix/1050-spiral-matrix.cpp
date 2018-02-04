// 1050-spiral-matrix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getn(int N);
bool cmp(int a, int b);

int main()
{
	int N, m, n;
	cin >> N;
	//n�Ƚ�С�����Բ���ֱ����
	//�ۣ�������ܶ�����Ŷ...����ֱ��--�����ܳ˳����������
	n = getn(N);
	m = N / n;
	//����������
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		//��������ȫ���Ե���������
		scanf("%d", &a[i]);
	}
	//sortֵ����������
	sort(a.begin(), a.end(),cmp );
	//��ά����
	vector<vector <int>> b(m, vector<int>(n));
	//���������ȣ�ͨ��ȡģ���жϼӲ��ӡ�
	int level = m / 2 + m % 2, t = 0;
	for (int i = 0; i < level; i++)
	{
		//��ʼһȦһȦ������
		//��д���ŵģ�ע������ļ�һ�ǽű������
		for (int j = i; j <= n - i - 1 && t <= N-1; j++)
			//t++д��������棬�ǳ�����-��-
			b[i][j] = a[t++];
		for (int j = i + 1; j <= m - i - 2 && t <= N - 1; j++)
			b[j][n - i - 1] = a[t++];
		for (int j = n - i - 1; j >= i && t <= N-1; j--)
			b[m - i - 1][j] = a[t++];
		for (int j = m - i - 2; j >= i + 1 && t <= N-1; j--)
			b[j][i] = a[t++];
	}
	//������ֱ�������
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", b[i][j]);
			if (j != n - 1)
				printf(" ");
		}
		cout << endl;
	}
    return 0;
}

int getn(int N)
{
	int n = int(sqrt(N));
	while (n >= 1)
	{
		if (N % n == 0)
			return n;
		n--;
	}
	//����ֵ����/�ָ���һ������
	return 1;
}

bool cmp(int a, int b)
{
	return a > b;
}