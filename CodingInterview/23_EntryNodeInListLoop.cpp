/*
23 �����л�����ڽ�� leetcode 142
��Ŀ��һ�������а�����������ҳ�������ڽ�㣿���û�л�������null
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