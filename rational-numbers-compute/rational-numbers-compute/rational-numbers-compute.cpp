// rational-numbers-compute.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct num {
	bool positive = true;//������
	bool has_deno = true;//�Ƿ������ĸ
	bool isInf = false;//�Ƿ����Inf
	long long int the_integer = 0;//��������
	long long int numerator = 0;//����
	long long int denominator = 0;//��ĸ

	//�Ӽ��˳����ĸ�������
	//��һ������Ĳ���
	bool simplify()
	{
		//����Լ�֣�
		if (this->numerator == 0)
		{
			has_deno = false;
		}
		//շת�������Сֵ
		long long int num2 = this->numerator;
		long long int  c = this->denominator;
		long long int num1;
		if (num2 == 0)
			return false;
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
		return true;
	}
	void dai2fake()
	{
		//������ת���ɼٷ�����������㡣
		this->numerator += this->the_integer * this->denominator;
		this->the_integer = 0;
	}
}a,b;
//����ӷ�
num operator + (num a, num b)
{
	num result;
	//int co_denominator
	a.dai2fake();
	b.dai2fake();

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

	result.simplify();
	return result;
}
num operator - (num a, num b)
{
	b.positive = !b.positive;
	return a + b;
}

num operator * (num a, num b)
{
	a.dai2fake();
	b.dai2fake();
	num result;
	result.numerator = a.numerator * b.numerator;
	result.denominator = a.denominator * b.denominator;
	result.positive = !(a.positive^b.positive);
	result.simplify();
	return result;
}

num operator / (num a, num b)
{
	a.dai2fake();
	b.dai2fake();
	num result;
	if (b.numerator == 0)
	{
		result.isInf = true;
		return result;
	}
	long long int temp = b.denominator;
	b.denominator = b.numerator;
	b.numerator = temp;
	result = a*b;
	return result;
}

//�������
ostream& operator << (ostream& o, const num output_num)
{
	if (output_num.isInf == true)
	{
		o << "Inf";
		return o;
	}
	if (!output_num.positive && (output_num.the_integer!=0 || output_num.numerator!=0 ))
		o << "(-";
	if (output_num.the_integer)
		o << output_num.the_integer << ' ';
	if (output_num.has_deno)
	{
		o << output_num.numerator << '/' << output_num.denominator;
	}
	else
		o << output_num.numerator;
	if (!output_num.positive && (output_num.the_integer != 0 || output_num.numerator != 0))
		o << ')';
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
	a.simplify();
	b.simplify();


	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;


    return 0;
}



