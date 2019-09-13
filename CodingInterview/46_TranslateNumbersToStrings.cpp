/*
46�������ַ�����ַ��� leetcode 91
��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣��
��12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
"mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����
*/

#include <vector>

using namespace std;

int numDecodings(string s) {
	int len = s.size();
	vector<int> dp(len + 1);
	dp[0] = 1;

	for (int i = 1; i <= len; i++) {
		dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
		if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
			dp[i] += dp[i - 2];
		}
	}
	return dp.back();
}