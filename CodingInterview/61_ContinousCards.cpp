/*
61：扑克牌的顺子
题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
*/

#include <vector>
#include <algorithm>
using namespace std;

bool isContinuous(vector<int> nums) {
	if (nums.size() != 5)
		return false;
	int minNum = 14, maxNum = -1;
	int flag = 0;

	for (auto &i : nums) {
		if (i < 0 || i > 13) return false;
		if (i == 0) continue;
		if ((flag >> i) & 1 == 1) return false;
		flag |= (1 << i);
		maxNum = max(maxNum, i);
		minNum = min(minNum, i);
		if (maxNum - minNum >= 5) return false;
	}
	return true;
}