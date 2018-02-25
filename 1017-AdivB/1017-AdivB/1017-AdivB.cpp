// 1017-AdivB.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int b, rest = 0;
	string a, result = "";
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		int m = (a[i] - '0' + 10 * rest) / b;
		rest = (a[i] - '0' + 10 * rest) % b;
		if (m == 0)
		{
			if (result == "")
				continue;
			else
				result = result + to_string(m);
		}
		else
		{
			result = result + to_string(m);
		}

	}
	if (result == "")
		result = "0";
	cout << result<< " " << rest;
    return 0;
}

