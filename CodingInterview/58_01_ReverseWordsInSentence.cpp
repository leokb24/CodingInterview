/*
58��һ������ת����˳��
��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
�����"student. a am I"��
*/

#include <string>

using namespace std;

void reverseWords(string &s) {
	int storeIndex = 0, n = s.size();
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; ++i) {
		if (s[i] != ' ') {
			if (storeIndex != 0) s[storeIndex++] = ' ';
			int j = i;
			while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
			reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
			i = j;
		}
	}
	s.resize(storeIndex);
}