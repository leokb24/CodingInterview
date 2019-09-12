/*
38：字符串的排列
题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
*/

#include <string>
#include <vector>

using namespace std;

void helper(int index, string &s, vector<string> &res) {
	if (index == s.size()) {
		res.push_back(s);
		return;
	}

	for (int i = index; i < s.size(); i++) {
		if (i != index && s[i] == s[index]) continue;
		swap(s[i], s[index]);
		helper(index + 1, s, res);
		swap(s[i], s[index]);
	}
}

vector<string> permutate(string s) {
	vector<string> res;
	helper(0, s, res);
	return res;
}
