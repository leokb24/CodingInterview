/*
23 链表中环的入口结点 leetcode 142
题目：一个链表中包含环，如何找出环的入口结点？如果没有环，返回null
*/

#include "ListNode.h"

ListNode *detectCycle(ListNode *pHead) {
	ListNode *slow = pHead, *fast = pHead;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (!fast || !fast->next)
		return nullptr;

	fast = pHead;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}