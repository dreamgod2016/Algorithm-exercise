// 1030-perfect-sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> nums;
int main()
{
	int n, temp;
	long long p;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	//int the_max = nums[n-1];
	int count = 0;
	int the_min, result = 0;
	for (int i = 0; i < n; i++)
	{
		//对每一个元素都要遍历
		//直接往后跳result过，如果还可以，就很厉害，如果没超过，那就拜拜了。
		the_min  = nums[i];
		//这个地方之前用的int，但是两个数字一乘法，就出问题了。
		long long  mul_res = the_min * p;
		for (int j = i + result; j < n; j++)
		{
			if (nums[j] <= mul_res)
			{
				//count++;
				count = j - i + 1;
				if (count > result)
					result = count;
			}
			else
				break;
		}

	}
	cout << result;
    return 0;
}

