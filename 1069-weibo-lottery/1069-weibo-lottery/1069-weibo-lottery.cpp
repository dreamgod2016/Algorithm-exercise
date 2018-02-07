// 1069-weibo-lottery.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<string> owners;
int main()
{
	int m, n, s, cnt = 0;
	cin >> m >> n >> s;
	bool flag = false;
	string temp;
	vector<string> forword(m);
	map<string, int> mapp;
	//getchar();//吃掉回车
	for (int i = 1; i <= m; i++)
	{
		cin >> temp;
		//s向下滑动，是遇到就滑动！不是说再抽到它再滑动
		if (mapp[temp] == 1)
			s += 1;
		if (i == s && mapp[temp] == 0) 
		{
			mapp[temp] = 1;
			cout << temp << endl;
			flag = true;
			s += n;
		}

		//每个存进去
		//getline(cin, forword[i]);
		//cin >> forword[i];
	}
	/*
	for (int i = s - 1; i < m && cnt < n;)
	{
		
		vector<string>::iterator result = find(owners.begin(), owners.end(), forword[i]);
		if (result == owners.end())
		{
			//说明中奖的没在里面，
			owners.push_back(forword[i]);
			cnt += 1;
			i += n;
		}
		else
		{
			//中奖在里面的话，
			i += 1;
		}
		
	}*/
	//if (owners.size() == 0)
	if(!flag)
		cout << "Keep going...";
	/*
	else
	{
		for (vector<string>::iterator it = owners.begin(); it != owners.end(); it++)
		{
			cout << *it << endl;
		}
	}
	*/
    return 0;
}

