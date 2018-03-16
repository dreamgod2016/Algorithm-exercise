// 1073-multiple-choice-scoring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct topic {
	int id;
	int score;
	int opt_num;//选项个数
	int right_num;//正确的个数
	int ans = 0;//二进制处理
	int wrong_stu_count = 0;//错误学生数
	int wrong_opt[5];//错误选项
};
int hashs[] = { 1, 2, 4, 8, 16 };//对应a, b, c, d, e
int main()
{
	int stu_num, topic_sum, max_wrong_num = 0;
	cin >> stu_num >> topic_sum;
	vector<topic> topics(topic_sum);
	vector<double> stu_scores(stu_num,0.0);
	for (int i = 0; i < topic_sum; i++)
	{
		char temp_ans;
		topics[i].id = i+1;
		cin >> topics[i].score >> topics[i].opt_num >> topics[i].right_num;
		//进行一些编码以后再存进去。
		for (int j = 0; j < topics[i].right_num; j++)
		{
			cin >> temp_ans;
			if (temp_ans - 'a' > 5 || temp_ans - 'a' < 0)
			{
				cout << "wrong!" << endl;
				break;
			}
			//随后用二进制算啦
			topics[i].ans += hashs[temp_ans - 'a'];
		}
	}
	//接下里处理学生的成绩
	getchar();
	getchar();
	for (int i = 0; i < stu_num; i++)
	{
		string stu_res;
		int topic_num = 0, answer = 0;
		getline(cin, stu_res);
		for (int j = 0; j < stu_res.length(); j++)
		{
			//对每一个字符进行处理
			if (stu_res[j] == ')')
			{
				//要计算本道题目的得分了。
				if (!(answer ^ topics[topic_num].ans))
				{
					//完全正确，结果为零。
					stu_scores[i] += topics[topic_num].score;
				}
				//有漏选/错选的。取出错选的部分，如果没有，就是半分漏选。
				else if (!(~topics[topic_num].ans & answer))
				{
					//漏选并不需要统计错误的选项。
					//看结果好像需要统计？？？
					stu_scores[i] = stu_scores[i] + (double)topics[topic_num].score/2;
					//int temp_rest = topics[topic_num].ans ^ answer;
					int temp_rest = topics[topic_num].ans & ~answer;
					for (int m = 0; m < topics[topic_num].opt_num; m++)
					{
						if (temp_rest & hashs[m])
							topics[topic_num].wrong_opt[m]++;
					}
					//topics[topic_num].wrong_stu_count++;
				}
				else
				{
					//需要提取出来错误选项。
					topics[topic_num].wrong_stu_count++;
					int temp_rest = topics[topic_num].ans ^ answer;
					//int temp_rest = ~topics[topic_num].ans & answer;
					for (int m = 0; m < topics[topic_num].opt_num; m++)
					{
						if (temp_rest & hashs[m])
						{
							topics[topic_num].wrong_opt[m]++;
							max_wrong_num = topics[topic_num].wrong_opt[m] > max_wrong_num ? topics[topic_num].wrong_opt[m] : max_wrong_num;

						}
					}
				}
				topic_num++;
				answer = 0;
				continue;
			}
			//是字母的话
			if (stu_res[j] - 'a' < 5 && stu_res[j]- 'a' >= 0)
			{
				//接着用同样的办法来处理。
				answer += hashs[stu_res[j] - 'a'];
			}

		}
	}
	for (int i = 0; i < stu_num; i++)
	{
		printf("%.1f\n", stu_scores[i]);
	}
	if (max_wrong_num == 0)
	{
		cout << "Too simple\n";

	}
	else
	{
		for (int i = 0; i < topic_sum; i++)
		{
			//开始遍历topics每一个元素
			int max_wrong_opt = max_element(topics[i].wrong_opt, topics[i].wrong_opt + 5) - topics[i].wrong_opt;
			if (topics[i].wrong_stu_count == 0 || topics[i].wrong_opt[max_wrong_opt] < max_wrong_num)
				//这题没人错
				continue;
			for (int k = 0; k < topics[i].opt_num; k++)
			{
				if (topics[i].wrong_opt[k] == topics[i].wrong_opt[max_wrong_opt])
				{
					printf("%d %d-%c\n", topics[i].wrong_stu_count, topics[i].id, k + 'a');
				}
			}
		}
	}
    return 0;
}

