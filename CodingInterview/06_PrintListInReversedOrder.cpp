/*
6 从尾到头打印链表
输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
*/

#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int val;
	Node *next;
	Node(int x) : val(x), next(nullptr) {}
};

void printListInReversedOrder(Node *head) {
	if (!head)
		return;
	stack<Node*> st;
	Node *pNode = head;
	while (pNode) {
		st.push(pNode);
		pNode = pNode->next;
	}

	while (!st.empty()) {
		cout << st.top()->val << " ";
		st.pop();
	}
}
