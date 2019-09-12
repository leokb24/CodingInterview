/*
24 反转链表 leetcode 206
题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/

#include "ListNode.h"

ListNode *reverseList(ListNode *pHead) {
	if (!pHead || !pHead->next) return pHead;

	ListNode *pre = nullptr, *cur = pHead;
	while (cur) {
		ListNode *next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}