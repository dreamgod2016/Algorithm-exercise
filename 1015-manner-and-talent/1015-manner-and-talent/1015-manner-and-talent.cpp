
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
		state用来表示德才的情况
		5：才德全尽
		4：德胜才
		3:“才德兼亡”但尚有“德胜才”者
		2: 剩余达到最低线的
		1：有成绩没达到最低限的
		-1：未初始化
	*/
	stu(long long id, int manner, int talent)
	{
		//构造函数
		this->id = id;
		this->manner = manner;
		this->talent = talent;
		sum = manner + talent;
		if (manner < L || talent < L)
			state = 1;//不及格
		else if (manner >= H && talent >= H)
			state = 5;
		else if (manner >= H && talent < H)
			state = 4;//德胜才
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
	//自定义排序规则
	if (a.state > b.state)
		return false;
	else if (a.state < b.state)
		return true;
	else
	{
		//德才情况相等
		if (a.sum > b.sum)
			return false;
		else if (a.sum < b.sum)
			return true;
		else
		{
			//如果还相等，按照德分排序
			if (a.manner == b.manner)
				//准考证的升序
				return a.id > b.id;
			else
				return a.manner < b.manner;
		}
	}
}
//这里换成多个vector就不超时了=。=
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
