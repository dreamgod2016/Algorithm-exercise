// 1009-reverse-string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> words(80);
	int i = 0;
	for (; i < 80; i++)
	{
		if (!(cin >> words[i]))
			break;
	}
	reverse(words.begin(), words.begin() + i);
	for (int j = 0; j < i-1; j++)
	{
		cout << words[j] << " ";
	}
	cout << words[i-1];
    return 0;
}

