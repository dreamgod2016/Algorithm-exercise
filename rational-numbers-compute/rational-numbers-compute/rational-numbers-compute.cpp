// rational-numbers-compute.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct num {
	bool positive = true;//正负号
	bool has_deno = true;//是否包含分母
	bool isInf = false;//是否输出Inf
	long long int the_integer = 0;//整数部分
	long long int numerator = 0;//分子
	long long int denominator = 0;//分母

	//加减乘除有四个操作。
	//有一个化简的操作
	bool simplify()
	{
		//进行约分，
		if (this->numerator == 0)
		{
			has_deno = false;
		}
		//辗转相除求最小值
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
		//最大公约数是num2
		this->numerator /= num2;
		this->denominator /= num2;
		if (this->denominator == 1)//是整数
			has_deno = false;
		else if (this->numerator > this->denominator)
		{
			//如果分子比分母大
			this->the_integer = this->numerator / this->denominator;
			this->numerator = this->numerator % this->denominator;
		}
		return true;
	}
	void dai2fake()
	{
		//带分数转换成假分数，方便计算。
		this->numerator += this->the_integer * this->denominator;
		this->the_integer = 0;
	}
}a,b;
//定义加法
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


	//判断是否是负数
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

//定义输出
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
		//从头开始获取。
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
	//这里可以封装成一个函数进行，不要copy代码了=。=
	for (string::iterator it = temp.begin(); it != temp.end(); it++)
	{
		//从头开始获取。
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



