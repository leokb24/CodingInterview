/*
48：最长不含重复字符的子字符串 leetcode 3
题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
字符串的长度。假设字符串中只包含从'a'到'z'的字符。
*/

#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
	vector<int> m(26, -1);

	int left = -1. res = 0;

	for (int i = 0; i < s.size(); i++) {
		left = max(left, m[s[i] - 'a']);
		m[s[i] - 'a'] = i;
		res = max(res, i - left);
	}
	return res;
}