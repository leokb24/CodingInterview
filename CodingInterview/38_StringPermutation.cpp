/*
38���ַ���������
��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��
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
