/*
41：数据流中的中位数 leetcode 295
题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。
*/

#include <queue>
#include <functional>

using namespace std;

class MedianFinder {
public:
	void addNum(int num) {
		small.push(num);
		large.push(small.top());
		small.pop();
		if (small.size() < large.size()) {
			small.push(large.top());
			large.pop();
		}
	}

	double findMedian() {
		return small.size() > large.size() ? small.top() : 0.5 * (small.top() + large.top());
	}

private:
	priority_queue<int> small;
	priority_queue<int, vector<int>, greater<int>> large;
};
