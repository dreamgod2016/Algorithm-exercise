// 1012-number-classification.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<int> a1;
vector<int> a2;
vector<int> a3;
vector<int> a4;
vector<int> a5;
*/
int main()
{
	int n, temp, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a1_num = 0,a2_num = 0, a3_num = 0, a4_num = 0, a5_num = 0;
	double a4_res;
	bool flag = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		switch (temp % 5)
		{
		case 0:
			if (temp % 2 == 0)
			{
				a1 += temp;
				a1_num++;
			}
			break;
		case 1:
			if (flag)
			{
				a2 += temp;
				flag = false;
			}
			else
			{
				a2 -= temp;
				flag = true;
			}
			a2_num++;
			break;
		case 2:
			a3++;
			a3_num++;
			break;
		case 3:
			a4_num++;
			a4 += temp;
			break;
		case 4:
			if (temp >= a5)
				a5 = temp;
			a5_num++;
			break;
		default:
			break;
		}
	}
	if (a1_num)
		cout << a1 << ' ';
	else
		cout << "N ";
	if (a2_num)
		cout << a2 << ' ';
	else
		cout << "N ";
	if (a3_num)
		cout << a3 << ' ';
	else
		cout << "N ";
	if (a4_num)
	{
		a4_res = (double)a4 / a4_num;
		printf("%.1f ", a4_res);
		//cout << a4_res << ' ';
	}
	else
		cout << "N ";
	if (a5_num)
		cout << a5 << endl;
	else
		cout << "N\n";


	//printf("%d %d %d %.1f %d\n", a1, a2, a3, a4_res, a5);
    return 0;
}

