/*
18（三）：删除链表中重复的结点 leetcode 83
题目：在一个排序的链表中，删除重复的结点，使每个值只出现一次
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

ListNode *deleteDuplication(ListNode *pHead) {
	if (!pHead || !pHead->next)
		return pHead;

	ListNode *cur = pHead;
	while (cur) {
		ListNode *next = cur->next;
		while (next && next->val == cur->val) next = next->next;
		cur->next = next;
		cur = cur->next;
	}
	return pHead;
}