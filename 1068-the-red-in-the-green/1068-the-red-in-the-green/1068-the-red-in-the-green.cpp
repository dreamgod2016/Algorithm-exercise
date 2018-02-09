// 1068-the-red-in-the-green.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//������Խ���һЩ������
	//colors.resize(n, vector<int> (m));
	map<int, int> mapp; 
	//���ȥ
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
			//������������
			if (after - before > tol)
			{
				//���ɫ��������жϿ���������
				//��i�У���j��
				maybe_x.push_back(i);
				maybe_y.push_back(j);
			}

		}
		colors.push_back(temp);
	}
	//�������жϿ����б��е������
	for (int i = 0; i < maybe_x.size(); i++)
	{
		//ÿһ������ж�
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
	//������һ���Ѿ��жϽ����ˣ�(x��y-1������㡣
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
