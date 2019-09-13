/*
57（二）：和为s的连续正数序列
题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
4～6和7～8。
*/

#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	if (sum < 3)
		return result;
	int end = (sum + 1) / 2;
	int small = 1, big = 2;
	int curSum = small + big;

	while (small < big && big <= end)
	{
		if (curSum == sum)
		{
			vector<int> temp;
			for (int i = small; i <= big; i++)
				temp.push_back(i);
			result.push_back(temp);
			curSum -= (small++); //small 向前进1，要扫没扫过的，所以不是减去big,也不是big++
		}
		else if (curSum<sum)  //制定扫描规则，只能往前扫
			curSum += (++big);
		else if (curSum>sum)
			curSum -= (small++);
	}
	return result;
}