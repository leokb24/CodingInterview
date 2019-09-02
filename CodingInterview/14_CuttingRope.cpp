/*
14 ������
��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
ʱ�õ����ĳ˻�18��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����1 ��̬�滮
int maxProductAfterCutting1(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	vector<int> dp(length + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= length; i++) {
		int maxProduct = 0;
		for (int j = 1; j <= i / 2; j++) {
			maxProduct = max(maxProduct, dp[j] * dp[i - j]);
		}
		dp[i] = maxProduct;
	}

	return dp[length];
}


// ����2 ̰��
int maxProductAfterCutting2(int length) {
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;
	if (length - timesOf3 * 3 == 1)
		timesOf3--;
	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}