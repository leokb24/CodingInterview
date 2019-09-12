/*
18��һ������O(1)ʱ��ɾ��������
��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣
*/

// ��leetcode 237���ƣ�����237��ȷ���߲���β��㣬����Ҫ���������

#include "ListNode.h"

void deleteNode(ListNode *pHead, ListNode *pToBeDeleted) {
	if (!pHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->next) {
		ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;
		delete pNext;
		pNext = nullptr;
	}
	else if (pHead == pToBeDeleted) {
		delete pHead;
		pHead = nullptr;
	}
	else{
		ListNode *pNode = pHead;
		while (pNode->next && (pNode->next != pToBeDeleted)) {
			pNode = pNode->next;
		}
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pNode->next = nullptr;
	}
}