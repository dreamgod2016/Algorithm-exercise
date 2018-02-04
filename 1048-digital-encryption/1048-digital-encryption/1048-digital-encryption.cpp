// 1048-digital-encryption.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

char even_encry(char char_a, char char_b);
char odd_encry(char char_a, char char_b);


int main()
{
	string a, b, result = "";
	cin >> a;
	cin >> b;
	int alength = a.length();
	int blength = b.length();
	bool isEven = false;
	//如果A比B长，就把B的前面补满零。
	if (alength > blength)
	{
		string zero_string(alength - blength, '0');
		b = zero_string + b;
		blength = b.length();
	}
	for (int i = blength - 1, j = alength -1; i >= 0; i--)
	{
		//如果B比A长
		if (j == -1)
		{
			result = b[i] + result;
			continue;
		}
		else
		{
			if (isEven)
				result = even_encry(a[j], b[i]) + result;
			else
				result = odd_encry(a[j], b[i]) + result;
			isEven = !isEven;
			j--;
		}

	}
	cout << result <<endl;
    return 0;
}

char even_encry(char char_a, char char_b)
{
	int a = char_a - '0';
	int b = char_b - '0';
	if (b - a < 0)
		return (b - a + 10) + '0';
	else
		return (b - a) + '0';
}

char odd_encry(char char_a, char char_b)
{
	int a = char_a - '0';
	int b = char_b - '0';
	int result = (a + b) % 13;
	switch (result)
	{
	case 10:
		return 'J';
		break;
	case 11:
		return 'Q';
		break;
	case 12:
		return 'K';
		break;
	default:
		return result + '0';
		break;
	}
}