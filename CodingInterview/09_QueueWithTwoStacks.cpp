/*
9 ������ջʵ�ֶ���
��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�
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