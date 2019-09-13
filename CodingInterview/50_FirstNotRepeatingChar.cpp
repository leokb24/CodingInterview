/*
50：字符串中第一个只出现一次的字符 leetcode 387
题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
'b'。
*/

#include <vector>

using namespace std;

int firstUniqChar(string s) {
	vector<int> unique(26, -1);
	for (int i = 0; i<s.size(); i++) {
		if (unique[s[i] - 'a'] == -1)
			unique[s[i] - 'a'] = i;
		else if (unique[s[i] - 'a']>-1)
			unique[s[i] - 'a'] = -2;
	}

	for (int i = 0; i<s.size(); i++) {
		if (unique[s[i] - 'a'] >= 0)
			return i;
	}
	return -1;
}