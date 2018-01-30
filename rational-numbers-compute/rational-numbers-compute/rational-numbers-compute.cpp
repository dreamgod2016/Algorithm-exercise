// rational-numbers-compute.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct num {
	bool positive = true;//������
	bool has_deno = true;//�Ƿ������ĸ
	int the_integer = 0;//��������
	int numerator = 0;//����
	int denominator = 0;//��ĸ

	//�Ӽ��˳����ĸ�������
	//��һ������Ĳ���
	void simplif()
	{
		//����Լ�֣�
		if (this->numerator == 0)
		{
			has_deno = false;
		}
		//շת�������Сֵ
		int num2 = this->numerator;
		int  c = this->denominator;
		int num1;
		do
		{
			num1 = num2;
			num2 = c;
			c = num1 % num2;
		} while (c != 0);
		//���Լ����num2
		this->numerator /= num2;
		this->denominator /= num2;
		if (this->denominator == 1)//������
			has_deno = false;
		else if (this->numerator > this->denominator)
		{
			//������ӱȷ�ĸ��
			this->the_integer = this->numerator / this->denominator;
			this->numerator = this->numerator % this->denominator;
		}
	}
}a,b;
//����ӷ�
num operator + (const num a, const num b)
{
	num result;
	//int co_denominator
	result.denominator = a.denominator * b.denominator;
	if (a.positive && b.positive)
		result.numerator = a.numerator*b.denominator + a.denominator*b.numerator;
	else if (!a.positive && b.positive)
	{
		result.numerator = b.denominator*a.numerator - b.numerator*a.denominator;
	}
	else if (a.positive && !b.positive)
	{
		result.numerator = a.numerator*b.denominator - a.denominator*b.numerator;
	}
	else
		result.numerator = - a.numerator*b.denominator - a.denominator*b.numerator;


	//�ж��Ƿ��Ǹ���
	if (result.numerator < 0)
	{
		result.numerator = -result.numerator;
		result.positive = false;
	}

	result.simplif();
	return result;
}


//�������
ostream& operator << (ostream& o, const num output_num)
{
	if (!output_num.positive)
		o << '-';
	if (output_num.the_integer)
		o << output_num.the_integer << ' ';
	if (output_num.has_deno)
	{
		o << output_num.numerator << '/' << output_num.denominator;
	}
	else
		o << output_num.numerator;

	return o;
}


int main()
{
	string temp;
	bool flag = false;
	cin >> temp;

	for (string::iterator it = temp.begin(); it != temp.end(); it++)
	{
		//��ͷ��ʼ��ȡ��
		if (*it == '-')
			a.positive = false;
		else if (*it == '/')
			flag = true;
		else if (!flag)
			a.numerator = a.numerator * 10 + (*it - '0');
		else
			a.denominator = a.denominator * 10 + (*it - '0');
	}

	flag = false;
	cin >> temp;
	//������Է�װ��һ���������У���Ҫcopy������=��=
	for (string::iterator it = temp.begin(); it != temp.end(); it++)
	{
		//��ͷ��ʼ��ȡ��
		if (*it == '-')
			b.positive = false;
		else if (*it == '/')
			flag = true;
		else if (!flag)
			b.numerator = b.numerator * 10 + (*it - '0');
		else
			b.denominator = b.denominator * 10 + (*it - '0');
	}
	a.simplif();
	b.simplif();

	num result = a + b;
	cout << result;

    return 0;
}



