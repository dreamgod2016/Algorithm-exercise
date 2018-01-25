// get-all-words.cpp : �������̨Ӧ�ó������ڵ㡣
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
				s[i] = tolower(s[i]);//������Сд
			else
				s[i] = ' ';//�����ַ���ɿո�
		}
		stringstream ss(s);
		while (ss >> buf)
		{
			//����stringstream��ȡÿ������
			dict.insert(buf);
		}
	}
	for (set<string> ::iterator it = dict.begin(); it != dict.end(); ++it)
		cout << *it << "\n";
	getchar();
    return 0;
}

