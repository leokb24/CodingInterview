/*
18（二）：删除链表中重复的结点
题目：在一个排序的链表中，删除所有重复的结点 Leetcode 82
*/

#include "ListNode.h"

ListNode *deleteDuplication_1(ListNode *pHead) {
	if (!pHead || !pHead->next) return pHead;
	ListNode *dummy = new ListNode(-1);
	ListNode *pre = dummy;
	dummy->next = pHead;

	while (pre->next) {
		ListNode *cur = pre->next;
		while (cur->next && cur->next->val == cur->val) cur = cur->next;
		if (cur != pre->next) pre->next = cur->next;
		else pre = pre->next;
	}

	return dummy->next;
}

