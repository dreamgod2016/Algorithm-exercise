// 1027-print-hourglass.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, rest = 0,num = 0 , temp_result = 0;
	vector<int> nums;
	for (int i = 0; temp_result <= 1020; i++)
	{
		temp_result = 2 * i*i + 4 * i + 1;
		nums.push_back(temp_result);
	}
	char symbol;
	cin >> N >> symbol;
	for (int i = 0; i < nums.size(); i++)
	{
		if (N >= nums[i])
		{
			rest = N - nums[i] ;
			num = i*2+1;
		}
		else
		{
			//�Ѿ���������һ���ˣ������ϴεĽ����
			break;
		}
	}
	for (int j = num; j >= -num; j = j - 2)
	{
		if (j == -1)
			//��ֹ��������м䡣
			continue;
		int temp = j > 0 ? j : -j;
		string blanks((num - temp)/2, ' ');
		string stars(temp, symbol);
		cout << blanks << stars << endl;
	}
	cout << rest;
    return 0;
}

