// 1065-single-dog.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string.h>
#include <set>
#include <vector>
#include <functional>

using namespace std;

int id[100005];
int couple[100005];
set<int> dogs;
vector<int> maybe_dogs;

int main()
{
	int co_nums, temp1, temp2, banquet;// , single_dog = 0;
	memset(id, -1, sizeof(id));
	memset(couple, 0, sizeof(couple));
	cin >> co_nums;
	//��ÿ�����±��|��������ʵ�Ƕ����
	//���������໥�Ĵ洢�������Ͳ���Ҫ����ˡ�
	/*
	for (int i = 1; i <= co_nums; i++)
	{
		cin >> temp1;
		cin >> temp2;
		id[temp1] = i;
		id[temp2] = i;
	}*/
	for (int i = 1; i <= co_nums; i++)
	{
		cin >> temp1;
		cin >> temp2;
		id[temp1] = temp2;
		id[temp2] = temp1;
	}
	cin >> banquet;
	for (int j = 0; j < banquet; j++)
	{
		cin >> temp1;
		maybe_dogs.push_back(temp1);
		//�����ǵ���Ļ�
		if (id[temp1] != -1)
		{
			//�����ж϶Է��İ�����û��
			couple[id[temp1]] = 1;
			//֮ǰ�Ǳ���������
			//dogs.insert(temp1);
			//single_dog++;
		}
		/*
		//����û��
		else if (couple[id[temp1]] == 0)
		{
			couple[id[temp1]] = 1;
			maybe_dogs.push_back(temp1);
		}
		//�����Ѿ�����
		else if (couple[id[temp1]] == 1)
		{
			couple[id[temp1]] = 2;
			//һ�����ѭ������������
		}
		*/
	}
	for (int i = 0; i < banquet; i++)
	{
		if (!couple[maybe_dogs[i]])
			dogs.insert(maybe_dogs[i]);
	}
	/*
	//���������һ�£�һ��ʼ������������
	for (int j = 0; j < maybe_dogs.size(); j++)
	{
		if (couple[id[maybe_dogs[j]]] == 1)
		{
			dogs.insert(maybe_dogs[j]);
			//single_dog++;
		}
	}
	*/
	//���
	cout << dogs.size() << endl;
	for (set<int>::iterator it = dogs.begin(); it != dogs.end(); it++)
	{
		if (it != dogs.begin())
			cout << " ";
		printf("%05d", *it);
	}
    return 0;
}

