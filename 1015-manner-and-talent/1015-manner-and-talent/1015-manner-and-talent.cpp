
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, H;

typedef struct stu
{
public:
	long long id;
	int manner;
	int talent;
	int sum;
	int state = -1;
	/*
		state������ʾ�²ŵ����
		5���ŵ�ȫ��
		4����ʤ��
		3:���ŵ¼����������С���ʤ�š���
		2: ʣ��ﵽ����ߵ�
		1���гɼ�û�ﵽ����޵�
		-1��δ��ʼ��
	*/
	stu(long long id, int manner, int talent)
	{
		//���캯��
		this->id = id;
		this->manner = manner;
		this->talent = talent;
		sum = manner + talent;
		if (manner < L || talent < L)
			state = 1;//������
		else if (manner >= H && talent >= H)
			state = 5;
		else if (manner >= H && talent < H)
			state = 4;//��ʤ��
		else if (manner < H && talent < H && manner >= talent)
			state = 3;
		else
			state = 2;
	}
	
};
/*
ostream& operator <<(ostream &out, stu& a )
{
	out << a.id << " " << a.manner << " " << a.talent << endl;
	return out;
}*/
bool operator < (stu a, stu b)
{
	//�Զ����������
	if (a.state > b.state)
		return false;
	else if (a.state < b.state)
		return true;
	else
	{
		//�²�������
		if (a.sum > b.sum)
			return false;
		else if (a.sum < b.sum)
			return true;
		else
		{
			//�������ȣ����յ·�����
			if (a.manner == b.manner)
				//׼��֤������
				return a.id > b.id;
			else
				return a.manner < b.manner;
		}
	}
}
vector<stu> stus;
int main()
{
	cin >> N >> L >> H;
	long long temp_id;
	int temp_manner, temp_talent, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp_id >> temp_manner >> temp_talent;
		stu temp(temp_id, temp_manner, temp_talent);
		if (temp.state > 1)
			cnt++;
		stus.push_back(temp);
	}
	sort(stus.begin(), stus.end());
	cout << cnt << endl;
	for (int i = N-1; i >=N-cnt; i--)
	{
		cout << stus[i].id<< " " << stus[i].manner << " "<< stus[i].talent <<endl;
	}
}
