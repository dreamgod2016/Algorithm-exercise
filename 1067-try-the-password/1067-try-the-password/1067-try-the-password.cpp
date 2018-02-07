// 1067-try-the-password.cpp : 定义控制台应用程序的入口点。
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
	getchar();//吃掉换行符
	while (test_times--)
	{
		//接下来是每一次的测试
		//flag = true;
		getline(cin, trial);
		//cin >> trial;
		if (trial == "#")
			return 0;
		if (trial.length() != length)
		{
			//已经错误了
			cout << "Wrong password: " << trial << endl;
			continue;
		}
		//这里不需要一个字符一个字符的比较。
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
		//如果运行到这里，就是正确了。
		cout << "Welcome in" << endl;
		return 0;
	}
	cout << "Account locked"<<endl;
    return 0;
}

