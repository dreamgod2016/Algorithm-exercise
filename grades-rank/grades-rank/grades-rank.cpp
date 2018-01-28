// grades-rank.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	int T,gradeMax = 0, gradeMin = 200;
	string topStuName, topStuNum, bottomStuName, bottomStuNum;
	scanf("%d", &T);
	while (T--)
	{
		string theName;
		string theNum;
		int Grades;
		cin >> theName;
		cin >> theNum;
		cin >> Grades;
		if (Grades > gradeMax)
		{
			topStuName = theName;
			topStuNum = theNum;
			gradeMax = Grades;
		}
		if (Grades < gradeMin)
		{
			bottomStuName = theName;
			bottomStuNum = theNum;
			gradeMin = Grades;
		}
	}
	cout << topStuName << " " << topStuNum <<endl;
	cout << bottomStuName << " " << bottomStuNum << endl;
    return 0;
}

