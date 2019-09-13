/*
50���ַ����е�һ��ֻ����һ�ε��ַ� leetcode 387
��Ŀ�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������
'b'��
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