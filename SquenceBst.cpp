判读是否为二叉搜索树的后续遍历序列

#include<stdio.h>

//二叉搜索树根的左孩子节点均小于根节点，右孩子节点均大于根节点，后序遍历顺序为左右中，根据特性，数组最后一个元素应为根节点
bool SquenceBST(int squence[],int len)
{
	if(squence == NULL || len <= 0)
	{
		return false;
	}
	int root = squence[len - 1];
	int i;
	for(i = 0;i < len - 1; i++)//遍历左孩子，出现大于根节点的值时说明该值及后面元素均应为右子树节点
	{
		if(squence[i] > root)
		{
			break;
		}
	}
	int j;
	for(j = i;j < len - 1; j++)//若左子树遍历结束后再次出现小于根节点的值时，说明该树不满足二叉搜索树的性质
	{
		if(squence[j] < root)
		{
			return false;
		}
	}
	bool LeftTree = true;//判断左子树是否为二叉搜索树
	if(i > 0)
	{
		LeftTree = SquenceBST(squence,i);
	}
	bool RightTree = true;//判断右子树是否为二叉搜索树
	if(i < len - 1)
	{
		RightTree = SquenceBST(squence + i,len - i - 1);
	}
	return (LeftTree && RightTree); 
}

int main()
{
	int squence[] = {5,7,6,9,11,10,8};
	int len = sizeof(squence)/sizeof(squence[0]);
	printf("%d\n",SquenceBST(squence,len));
	return 0;
}
