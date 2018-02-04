// 1051-plural-multi.cpp : 定义控制台应用程序的入口点。
//

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	double R1, P1, R2, P2, R, P, A, B;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	R = R1 * R2;
	P = P1 + P2;

	A = R * cos(P);
	B = R * sin(P);
	if (A + 0.005 >= 0 && A < 0)
		printf("0.00");
	else
		printf("%.2f", A);
	if (B >= 0)
	{
		printf("+%.2fi", B);
	}
	else if (B + 0.005 >= 0 && B < 0)
		printf("+0.00i");
	else
		printf("%.2fi", B);
	/*
	if (B < 0)
	{
		printf("%.2f%.2fi", A, B);
	}
	else
		printf("%.2f+%.2fi", A, B);
		*/
    return 0;
}

