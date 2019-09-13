/*
47�����������ֵ
��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
(��ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ�
�������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
����������õ����ټ�ֵ�����
*/

#include <vector>
#include <algorithm>
using namespace std;

int getMaxValue(vector<vector<int>> values) {
	if (values.empty() || values[0].empty()) 
		return 0;
	int m = values.size(), n = values[0].size();
	vector<int> dp(n, INT_MIN);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) dp[j] += values[i][j];
			else dp[j] = max(dp[j - 1], dp[j]) + values[i][j];
		}
	}
	return dp.back();
}