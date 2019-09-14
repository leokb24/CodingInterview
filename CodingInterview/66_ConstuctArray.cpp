/*
66：构建乘积数组
题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
*/

#include <vector>

using namespace std;

vector<int> buildProductionArray(const vector<int> &nums){
	vector<int> res(nums.size(), 0);
	res[0] = 1;
	for (int i = 1; i < nums.size(); i++) 
		res[i] = res[i - 1] * nums[i - 1];

	int tmp = 1;
	for (int i = nums.size() - 2; i >= 0; i--) {
		tmp *= nums[i+1];
		res[i] *= tmp;
	}
	return res;
}