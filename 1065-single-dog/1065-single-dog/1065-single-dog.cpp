// 1065-single-dog.cpp : 定义控制台应用程序的入口点。
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
	//给每队情侣编号|这个编号其实是多余的
	//可以利用相互的存储来做，就不需要编号了。
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
		//本身是单身的话
		if (id[temp1] != -1)
		{
			//现在判断对方的伴侣来没来
			couple[id[temp1]] = 1;
			//之前是本身单身的情况
			//dogs.insert(temp1);
			//single_dog++;
		}
		/*
		//对象还没来
		else if (couple[id[temp1]] == 0)
		{
			couple[id[temp1]] = 1;
			maybe_dogs.push_back(temp1);
		}
		//对象已经来了
		else if (couple[id[temp1]] == 1)
		{
			couple[id[temp1]] = 2;
			//一会儿再循环拯救他对象。
		}
		*/
	}
	for (int i = 0; i < banquet; i++)
	{
		if (!couple[maybe_dogs[i]])
			dogs.insert(maybe_dogs[i]);
	}
	/*
	//接下来检查一下，一开始单身来的人们
	for (int j = 0; j < maybe_dogs.size(); j++)
	{
		if (couple[id[maybe_dogs[j]]] == 1)
		{
			dogs.insert(maybe_dogs[j]);
			//single_dog++;
		}
	}
	*/
	//输出
	cout << dogs.size() << endl;
	for (set<int>::iterator it = dogs.begin(); it != dogs.end(); it++)
	{
		if (it != dogs.begin())
			cout << " ";
		printf("%05d", *it);
	}
    return 0;
}

