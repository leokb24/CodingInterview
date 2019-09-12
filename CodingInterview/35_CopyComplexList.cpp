/*
35：复杂链表的复制 leetcode 138
题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
*/

class RandomNode {
public:
	int val;
	RandomNode* next;
	RandomNode* random;

	RandomNode() {}

	RandomNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

RandomNode *copyRandomList(RandomNode *pHead) {
	if (!pHead) return nullptr;
	RandomNode *cur = pHead;
	while (cur) {
		RandomNode *t = new RandomNode(cur->val);
		t->next = cur->next;
		cur->next = t;
		cur = t->next;
	}

	cur = pHead;
	while (cur) {
		if (cur->random) cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	
	cur = pHead;
	RandomNode *res = pHead->next;
	while (cur) {
		RandomNode *t = cur->next;
		cur->next = t->next;
		cur = cur->next;
		if (cur) t->next = cur->next;
	}
	return res;
}