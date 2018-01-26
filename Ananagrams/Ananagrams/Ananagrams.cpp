// Ananagrams.cpp : �������̨Ӧ�ó������ڵ㡣
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
��Ƭ�Ananagrams��Uva 156��
����һЩ���ʣ��ҳ������������������ĵ��ʣ��õ��ʲ���ͨ����ĸ���ţ��õ�������
���е�����һ�����ʡ����ж��Ƿ���������ʱ����ĸ���ִ�Сд���������ʱӦ����������
�Ĵ�Сд�����ֵ���������У����д�д��ĸ������Сд��ĸ��ǰ�棩��
*/
map<string, int> cnt;
vector<string> words;

string repr(const string& s)
{
	//���б�׼��
	string ans = s;
	for (int i = 0; i < s.length(); i++)
	{
		ans[i] = tolower(ans[i]);
	}
	sort(ans.begin(), ans.end());//ȫ����������
	return ans;//���ر�׼����ĺ���
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
		string r = repr(s);//��׼�����
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

