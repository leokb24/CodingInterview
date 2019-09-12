/*
18��������ɾ���������ظ��Ľ�� leetcode 83
��Ŀ����һ������������У�ɾ���ظ��Ľ�㣬ʹÿ��ֵֻ����һ��
*/

#include "ListNode.h"

ListNode *deleteDuplication_2(ListNode *pHead) {
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