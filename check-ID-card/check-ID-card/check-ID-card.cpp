// check-ID-card.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPass(string card);


string check_index = "10X98765432";
int coefficient[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
bool isPassed = true;
//vector<string> wrong_card;
int main()
{
	int T;
	string ID_number;
	scanf("%d", &T);
	while (T--)
	{
		//输入身份证号
		cin >> ID_number;
		if (isPass(ID_number))
			continue;
		else
		{
		//	wrong_card.push_back(ID_number);
			cout << ID_number <<endl;
			isPassed = false;
		}
	}
	if (isPassed)
		cout << "All passed";
    return 0;
}

bool isPass(string card)
{
	int sum = 0;
	for (int i = 0; i < 17; i++)
	{
		int number = card[i] - '0';
		if (number > 9 || number < 0)
			return false;
		sum = sum + number*coefficient[i];
	}
	//求和以后，进行匹配
	sum = sum % 11;
	if (check_index[sum] == card[17])
		return true;
	else
		return false;
}

