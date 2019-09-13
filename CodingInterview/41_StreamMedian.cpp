/*
41���������е���λ�� leetcode 295
��Ŀ����εõ�һ���������е���λ����������������ж�����������ֵ����ô
��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ��
��ô��λ������������ֵ����֮���м���������ƽ��ֵ��
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
