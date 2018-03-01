// 1018-mora.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;
bool isWin(char a, char b);
char getMax(map<char, int> c);


int main()
{
	int n, a_win = 0, a_draw = 0, a_lose = 0 ;
	char temp_a, temp_b;
	map<char, int> a_wins;
	map<char, int> b_wins;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp_a >> temp_b;
		if (temp_a == temp_b)
		{
			a_draw++;
			continue;
		}
		else
		{
			//在不相同的情况下，判断谁赢了
			if (isWin(temp_a, temp_b))
			{
				//a赢了，
				a_win++;
				//map默认初始化为0吧
				a_wins[temp_a]++;
			}
			else
			{
				a_lose++;
				//map默认初始化为0吧
				b_wins[temp_b]++;
			}
		}
	}
	//输入和最后的结果都OK了
	cout << a_win << " " << a_draw << " " << a_lose << endl;
	cout << a_lose << " " << a_draw << " " << a_win << endl;
	//接下来的判断写出来就麻烦了
	cout << getMax(a_wins) << " " << getMax(b_wins);
    return 0;
}

bool isWin(char a, char b)
{
	//已保证a != b
	if (a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C')
		return true;
	return false;
}

char getMax(map<char, int> c)
{
	int B = c['B'];
	int J = c['J'];
	int C = c['C'];
	if (B >= (J > C ? J : C))
		return 'B';
	if (C > (B > J ? B : J) || C == J && J > B)
		return 'C';
	if (J > (B > C ? B : C) )
		return 'J';
	//防止有Bug
	cout << "something wrong" << B << " " << J << " " << C << endl;
}