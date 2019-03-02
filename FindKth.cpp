链表中倒数第k个节点

#include<stdio.h>
#include<assert.h>

struct ListNode
{
	int mvalue;
	ListNode *pnext;
};

ListNode *FindKth(ListNode *Phead,int k)//倒数第k个节点的位置是n-k+1，利用前后指针寻找，两指针的距离为k-1
{
	assert(Phead != NULL);
	if(k <= 0)
	{
		return ;
	}
	ListNode *p = Phead;
	ListNode *q = NULL;
	for(int i = 0;i < k - 1; i++)//第一个指针走到k-1的位置
	{
		if(p->pnext != NULL)
		{
			p = p->pnext;
		}
		else
		{
			return NULL;
		}
	}
	q = Phead;//指针q开始遍历，使指针p和指针q之间相差k-1个位置
	while(p->pnext != NULL)//当第一个指针指向尾节点时，第二个节点恰好指向倒数第k个节点
	{
		p = p->pnext;
		q = q->pnext;
	}
	return q;
}
