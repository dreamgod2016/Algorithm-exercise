// how-many-PAT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//int Pcount[100005];
//int Tcount[100005];
int main()
{
	string pat;
	//i��j��k�ֱ�PATĿǰ��λ�á�
	int count = 0;
	int countp = 0, counta = 0, countt = 0;
	//int i = 0, j = 0, k = 0;
	cin >> pat;
	int the_length = pat.length();
/*
	while(true)
	{
		//Ѱ����һ��P
		for (i = i+1; pat[i] != 'P'&&i < the_length; i++);
		if (i == the_length)
			break;
		if (k > j && j > i && k <= the_length)
		{
			count++;
			continue;
		}
		//Ѱ����һ��A
		for (j = j+1; pat[j] != 'A' && j < the_length || j<=i ; j++);
		if (j == the_length)
			break;
		if (k > j && j > i && k <= the_length)
		{
			count++;
			continue;
		}

		//Ѱ����һ��T
		for (k = k+1; pat[k] != 'T' && k < the_length || k <= j; k++);
		if (k > j && j > i && k <= the_length)
		{
			count++;
			continue;
		}

	}
	*/

/*
//����ѭ��̫��������ʱ��
	for (i = 0; i < the_length; i++)
	{
		if (pat[i] != 'P')
			continue;
		for (j = i; j < the_length ; j++)
		{
			if (pat[j] != 'A')
				continue;
			for (k = j; k < the_length ; k++)
			{
				if (pat[k] != 'T')
					continue;
				count++;
			}
		}
	}
	*/

/*
//�ҵ��˴��µ�˼·����������ѭ�����Ǻ��ˡ�
	for (int i = 0; i < the_length; i++)
	{

		if (pat[i] == 'P')
		{
			if (i == 0)
				Pcount[i] = 1;
			else
				Pcount[i] = Pcount[i - 1] + 1;
		}
		else
		{
			if (i == 0)
				Pcount[i] = 0;
			else
				Pcount[i] = Pcount[i - 1];
		}

	}

	for (i = the_length - 1; i >= 0; i--)
	{
		if (pat[i] == 'T')
		{
			if (i == the_length - 1)
				Tcount[i] = 1;
			else
				Tcount[i] = Tcount[i + 1] + 1;
		}
		else
		{
			if (i == the_length - 1)
				Tcount[i] = 0;
			else
				Tcount[i] = Tcount[i + 1];
		}
	}

	for (i = 0; i < the_length; i++)
	{
		if (pat[i] == 'A')
		{
			count += Tcount[i] * Pcount[i];
		}
	}
	*/
	for (int i = 0; i < the_length; i++)
	{
		if (pat[i] == 'T')
			countt++;
	}
	for (int i = 0; i < the_length; i++)
	{
		if (pat[i] == 'P')
			countp++;
		if (pat[i] == 'A')
			count = (count + (countp*countt) % 1000000007) % 1000000007;
		if (pat[i] == 'T')
			countt--;
	}


	cout << count;
    return 0;
}

