/*
30 包含min函数的栈
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。
*/

#include <stack>
#include <assert.h>
using namespace std;

template <typename T> class StackWithMin {
public:
	StackWithMin() {}
	virtual ~StackWithMin() {}

	T &top();
	const T &top() const;

	void push(const T &value);
	void pop();

	const T &min() const;

	bool empty() const;
	size_t size() const;

private:
	stack<T> m_data;
	stack<T> m_min;
};

template <typename T> void StackWithMin<T>::push(const T& value) {
	m_data.push(value);
	if (m_min.empty() || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop() {
	assert(!m_data.empty() && !m_min.empty());

	m_data.pop();
	m_min.pop();
}

template <typename T> const T &StackWithMin<T>::min() const {
	assert(!m_data.empty() && !m_min.empty());
	return m_min.top();
}

template <typename T> T &StackWithMin<T>::top()
{
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
	return m_data.size();
}