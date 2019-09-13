/*
������44������������ĳһλ������ leetcode 400
��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
�������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
������������λ��Ӧ�����֡�
*/

#include <string>

using namespace std;

int findNthDigit(int n) {
	long long len = 1, cnt = 9, start = 1;
	while (n > cnt * len) {
		n -= cnt * len;
		len++;
		cnt *= 10;
		start *= 10;
	}

	start += (n - 1) / len;
	string t = to_string(start);
	return t[(n - 1) % len] - '0';
}