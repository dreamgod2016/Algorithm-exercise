// Hanxin-CRT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int total = 0;
	int A, B, C;
	scanf_s("%d %d %d", &A, &B, &C);
	total = C;
	for (; total % 5 != B; total += 7);
	for (; total % 3 != A; total += 35);
	//printf("answer:%d", total);
    return total;
}

