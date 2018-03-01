// 1060-aidingdun.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int n, result = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), greater<int>());

	for (int j = 0; j < n; j++)
	{
		//对应的数字够大，剩下的数字不那么大。
		if (j + 1 == n)
		{
			//到结尾了。
			if (nums[j] > j + 1)
				result = j + 1;
			break;
		}
		//原来还有一个条件是nums[j+1] <= j+1
		//去掉这个以后，也注释掉了出现解就break的问题
		//这样就可以走到结尾找到结果了。
		if (nums[j]>j+1)
		{
			//那么就可以说这个数是艾丁顿数?
			result = j+1;
			//break;
		}
	}
	cout << result;
    return 0;
}

