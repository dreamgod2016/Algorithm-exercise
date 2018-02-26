// 1010-Polynomial derivation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct formula {
	int number;
	int index;//指数
};
vector<formula> nums;
int main()
{
	int temp_num, temp_index;
	while (cin >> temp_num && cin >> temp_index)
	{
		formula temp;
		temp.number = temp_num;
		temp.index = temp_index;
		if (temp_index == 0)
			continue;
		nums.push_back(temp);
	}
	if (nums.size() == 0)
	{
		cout << "0"<< " " <<"0";
		return 0;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		//无论是几都是这样
		nums[i].number = nums[i].number * nums[i].index;
		if (nums[i].index != 0)
		{
			//减一。
			nums[i].index -= 1;
		}
	}
	//接下来就可以输出了。
	for (int i = 0; i < nums.size()-1; i++)
	{
		//if (nums[i].number == 0)
			//continue;
		cout << nums[i].number << " " << nums[i].index << " ";
	}
	//if(nums[nums.size() - 1].number != 0)
	cout << nums[nums.size() - 1].number << " " << nums[nums.size() - 1].index;
    return 0;
}

