/*
19 ������ʽƥ�� leetcode 10
��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'
��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ����ڱ���
�У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"
��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣
*/

#include <vector>
#include <string>

using namespace std;

//����1 �ݹ�
bool isMatch_1(string s, string p) {
	if (p.empty()) return s.empty();
	if (p.size() > 1 && p[1] == '*') {
		return isMatch_1(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') &&
			isMatch_1(s.substr(1), p));
	}
	else {
		return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch_1(s.substr(1), p.substr(1));
	}
}

//����2 ��̬�滮 dp[i][j] ��ʾ s[0,i) �� p[0,j) �Ƿ� match
bool isMatch_2(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j > 1 && p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
			}
			else {
				dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[m][n];
}