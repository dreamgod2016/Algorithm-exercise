// 1024-scientific-notation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string the_num, main_num = "",index = "";
	getline(cin, the_num);
	bool isNeg = false, isIndexNeg = false;
	int i = 0;
	if (the_num[i] == '-')
		cout << '-';
		//isNeg = true;
	i++;
	while (the_num[i] != 'E')
	{
		if (the_num[i] == '.')
		{
			i++;
			continue;
		}
		main_num = main_num + the_num[i];
		i++;
	}
	//�ҵ�E��
	if (the_num[++i] == '-')
		isIndexNeg = true;
	while (the_num[++i] != '\0')
	{
		index = index + the_num[i];
	}
	//��ȡ��д���ˣ��������ǵ�����
	int int_index = stoi(index);
	//ȱ��Ϊ0�����
	if (!isIndexNeg)
	{
		//ָ��Ϊ����
		if (int_index > main_num.length() - 1)
		{
			//�����������Ҫ���м���롣
			cout << main_num << string(int_index - main_num.length() + 1, '0');
		}
		else
		{
			//��Ҫ�м����С���㡣
			for (int j = 0; j <= int_index; j++)
				cout << main_num[j];
			cout << '.';
			for (int j = int_index + 1; j < main_num.length(); j++)
				cout << main_num[j];
		}
	}
	else
	{
		//�����������������1������0.x��
		cout << "0." << string(int_index-1,'0') << main_num ;
	}
    return 0;
}

