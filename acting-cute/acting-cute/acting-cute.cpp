// acting-cute.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void parseBuffer(int flag, string buffer);


vector<string> hands;
vector<string> eyes;
vector<string> mouses;

int main()
{
	string buffer;
	for (int i = 0; i < 3; i++)
	{
		getline(cin, buffer);
		parseBuffer(i, buffer);
	}

	int T, hands_len, eyes_len, mouses_len;
	hands_len = hands.size();
	eyes_len = eyes.size();
	mouses_len = mouses.size();

	cin >> T;
	while (T--)
	{
		int h1, e1, m, e2, h2;
		scanf("%d %d %d %d %d", &h1, &e1, &m, &e2, &h2);
		//这里如果判断少了，就会出现段错误！
		if (h1 > hands_len || h2 > hands_len || e1 > eyes_len || e2 > eyes_len || m > mouses_len ||h1<1||h2<1||e1<1||e2<1||m<1)
			printf("Are you kidding me? @\\/@\n");
		else
		{
			cout << hands[h1 - 1] << "(";
			cout << eyes[e1 - 1];
			cout << mouses[m - 1];
			cout << eyes[e2 - 1] << ")";
			cout << hands[h2 - 1]<<endl;
		}
	}
    return 0;
}

void parseBuffer(int flag, string buffer)
{
	bool isOpen = false;
	string temp = "";
	for (int i = 0; i < buffer.length(); i++)
	{
		if (buffer[i] == '[')
		{
			isOpen = true;
			continue;
		}
		if (buffer[i] == ']')
		{
			isOpen = false;
			if (flag == 0)
				hands.push_back(temp);
			else if (flag == 1)
				eyes.push_back(temp);
			else if (flag == 2)
				mouses.push_back(temp);
			//要清空temp!
			temp = "";
			continue;
		}
		if (isOpen)
		{
			temp = temp + buffer[i];
		}
	}
}