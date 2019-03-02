链表中环的入口节点

#include<stdio.h>
#include<assert.h>

struct ListNode
{
	int mvalue;
	ListNode *pnext;
};

ListNode *MeetingNode(ListNode *Phead)//判断是否有环，利用快慢指针，如果两指针相遇，说明链表中有环
{
	assert(Phead != NULL);
	ListNode *pSlow = Phead->pnext;//慢指针指向第一个节点
	ListNode *pFast = pSlow->pnext;//快指针指向慢指针的下一个节点
	assert(pSlow != NULL && pFast != NULL);
	while(pFast != NULL && pSlow != NULL)
	{
		if(pFast == pSlow)//两指针相等，证明有环
		{
			return pFast;
		}
		pSlow = pSlow->pnext;
		pFast = pFast->pnext;
		if(pFast != NULL)//若快指针指向的节点不为空，快指针继续向下走一个节点
		{
			pFast = pFast->pnext;
		}
	}
	return NULL;
}

ListNode *EntryNode(ListNode *phead)//寻找环的入口地址，利用快慢指针，快慢指针相差环中节点数的距离
{
	assert(phead != NULL);
	ListNode *meetNode = MeetingNode(phead);//找到两指针相遇的节点，该节点肯定在环内
	assert(meetNode != NULL);
	int count = -1;
	ListNode *qNode1 = meetNode;
	while(qNode1->pnext != meetNode)//遍历环，统计环中节点
	{
		qNode1 = qNode1->pnext;
		count ++;
	}
	qNode1 = phead;
	for(int i = 0;i < count; i++)//快指针从环中节点数的位置开始
	{
		qNode1 = qNode1->pnext;
	}
	ListNode *qNode2 = phead;//慢指针从头节点开始
	assert(qNode2 != NULL);
	while(qNode1 != qNode2)//若两节点相遇，则该节点环的入口节点
	{
		qNode1 = qNode1->pnext;
		qNode2 = qNode2->pnext;
	}
	return qNode1;
}
