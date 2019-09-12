/*
17 ��ӡ1������nλ��
��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
��ӡ��1��2��3һֱ������3λ����999��
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//˼·��������������ȥ����ÿһλ�ֱ��0-9����ӡʱ�Ѹ�λ��0����
void printString(string &s) {
	bool isBeginning0 = true;
	
	for (auto &c : s) {
		if (isBeginning0 && c != '0')
			isBeginning0 = false;

		if (!isBeginning0) {
			cout << c;
		}
	}
	if(!isBeginning0) 
		cout << '\t';
}

void dfs(string &s, int start, int n) {
	if (start == n) {
		printString(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		s.push_back(i + '0');
		dfs(s, start + 1, n);
		s.pop_back();
	}
}

void print1ToMax(int n) {
	if (n <= 0) return;
	
	string s;
	dfs(s, 0, n);
}
