// 1025-reverse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
/*
哇，algorithm中有reverse诶....
*/

using namespace std;

typedef struct link_num 
{
	//或许可以投机取巧这里用双向链表
	int address;
	int data;
	int next_address;

};
bool operator < (link_num a, link_num b)
{
	return a.address < b.address;
}

map<int, link_num> nums;

int main()
{
	int first_addr, n, k;
	cin >> first_addr >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int address, data, next_address;
		cin >> address >> data >> next_address;
		link_num temp;
		temp.address = address;
		temp.data = data;
		temp.next_address = next_address;
		nums[address] = temp;
		//nums.insert(address, temp);
	}
	link_num first = nums[first_addr];
	link_num temp;
	int next_addr, next_next_addr, last_addr = -2;
	while (n >= 0)
	{
		temp = first;
		if (first.next_address == -1)
			break;
		n = n - k;
		if (n < 0)
			break;
		next_addr = temp.next_address;
		//这里调整k-1个，最后再调整一个	
		for (int j = 0; j < k-1; j++)
		{
			//交换
			next_next_addr = nums[next_addr].next_address;
			nums[next_addr].next_address = temp.address;
			temp = nums[next_addr];
			next_addr = next_next_addr;
		}
		nums[first.address].next_address = next_next_addr;
		if (last_addr != -2)
			nums[last_addr].next_address = nums[temp.next_address].address;
		else
		{
			//现在是第一组，可以确定头结点。
			first_addr = temp.address;
		}
		last_addr = first.address;
		first = temp;
	}
	int print_addr = first_addr;
	while(print_addr != -1)
	{
		if(nums[print_addr].next_address != -1)
			printf("%05d %d %05d\n", nums[print_addr].address, nums[print_addr].data, nums[print_addr].next_address);
		//cout << nums[print_addr].address << ' ' << nums[print_addr].data << ' ' << nums[print_addr].next_address << endl;
		else
			printf("%05d %d %d\n", nums[print_addr].address, nums[print_addr].data, nums[print_addr].next_address);
		print_addr = nums[print_addr].next_address;
	}

    return 0;
}

