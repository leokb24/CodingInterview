/*
6 ��β��ͷ��ӡ����
����һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
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
