// 1069-weibo-lottery.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//getchar();//�Ե��س�
	for (int i = 1; i <= m; i++)
	{
		cin >> temp;
		//s���»������������ͻ���������˵�ٳ鵽���ٻ���
		if (mapp[temp] == 1)
			s += 1;
		if (i == s && mapp[temp] == 0) 
		{
			mapp[temp] = 1;
			cout << temp << endl;
			flag = true;
			s += n;
		}

		//ÿ�����ȥ
		//getline(cin, forword[i]);
		//cin >> forword[i];
	}
	/*
	for (int i = s - 1; i < m && cnt < n;)
	{
		
		vector<string>::iterator result = find(owners.begin(), owners.end(), forword[i]);
		if (result == owners.end())
		{
			//˵���н���û�����棬
			owners.push_back(forword[i]);
			cnt += 1;
			i += n;
		}
		else
		{
			//�н�������Ļ���
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

