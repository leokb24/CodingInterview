/*
59（二）：队列的最大值
题目：请定义一个队列并实现函数max得到队列里的最大值，要求函数max、
push_back和pop_back的时间复杂度都是O(1)
*/

#include <deque>
#include <exception>

using namespace std;

template<typename T> class QueueWithMax
{
public:
	QueueWithMax() : currentIndex(0) {}

	void push_back(T number)
	{
		while (!maximums.empty() && number >= maximums.back().number)
			maximums.pop_back();

		InternalData internalData = { number, currentIndex };
		data.push_back(internalData);
		maximums.push_back(internalData);

		++currentIndex;
	}

	void pop_front()
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		if (maximums.front().index == data.front().index)
			maximums.pop_front();

		data.pop_front();
	}

	T max() const
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		return maximums.front().number;
	}

private:
	struct InternalData
	{
		T number;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maximums;
	int currentIndex;
};
