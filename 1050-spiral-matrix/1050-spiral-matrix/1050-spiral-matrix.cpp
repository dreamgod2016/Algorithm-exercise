// 1050-spiral-matrix.cpp : 定义控制台应用程序的入口点。
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
	//n比较小，所以不入直接舍
	//哇，这里面很多问题哦...不能直接--，可能乘出来结果不对
	n = getn(N);
	m = N / n;
	//接下来输入
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		//哇塞，完全可以当数组用诶
		scanf("%d", &a[i]);
	}
	//sort值得整理整理
	sort(a.begin(), a.end(),cmp );
	//二维数组
	vector<vector <int>> b(m, vector<int>(n));
	//这个计算很稳，通过取模来判断加不加。
	int level = m / 2 + m % 2, t = 0;
	for (int i = 0; i < level; i++)
	{
		//开始一圈一圈的输入
		//先写横着的，注意这里的减一是脚标的问题
		for (int j = i; j <= n - i - 1 && t <= N-1; j++)
			//t++写在这个里面，非常方便-。-
			b[i][j] = a[t++];
		for (int j = i + 1; j <= m - i - 2 && t <= N - 1; j++)
			b[j][n - i - 1] = a[t++];
		for (int j = n - i - 1; j >= i && t <= N-1; j--)
			b[m - i - 1][j] = a[t++];
		for (int j = m - i - 2; j >= i + 1 && t <= N-1; j--)
			b[j][i] = a[t++];
	}
	//接下来直接输出了
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
	//真的轮到最后/分给我一个质数
	return 1;
}

bool cmp(int a, int b)
{
	return a > b;
}