// 1030-perfect-sequence.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//��ÿһ��Ԫ�ض�Ҫ����
		//ֱ��������result������������ԣ��ͺ����������û�������ǾͰݰ��ˡ�
		the_min  = nums[i];
		//����ط�֮ǰ�õ�int��������������һ�˷����ͳ������ˡ�
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

