/*
35����������ĸ��� leetcode 138
��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
����⣬����һ��m_pSibling ָ�������е����������nullptr��
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