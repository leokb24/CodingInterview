/*
22 �����е�����k�����
��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
�����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
ֵΪ4�Ľ�㡣
*/

#include "ListNode.h"

ListNode *findKthToTail(ListNode *pHead, int k) {
	if (!pHead || k <= 0)
		return nullptr;

	ListNode *pAhead = pHead, *pBehind = nullptr;
	for (int i = 0; i < k - 1; i++) {
		if (pAhead->next)
			pAhead = pAhead->next;
		else
			return nullptr;
	}

	pBehind = pHead;
	while (pAhead->next) {
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}