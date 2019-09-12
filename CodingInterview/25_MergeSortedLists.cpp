/*
25 合并两个排序的链表
题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。
*/

#include "ListNode.h"

ListNode *mergeList(ListNode *pHead1, ListNode *pHead2) {
	if (!pHead1) return pHead2;
	if (!pHead2) return pHead1;

	if (pHead1->val < pHead2->val) {
		pHead1->next = mergeList(pHead1->next, pHead2);
		return pHead1;
	}
	else {
		pHead2->next = mergeList(pHead1, pHead2->next);
		return pHead2;
	}
}