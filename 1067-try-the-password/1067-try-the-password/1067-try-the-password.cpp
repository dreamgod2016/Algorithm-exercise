// 1067-try-the-password.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string password, trial;
	int	test_times, length;
	bool flag = true;
	cin >> password;
	cin >> test_times;
	length = password.length();
	getchar();//�Ե����з�
	while (test_times--)
	{
		//��������ÿһ�εĲ���
		//flag = true;
		getline(cin, trial);
		//cin >> trial;
		if (trial == "#")
			return 0;
		if (trial.length() != length)
		{
			//�Ѿ�������
			cout << "Wrong password: " << trial << endl;
			continue;
		}
		//���ﲻ��Ҫһ���ַ�һ���ַ��ıȽϡ�
		/*
		for (int i = 0; i < length; i++)
		{
			if (trial[i] != password[i])
			{
				cout << "Wrong password: " << trial <<endl;
				flag = false;
				break;
			}
		}
		*/
		if (trial != password)
		{
			cout << "Wrong password: " << trial << endl;
			continue;
		}
		//������е����������ȷ�ˡ�
		cout << "Welcome in" << endl;
		return 0;
	}
	cout << "Account locked"<<endl;
    return 0;
}

