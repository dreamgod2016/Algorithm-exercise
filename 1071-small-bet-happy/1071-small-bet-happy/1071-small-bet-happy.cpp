// 1071-small-bet-happy.cpp : 定义控制台应用程序的入口点。
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
		//最多进行k次
		cin >> n1 >> isBig >> t >> n2;
		if (t > money)
		{
			printf("Not enough tokens.  Total = %d.\n",money);
			continue;
		}
		if (isBig && n1 < n2 || !isBig && n1> n2)
		{
			//赢了的情况
			money +=  t;
			printf("Win %d!  Total = %d.\n",t,money);
			continue;
		}
		else
		{
			//输了的情况
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

