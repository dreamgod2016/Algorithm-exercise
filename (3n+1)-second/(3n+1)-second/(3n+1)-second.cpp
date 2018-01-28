// (3n+1)-second.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <string>
#include <iostream>
#include <algorithm> 
#include <iterator>
#include <functional> //greater<int>

using namespace std;

set<int> result;
set<int> nums;
set<int, greater<int>> v;
void saveRes(int number);
int main()
{
	int T, number;
	scanf("%d", &T);
	string printRes;
	while (T--)
	{
		//输入一组数据
		cin >> number;
		saveRes(number);
		nums.insert(number);
	}

	std::set_difference(nums.begin(), nums.end(), result.begin(), result.end(), inserter(v, v.begin()));

	for (set<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		printRes = printRes + to_string(*it) + " ";
	}
	printRes.erase(printRes.find_last_not_of(" ")+1);
	cout << printRes;
	return 0;
}

void saveRes(int number)
{
	while (number != 1)
	{
		if (number % 2 == 0)
			number /= 2;
		else
			number = (3 * number + 1) / 2;
		result.insert(number);
	}
}
