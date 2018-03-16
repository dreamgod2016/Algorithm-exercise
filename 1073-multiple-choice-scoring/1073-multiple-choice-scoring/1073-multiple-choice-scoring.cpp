// 1073-multiple-choice-scoring.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int opt_num;//ѡ�����
	int right_num;//��ȷ�ĸ���
	int ans = 0;//�����ƴ���
	int wrong_stu_count = 0;//����ѧ����
	int wrong_opt[5];//����ѡ��
};
int hashs[] = { 1, 2, 4, 8, 16 };//��Ӧa, b, c, d, e
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
		//����һЩ�����Ժ��ٴ��ȥ��
		for (int j = 0; j < topics[i].right_num; j++)
		{
			cin >> temp_ans;
			if (temp_ans - 'a' > 5 || temp_ans - 'a' < 0)
			{
				cout << "wrong!" << endl;
				break;
			}
			//����ö���������
			topics[i].ans += hashs[temp_ans - 'a'];
		}
	}
	//�����ﴦ��ѧ���ĳɼ�
	getchar();
	getchar();
	for (int i = 0; i < stu_num; i++)
	{
		string stu_res;
		int topic_num = 0, answer = 0;
		getline(cin, stu_res);
		for (int j = 0; j < stu_res.length(); j++)
		{
			//��ÿһ���ַ����д���
			if (stu_res[j] == ')')
			{
				//Ҫ���㱾����Ŀ�ĵ÷��ˡ�
				if (!(answer ^ topics[topic_num].ans))
				{
					//��ȫ��ȷ�����Ϊ�㡣
					stu_scores[i] += topics[topic_num].score;
				}
				//��©ѡ/��ѡ�ġ�ȡ����ѡ�Ĳ��֣����û�У����ǰ��©ѡ��
				else if (!(~topics[topic_num].ans & answer))
				{
					//©ѡ������Ҫͳ�ƴ����ѡ�
					//�����������Ҫͳ�ƣ�����
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
					//��Ҫ��ȡ��������ѡ�
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
			//����ĸ�Ļ�
			if (stu_res[j] - 'a' < 5 && stu_res[j]- 'a' >= 0)
			{
				//������ͬ���İ취������
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
			//��ʼ����topicsÿһ��Ԫ��
			int max_wrong_opt = max_element(topics[i].wrong_opt, topics[i].wrong_opt + 5) - topics[i].wrong_opt;
			if (topics[i].wrong_stu_count == 0 || topics[i].wrong_opt[max_wrong_opt] < max_wrong_num)
				//����û�˴�
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

