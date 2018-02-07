// 1074-the-invincible-adder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct add_result {
	bool is_carry = false;
	int result;
};

add_result adder(char char_a, char char_b, char char_mode, bool is_carryed = false)
{
	int a, b, mode;
	add_result result;
	if (char_mode == 'd' || char_mode == '0')
		mode = 10;
	else
		mode = char_mode - '0';
	a = char_a - '0';
	b = char_b - '0';
	result.result = (a + b + (is_carryed ? 1 : 0)) % mode;
	result.is_carry = (a + b+ (is_carryed ? 1 : 0)) / mode;
	return result;
}

int main()
{
	string n, a, b,result = "";
	int length;
	cin >> n >> a >> b;
	//�벹����ô�����š�����
	length = n.length();
	if (length > a.length())
	{
		string add_zero(length - a.length(), '0');
		a = add_zero + a;
	}
	if (length > b.length())
	{
		string add_zero(length - b.length(), '0');
		b = add_zero + b;
	}
	//a��b�������˾�OK��
	add_result individ_result;
	for (int i = length - 1; i >= 0; i--)
	{
		if (i == length - 1)
			individ_result = adder(a[i], b[i], n[i]);
		else
			individ_result = adder(a[i], b[i], n[i], individ_result.is_carry);
		result = to_string(individ_result.result) + result;
	}
	//����������н�λ�Ļ�,����!�����ڶ�λ����0������
	if (individ_result.is_carry)
		result = '1' + result;
	//��ȥ0
	int zero_num = 0;
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] == '0')
		{
			zero_num++;
			if (result[i + 1] == '0')
				continue;
			else
				break;
		}
		else
			break;
	}
	result = result.substr(zero_num, result.length());
	//��������0�Ļ�
	if (result == "")
		cout << "0" << endl;
	else
		cout << result;
	return 0;
}

