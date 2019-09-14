/*
63����Ʊ��������� leetcode 121
��Ŀ�������ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У������������׸ù�
Ʊ���ܻ�õ������Ƕ��٣�����һֻ��Ʊ��ĳЩʱ��ڵ�ļ۸�Ϊ{9, 11, 8, 5,
7, 12, 16, 14}������������ڼ۸�Ϊ5��ʱ�����벢�ڼ۸�Ϊ16ʱ����������
�ջ���������11��
*/

#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int> &prices) {
	int curMin = INT_MAX, maxGain = 0;

	for (int i = 0; i < prices.size(); i++) {
		curMin = min(curMin, prices[i]);
		maxGain = max(maxGain, prices[i] - curMin);
	}
	return maxGain;
}