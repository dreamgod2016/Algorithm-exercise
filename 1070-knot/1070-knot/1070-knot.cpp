// 1070-knot.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int main()
{
	int n, temp;
	double result = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	for (vector<int>::iterator it = nums.begin();it!=nums.end();it++)
	{
		//cout << *it << endl;
		if (it == nums.begin())
			result = *it;
		else
			result = (*it + result) / 2;
	}
	cout << int(result);
    return 0;
}

