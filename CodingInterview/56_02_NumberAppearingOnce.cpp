/*
56（二）：数组中唯一只出现一次的数字
题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
找出那个吃出现一次的数字。
*/

#include <vector>
#include <exception>

using namespace std;

int findNumberAppearingOnce(vector<int> nums){
	if (nums.size() < 1)
		throw new exception("Invalid input.");

	int bitSum[32] = { 0 };
	for (int i = 0; i < nums.size(); ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = nums[i] & bitMask;
			if (bit != 0)
				bitSum[j] += 1;

			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}