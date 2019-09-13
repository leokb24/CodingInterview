/*
49������ leetcode 264
��Ŀ�����ǰ�ֻ��������2��3��5��������������Ugly Number�����󰴴�С��
���˳��ĵ�1500������������6��8���ǳ�������14���ǣ���Ϊ����������7��
ϰ�������ǰ�1������һ��������
*/

#include <vector>

using namespace std;

int nthUglyNumber(int n) {
	vector<int> res(1, 1);
	int i2 = 0, i3 = 0, i5 = 0;
	while (res.size() < n) {
		int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
		int mn = min(m2, min(m3, m5));

		if (mn == m2) i2++;
		if (mn == m3) i3++;
		if (mn == m5) i5++;
		res.push_back(mn);
	}
	return res.back();
}