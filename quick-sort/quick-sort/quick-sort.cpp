// quick-sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
//#include <set>

using namespace std;

string nums[100005];
string mins[100005];
string result[100005];

bool compare(string a, string b);
/*
bool operator < (string a, string b)
{
	return compare(a, b);
}*/
/*
//����һ���º���
struct SymCmp
{
	bool operator () (const string & x, const string& y) const
	{
		if (!compare(x,y))
			return true;
		else
			return false;
	}
};
*/
//set<string, SymCmp> result;

int main()
{
	int n, count = 0;
	cin >> n;
	string max = "MIN", min = "MAX";
	//����
	for (int m = 0; m < n; m++)
		cin >> nums[m];
	//�����������λ�õ�Min
	min = "MAX";
	//�Ӻ���ǰ�������ҵ�ÿһ����Χ����Сֵ��
	for (int j = n - 1; j >= 0; j--)
	{
		min = compare(nums[j], min) ? min : nums[j];
		mins[j] = min;
	}
	//��ͷ��ʼ����
	for (int i = 0; i < n; i++)
	{
		max = compare(nums[i], max) ? nums[i] : max;
		if (compare(mins[i], nums[i]) && compare(nums[i],max))
		{
			result[count++] = nums[i];
			//result.insert(nums[i]);
		}

	}
	cout << count << endl;
	/*
	for (set<string>::iterator it = result.begin(); it != result.end(); it++)
	{
		if (it != result.begin())
			cout << " ";
		cout << *it;
	}
	*/
	for (int i = 0; i < count; i++)
	{
		if (i != 0)
			cout << " ";
		cout << result[i];
	}
	cout << endl;
    return 0;
}

bool compare(string a, string b)
{
	if (a == "MAX" || b == "MIN")
		return true;
	if (b == "MAX" || a == "MIN")
		return false;
	if (a.length() > b.length())
		return true;
	else if (a.length() < b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > b[i])
				return true;
			if (a[i] < b[i])
				return false;
		}
	}
}

