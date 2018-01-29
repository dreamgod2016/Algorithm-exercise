// bad-keyboard.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "string.h"

using namespace std;

bool upper_allowed = true;
bool ascii_unallowed[10] = { false };
bool ascii_char_unallowed[30] = { false };
bool other_char[4] = { true };
bool print_block = true;
//�������bool��������orz

int main()
{
	string wrong_key, sentence;
	//cin >> wrong_key;
	//cin >> sentence;
	getline(cin, wrong_key);
	getline(cin, sentence);
	memset(other_char, true, sizeof(other_char));
	memset(ascii_unallowed, false, sizeof(ascii_unallowed));
	memset(ascii_char_unallowed, false, sizeof(ascii_char_unallowed));

	
	
	for (int i = 0; i < wrong_key.length(); i++)
	{
		//����ascii�����λ�á�
		//ascii_unallowed[wrong_key[i] - '0'] = true;
		//if (wrong_key[i] - '0' <= 9 && wrong_key[i] - '0' >= 0)
		if (isdigit(wrong_key[i]))
		{
			//����ǲ��������������
			ascii_unallowed[wrong_key[i] - '0'] = true;
		}
		else if (isupper(wrong_key[i]))
		{
			//�������ĸ
			ascii_char_unallowed[wrong_key[i] - 'A'] = true;
		}
		else if (wrong_key[i] == '+')
		{
			upper_allowed = false;
		}
		else if (wrong_key[i] == '_')
			other_char[0] = false;
		else if (wrong_key[i] == ',')
			other_char[1] = false;
		else if (wrong_key[i] == '.')
			other_char[2] = false;
		else if (wrong_key[i] == '-')
			other_char[3] = false;
	}

	for (int i = 0; i < sentence.length(); i++)
	{
		//��ʼ��ÿ���ַ����б���
		char the_char = sentence[i];
		if (isdigit(the_char))
		{
			if (ascii_unallowed[the_char - '0'] == false)
			{
				cout << the_char;
				print_block = false;
			}
		}
		else if (isalpha(the_char))
		{
			//�������ĸ
			if (isupper(the_char) && !upper_allowed)
				continue;
			else if (ascii_char_unallowed[toupper(the_char) - 'A'])
				continue;
			else
			{
				cout << the_char;
				print_block = false;
			}

		}
		else if (the_char == '+' && upper_allowed)
		{
			cout << the_char;
			print_block = false;

		}
		else if ((the_char == '_' && other_char[0]) || (the_char == ','&& other_char[1]) || (the_char == '.'&& other_char[2]) || (the_char == '-'&& other_char[3]))
		{
			print_block = false;
			cout << the_char;
		}

	}
	if (print_block == true)
		cout << endl;
    return 0;
}

