// coding-team-competition.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdio.h>
#include <string.h>

int team[1005];
int main()
{
	int T, teamNum, person, scores;
	scanf("%d", &T);
	memset(team, 0, sizeof(team));
	while (T--)
	{
		scanf("%d-%d %d", &teamNum, &person, &scores);
		team[teamNum] += scores;
	}
	scores = 0;
	teamNum = 0;
	for (int i = 0; i < 1005; i++)
	{
		//Ѱ������
		if (team[i] > scores)
		{
			teamNum = i;
			scores = team[i];
		}
	}
	printf("%d %d", teamNum, scores);
    return 0;
}

