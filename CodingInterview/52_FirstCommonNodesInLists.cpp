/*
52����������ĵ�һ��������� leetcode 160
��Ŀ���������������ҳ����ǵĵ�һ��������㡣
*/

#include "ListNode.h"

int getLength(ListNode* head) {
	int cnt = 0;
	while (head) {
		++cnt;
		head = head->next;
	}
	return cnt;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (!headA || !headB) return nullptr;
	int lenA = getLength(headA), lenB = getLength(headB);
	if (lenA < lenB) {
		for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
	}
	else {
		for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
	}
	while (headA && headB && headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return (headA && headB) ? headA : nullptr;
}