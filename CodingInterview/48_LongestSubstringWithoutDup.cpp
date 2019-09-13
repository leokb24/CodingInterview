/*
48��������ظ��ַ������ַ��� leetcode 3
��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
�ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���
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