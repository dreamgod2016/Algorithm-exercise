// 1068-the-red-in-the-green.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector <int> > colors;
vector<int> maybe_x;
vector<int> maybe_y;

bool isRed(int x, int y);
int m, n;
int main()
{
	int  tol, before, after, num, red_x = -1,red_y = -1;
	cin >> m >> n >> tol;
	//这里可以进行一些调整。
	//colors.resize(n, vector<int> (m));
	map<int, int> mapp; 
	//存进去
	for (int i = 0; i < n; i++)
	{
		vector<int> temp(m);
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			temp[j] = num;
			mapp[num]++;
			if (j == 0)
			{
				before = num;
				after = num;
			}
			else
				before = after;
			after = num;
			//推入行向量中
			if (after - before > tol)
			{
				//如果色差超过，就判断可能有问题
				//第i行，第j列
				maybe_x.push_back(i);
				maybe_y.push_back(j);
			}

		}
		colors.push_back(temp);
	}
	//接下来判断可疑列表中的情况。
	for (int i = 0; i < maybe_x.size(); i++)
	{
		//每一个点的判断
		if (isRed(maybe_x[i], maybe_y[i]) && mapp[colors[maybe_x[i]][maybe_y[i]]] == 1)
		{
			if (red_x != -1 || red_y != -1)
			{
				cout << "Not Unique" << endl;
				return 0;
			}
			red_x = maybe_x[i];
			red_y = maybe_y[i];
		}
	}
	if (red_x == -1 || red_y == -1)
	{
		cout << "Not Exist" << endl;
		return 0;
	}
	else
	{
		printf("(%d, %d): %d\n", red_y+1, red_x+1, colors[red_x][red_y]);
	}
    return 0;
}

bool isRed(int x, int y)
{
	//其中有一个已经判断结束了，(x，y-1）这个点。
	int the_color = colors[x][y];
	if (
		colors[x - 1][y - 1] < the_color &&
		colors[x - 1][y] < the_color &&
		colors[x - 1][y + 1] < the_color &&
		colors[x][y - 1] < the_color &&
		colors[x][y + 1] < the_color &&
		colors[x + 1][y - 1] < the_color &&
		colors[x + 1][y] < the_color &&
		colors[x + 1][y + 1] < the_color &&
		colors[x - 1][y - 1] < the_color
		)
		return true;
	else
		return false;
}
