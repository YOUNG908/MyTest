数组中出现次数超过一半的数字

#include<stdio.h>
bool InputInvalid = true;
bool CheckInvalidArray(int *number,int length)//判断数组中元素是否符合要求
{
    InputInvalid = true;
	if(number == NULL || length <= 0)
	{
		InputInvalid = false;
	}
	return InputInvalid;
}

bool CheckMoreHalf(int *number,int len,int num)//判断出现次数最多的元素个数是否超过数组元素的一半
{
	int time = 0;
	for(int i = 0;i < len; i++)
	{
		if(number[i] == num)
		{
			time ++;
		}
	}
	bool isMoreHalf = true;
	if(time * 2 <= len)//元素出现次数的2倍还小于等于数组长度，说明该元素个数肯定小于数组个数的一半
	{
		InputInvalid = false;
		isMoreHalf = false;
	}
	return isMoreHalf;
}

int MoreHalfNumber(int *number,int len)//寻找元素出现次数最多的元素
{
	if(!CheckInvalidArray(number,len))
	{
		return 0;
	}
	int result = number[0];//记录第一个元素
	int time = 1;//出现次数初始为1
	for(int i = 1;i < len; i++)
	{
		if(number[i] == result)//若下一个元素等于被记录的元素，次数加1，否则次数减1，当次数为0时，记录当前元素
		{
			time ++;
		}
		else if(time == 0)
		{
			result = number[i];
			time = 1;
		}
		else
		{
			time --;
		}
	}
	if(!CheckMoreHalf(number,len,result))
	{
		result = 0;
	}
	return result;
}

int main()
{
	int number[] = {1,2,4,3,5,3,2,2,2,2,2};
	int len = sizeof(number)/sizeof(number[0]);
	printf("%d\n",MoreHalfNumber(number,len));
	return 0;
}
