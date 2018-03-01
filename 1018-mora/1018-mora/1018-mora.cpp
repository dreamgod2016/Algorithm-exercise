// 1018-mora.cpp : �������̨Ӧ�ó������ڵ㡣
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
			//�ڲ���ͬ������£��ж�˭Ӯ��
			if (isWin(temp_a, temp_b))
			{
				//aӮ�ˣ�
				a_win++;
				//mapĬ�ϳ�ʼ��Ϊ0��
				a_wins[temp_a]++;
			}
			else
			{
				a_lose++;
				//mapĬ�ϳ�ʼ��Ϊ0��
				b_wins[temp_b]++;
			}
		}
	}
	//��������Ľ����OK��
	cout << a_win << " " << a_draw << " " << a_lose << endl;
	cout << a_lose << " " << a_draw << " " << a_win << endl;
	//���������ж�д�������鷳��
	cout << getMax(a_wins) << " " << getMax(b_wins);
    return 0;
}

bool isWin(char a, char b)
{
	//�ѱ�֤a != b
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
	//��ֹ��Bug
	cout << "something wrong" << B << " " << J << " " << C << endl;
}