// 1071-small-bet-happy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int money, k, isBig, t, n1, n2;
	cin >> money >> k;
	while (k--)
	{
		//������k��
		cin >> n1 >> isBig >> t >> n2;
		if (t > money)
		{
			printf("Not enough tokens.  Total = %d.\n",money);
			continue;
		}
		if (isBig && n1 < n2 || !isBig && n1> n2)
		{
			//Ӯ�˵����
			money +=  t;
			printf("Win %d!  Total = %d.\n",t,money);
			continue;
		}
		else
		{
			//���˵����
			money -= t;
			printf("Lose %d.  Total = %d.\n",t, money);
			if (money <= 0)
			{
				printf("Game Over.\n");
				break;
			}
		}
	}
    return 0;
}

