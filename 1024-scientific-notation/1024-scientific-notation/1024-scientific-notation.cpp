// 1024-scientific-notation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string the_num, main_num = "",index = "";
	getline(cin, the_num);
	bool isNeg = false, isIndexNeg = false;
	int i = 0;
	if (the_num[i] == '-')
		cout << '-';
		//isNeg = true;
	i++;
	while (the_num[i] != 'E')
	{
		if (the_num[i] == '.')
		{
			i++;
			continue;
		}
		main_num = main_num + the_num[i];
		i++;
	}
	//找到E了
	if (the_num[++i] == '-')
		isIndexNeg = true;
	while (the_num[++i] != '\0')
	{
		index = index + the_num[i];
	}
	//读取都写完了，接下来是调整。
	int int_index = stoi(index);
	//缺少为0的情况
	if (!isIndexNeg)
	{
		//指数为正。
		if (int_index > main_num.length() - 1)
		{
			//这种情况不需要在中间插入。
			cout << main_num << string(int_index - main_num.length() + 1, '0');
		}
		else
		{
			//需要中间插入小数点。
			for (int j = 0; j <= int_index; j++)
				cout << main_num[j];
			cout << '.';
			for (int j = int_index + 1; j < main_num.length(); j++)
				cout << main_num[j];
		}
	}
	else
	{
		//负数的情况，至少是1，就是0.x。
		cout << "0." << string(int_index-1,'0') << main_num ;
	}
    return 0;
}

