// Circular-Sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#define maxn 105

/*
长度为n的环状串有n种表示法，分别为从某
个位置开始顺时针得到。例如，图3-4的环状串
有10种表示：
CGAGTCAGCT，GAGTCAGCTC，AGTCAGCTCG等。在这些表示法中，字典序最小的称
为"最小表示"。
输入一个长度为n（n≤100）的环状DNA串（只包含A、C、G、T这4种字符）的一种表
示法，你的任务是输出该环状串的最小表示。例如，CTCC的最小表示是
CCCT，CGAGTCAGCT的最小表示为AGCTCGAGTC。
*/

int isLess(const char* s, int p, int q)
{
	//判断字典序的顺序，p和q是环状开始的位置
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		//相同的情况就过，不同的情况就行判断。
		if (s[(p + i)% length]  != s[(q + i) % length] )
			return s[(p + i) % length]  < s[(q + i) % length];
	}
	//如果相等
	return 0;
}

int main()
{
	int Time;
	char s[maxn];
	scanf_s("%d", &Time);
	while (Time--)
	{
		scanf_s("%s", s,sizeof(s));
		int result = 0;
		int length = strlen(s);
		for (int i = 1; i < length; i++)
		{
			//从第二个元素开始
			if (isLess(s, i, result))
				result = i;
		}
		//接下来是输出
		for (int i = 0; i < length; i++)
		{
			putchar(s[(result + i) % length]);
		}
		putchar('\n');
	}
    return 0;
}

