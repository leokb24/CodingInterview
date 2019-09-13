/*
49：丑数 leetcode 264
题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做第一个丑数。
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