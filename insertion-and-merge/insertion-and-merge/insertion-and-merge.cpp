// insertion-and-merge.cpp : 定义控制台应用程序的入口点。
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
	//两个输入
	int i, j;
	//寻找到已经排好序的那个点
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
	//接下来是没有输入的
	for (j = i + 1; a[j] == b[j] && j < n; j++);
	if (j == n)
	{
		cout << "Insertion Sort" << endl;
		//再插入一个元素进行排序
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
				//模拟排序，寻找b所处的位置。
				if (a[i] != b[i])
				{
					flag = 1;
					break;
				}
			}
			k = k * 2;//不断变大的序列
			for (i = 0; i < n / k; i++)
				//一组一组的进行排序。
				sort(a + i*k, a + (i + 1)*k);
			sort(a + n / k*k, a + n);
		}

	}
	//输出
	for (j = 0; j < n; j++)
	{
		if (j != 0)
			cout << " ";//如何不在结尾输出空格
		cout << a[j];
	}
	delete [] a;
	delete [] b;

    return 0;
}

