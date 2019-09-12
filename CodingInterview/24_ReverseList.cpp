/*
24 ��ת���� leetcode 206
��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ��㡣
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