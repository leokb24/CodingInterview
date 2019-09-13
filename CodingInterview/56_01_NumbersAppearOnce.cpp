/*
56（一）：数组中只出现一次的两个数字
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
*/

#include <vector>

using namespace std;

unsigned int findFirstBitIs1(int num);
bool isBit1(int num, unsigned int indexBit);

vector<int> FindNumsAppearOnce(vector<int> &data, int length)
{
	if (data.size() < 2)
		return{};

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);

	int num1 = 0, num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (isBit1(data[j], indexOf1))
			num1 ^= data[j];
		else
			num2 ^= data[j];
	}
	return{ num1, num2 };
}

unsigned int findFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

// 判断数字num的第indexBit位是不是1
bool isBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}