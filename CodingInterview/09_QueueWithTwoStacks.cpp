/*
9 用两个栈实现队列
题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
*/

#include <stack>
#include <exception>
using namespace std;

template <typename T> 
class CQueue {
public:
	CQueue() {}
	~CQueue() {}

	void appendTail(const T &node) {
		st1.push(node);
	}

	T deleteHead() {
		if (st2.empty()) {
			while (!st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
		}

		if (st2.empty())
			throw new exception("queue is empty");

		T head = st2.top();
		st2.pop();

		return head;
	}

private:
	stack<T> st1, st2;
};