最小的K个数

//改变原有数组顺序

#include<stdio.h>

int Partition(int *arr,int low,int high)//划分数据
{
	int left = low;
	int right = high;
	int tmp = arr[left];
	while(left < right)
	{
		while(left < right && tmp <= arr[right])//从右向左遍历，找到第一个小于标志元素的值，交换
		{
			right --;
		}
		arr[left] = arr[right];
		while(left < right && tmp >= arr[left])//从左到右遍历，找到第一个大于标志元素的值，交换
		{
			left ++;
		}
		arr[right] = arr[left];
	}
	arr[left] = tmp;//剩下的位置就是中间位置
	return left;//返回中间位置下标
}

void GetKnumber(int *intput,int n,int k)//得到最小K位数
{
	if(intput == nullptr || n <= 0 || k <= 0 || k > n)
	{
		return ;
	}
	int start = 0;
	int end = n - 1;
	int index = Partition(intput,start,end);//给数组元素排序，找出中间值
	while(index != k - 1)//中间值小标应等于K位数-1
	{
		if(index > k - 1)//若下标大于k-1，说明最小K位数在中间值的左边
		{
			index = Partition(intput,start,index - 1);
		}
		else
		{
			index = Partition(intput,index + 1,end);//若下标小于k-1，说明最小K位数在中间值的右边
		}
	}
	for(int i = 0;i < k; i++)
	{
		printf("%d ",intput[i]);
	}
}

int main()
{
	int intput[] = {2,5,4,3,7,1,6};
	int n = sizeof(intput)/sizeof(intput[0]);
	GetKnumber(intput,n,3);
	return 0;
}

