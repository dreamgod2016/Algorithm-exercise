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
int couple[10005];
set<int> dogs;
vector<int> maybe_dogs;

int main()
{
	int co_nums, temp1, temp2, banquet;// , single_dog = 0;
	memset(id, 0, sizeof(id));
	memset(couple, 0, sizeof(couple));
	cin >> co_nums;
	//给每队情侣编号
	for (int i = 1; i <= co_nums; i++)
	{
		cin >> temp1;
		cin >> temp2;
		id[temp1] = i;
		id[temp2] = i;
	}
	cin >> banquet;
	for (int j = 0; j < banquet; j++)
	{
		cin >> temp1;
		//本身是单身的话
		if (id[temp1] == 0)
		{
			dogs.insert(temp1);
			//single_dog++;
		}
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
	}
	//接下来检查一下，一开始单身来的人们
	for (int j = 0; j < maybe_dogs.size(); j++)
	{
		if (couple[id[maybe_dogs[j]]] == 1)
		{
			dogs.insert(maybe_dogs[j]);
			//single_dog++;
		}
	}
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

