// Ananagrams.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

/*
反片语（Ananagrams，Uva 156）
输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排，得到输入文
本中的另外一个单词。在判断是否满足条件时，字母不分大小写，但在输出时应保留输入中
的大小写，按字典序进行排列（所有大写字母在所有小写字母的前面）。
*/
map<string, int> cnt;
vector<string> words;

string repr(const string& s)
{
	//进行标准化
	string ans = s;
	for (int i = 0; i < s.length(); i++)
	{
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());//全部进行排序
	return ans;//返回标准化后的函数
}

int main()
{
	int n = 0;
	string s;
	while (cin >> s)
	{
		if (s[0] == '#')
			break;
		words.push_back(s);
		string r = repr(s);//标准化后的
		if (!cnt.count(r))
			cnt[r] = 0;
		cnt[r]++;
	}
	vector<string> ans;
	for (int i = 0; i < words.size(); i++)
		if (cnt[repr(words[i])] == 1)
			ans.push_back(words[i]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	getchar();
    return 0;
}

