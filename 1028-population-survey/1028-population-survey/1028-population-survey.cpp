// 1028-population-survey.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
bool setMax(string name, int year, int month, int day);
bool setMin(string name, int year, int month, int day);

int max_year = 2014, max_month = 9, max_day = 7;
int min_year = 0, min_month = 0, min_day = 0;
string max_name, min_name;
int main()
{
	int n, temp_year, temp_month, temp_day, population = 0;
	string temp_name;
	cin >> n;
	while (n--)
	{
		cin >> temp_name;
		scanf("%d/%d/%d", &temp_year, &temp_month, &temp_day);
		//判断是否合理
		if (temp_year < 1814 ||
			temp_year == 1814 && (temp_month < 9 || temp_month == 9 && temp_day < 6) ||
			temp_year > 2014 ||
			temp_year == 2014 && (temp_month > 9 || temp_month == 9 && temp_day > 6)
			)
		{
			//日期不合理
			continue;
		}
		else
		{
			population++;
			setMax(temp_name, temp_year, temp_month, temp_day);
			setMin(temp_name, temp_year, temp_month, temp_day);
		}
	}
	cout << population;
	if(population != 0)
		cout << " " << max_name << " " << min_name;
    return 0;
}

//寻找岁数最大的
bool setMax(string name, int year, int month, int day)
{
	if (year < max_year ||
		year == max_year && (month < max_month || month == max_month && day < max_day))
	{
		//找到更大的了
		max_name = name;
		max_year = year;
		max_month = month;
		max_day = day;
		return true;
	}
	else
	{
		return false;
	}
}

bool setMin(string name, int year, int month, int day)
{
	if (year > min_year ||
		year == min_year && (month > min_month || month == min_month && day > min_day))
	{
		//找到更大的了
		min_name = name;
		min_year = year;
		min_month = month;
		min_day = day;
		return true;
	}
	else
	{
		return false;
	}
}