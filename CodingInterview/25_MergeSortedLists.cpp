/*
25 �ϲ��������������
��Ŀ������������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ��յ�������ġ�
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