// 1060-aidingdun.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//��Ӧ�����ֹ���ʣ�µ����ֲ���ô��
		if (j + 1 == n)
		{
			//����β�ˡ�
			if (nums[j] > j + 1)
				result = j + 1;
			break;
		}
		//ԭ������һ��������nums[j+1] <= j+1
		//ȥ������Ժ�Ҳע�͵��˳��ֽ��break������
		//�����Ϳ����ߵ���β�ҵ�����ˡ�
		if (nums[j]>j+1)
		{
			//��ô�Ϳ���˵������ǰ�������?
			result = j+1;
			//break;
		}
	}
	cout << result;
    return 0;
}

