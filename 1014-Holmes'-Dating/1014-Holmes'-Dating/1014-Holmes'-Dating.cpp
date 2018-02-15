// 1014-Holmes'-Dating.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string weekdays[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
string getDay(char a);
int getHour(char a);
int main()
{
	string a, b, c, d, the_day;
	int length_a, length_b, flag = 0, the_hour, the_min;
	cin >> a >> b >> c >> d;
	length_a = min(a.length(), b.length());
	length_b = min(c.length(), d.length());
	for (int i = 0; i < length_a; i++)
	{
		if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G' && flag == 0)
		{
			the_day = getDay(a[i]);
			flag = 1;
			continue;
		}
		//这个只能是大写字母嘛？？？
		if (a[i] == b[i] && flag == 1 && (a[i] >= 'A' && a[i] <= 'N' || isdigit(a[i]))) 
		{
			the_hour = getHour(a[i]);
			flag = 2;
			break;
		}
	}
	for (int i = 0; i < length_b; i++)
	{
		if (c[i] == d[i] && isalpha(c[i]))
		{
			the_min = i;
			//退出循环。
			break;
		}
	}
	cout << the_day;
	printf(" %02d:%02d",  the_hour, the_min);
    return 0;
}

string getDay(char a)
{
	return weekdays[a - 'A'];
}

int getHour(char a)
{
	if (isdigit(a))
	//if (a - '0' >= 0 && a - '0' <= 9)
		return a - '0';
	else
		return (a - 'A' + 10);
}

