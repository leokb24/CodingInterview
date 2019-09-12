/*
18（一）：在O(1)时间删除链表结点
题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
*/

// 与leetcode 237类似，不过237明确告诉不是尾结点，不需要分情况讨论

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