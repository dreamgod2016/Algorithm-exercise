// 1008-move-right.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	//���÷�ת�Ϳ��Խ���������
	m = m % n;
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin()+m);
	reverse(nums.begin() + m, nums.end());
	for (int i = 0; i < n - 1; i++)
	{
		cout << nums[i] << " ";
	}
	cout << nums[n - 1];
    return 0;
}

