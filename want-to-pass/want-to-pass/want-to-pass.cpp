// want-to-pass.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isExist(vector<string> rightAns, string element);

int main()
{	
	vector<string> rightAns;
	int i = 0;
	//第一个条件的生成
	do
	{
		string a(i,  'A');
		rightAns.push_back(a + "PAT" + a);
		i++;
	} while (rightAns[i-1].length() <= 100);
	
	for (int j = 0; j < rightAns.size(); j++)
	{
		string temp = rightAns[j];
		int charactor = 0, num = 0;
		string a, b, c;

		while (charactor <= temp.length())
		{
			char nowChar = temp[charactor];
			if (nowChar == 'P')
				num = 1;
			else if (nowChar == 'T')
				num = 2;
			//判断加到哪个里面
			else if (nowChar == 'A')
			{
				switch (num)
				{
				case 0:
					a = a + nowChar;
					break;
				case 1:
					b = b + nowChar;
					break;
				case 2:
					c = c + nowChar;
					break;
				default:
					break;
				}
			}
			charactor++;
		}
		//a、b、c获取完成
		temp = a + 'P' + b + "AT" + c + a;
		if (temp.length() > 100)
			continue;
		else
			rightAns.push_back(temp);

	}
	//以上是产生所有的元素，接下来处理IO
	int T;
	scanf("%d", &T);
	while (T--)
	{
		string inputStr;
		cin >> inputStr;
		if (isExist(rightAns, inputStr))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
    return 0;
}

bool isExist(vector<string> rightAns, string element)
{
	//首先判断是否有其他字符
	for (int m = 0; m < element.length(); m++)
	{
		if (element[m]!= 'T' && element[m] != 'P'&& element[m] != 'A')
		{
			//有其他字符出现
			return false;
		}
	}

	//从头到尾寻找是否存在
	vector<string>::const_iterator it;
	it = find(rightAns.begin(), rightAns.end(), element);
	if (it != rightAns.end())
		return true;
	else
		return false;
}

//string getNewString(vector<string> nowList, )

