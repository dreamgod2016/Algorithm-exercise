// get-all-words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
set<string> dict;

int main()
{
	string s, buf;
	while (cin >> s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))
				s[i] = tolower(s[i]);//把所有小写
			else
				s[i] = ' ';//其他字符变成空格
		}
		stringstream ss(s);
		while (ss >> buf)
		{
			//利用stringstream获取每个单词
			dict.insert(buf);
		}
	}
	for (set<string> ::iterator it = dict.begin(); it != dict.end(); ++it)
		cout << *it << "\n";
	getchar();
    return 0;
}

