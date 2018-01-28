// want-to-pass.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��һ������������
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
			//�жϼӵ��ĸ�����
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
		//a��b��c��ȡ���
		temp = a + 'P' + b + "AT" + c + a;
		if (temp.length() > 100)
			continue;
		else
			rightAns.push_back(temp);

	}
	//�����ǲ������е�Ԫ�أ�����������IO
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
	//�����ж��Ƿ��������ַ�
	for (int m = 0; m < element.length(); m++)
	{
		if (element[m]!= 'T' && element[m] != 'P'&& element[m] != 'A')
		{
			//�������ַ�����
			return false;
		}
	}

	//��ͷ��βѰ���Ƿ����
	vector<string>::const_iterator it;
	it = find(rightAns.begin(), rightAns.end(), element);
	if (it != rightAns.end())
		return true;
	else
		return false;
}

//string getNewString(vector<string> nowList, )

