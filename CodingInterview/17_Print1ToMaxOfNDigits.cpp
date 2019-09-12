/*
17 打印1到最大的n位数
题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
打印出1、2、3一直到最大的3位数即999。
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//思路：当做排列问题去做，每一位分别放0-9，打印时把高位的0忽略
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
