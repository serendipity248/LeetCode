#define _CRT_SECURE_NO_WARNINGS

//消失的数字


////方法一：排序，然后循环查找。但是时间复杂度通不过
//# include <stdio.h>
//# include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main(void)
//{
//	int nums[9] = { 0 };
//	//赋值
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", nums + i);
//	}
//	//排序
//	qsort(nums, 9, sizeof(nums[0]), cmp);
//	int ret = missingNumber(nums, 9);
//	printf("%d\n", ret);
//	return 0;
//}
//int missingNumber(int* nums, int numsSize) 
//{
//	int i = 0;
//	for (i = 0; i < numsSize; ++i)
//	{
//		//如果不匹配，则返回i.就是消失的那个数字
//		if (*(nums + i) != i)
//		{
//			return i;
//		}
//	}
//}






////第二种方法
////消失的数字 = 没有少数字之前的和 - 少了数字之后的和
//# include <stdio.h>
// 
//int missingNumber(int* nums, int numsSize);
// 
//int main(void)
//{
//	int nums[9] = { 0 };
//	//对数组赋值
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", nums + i);
//	}
//	int ret = missingNumber(nums, 9);
//	printf("%d\n", ret);
//	return 0;
//}
//
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int sum1 = 0;
//	int sum2 = 0;
//	//求出少了数字之后的和
//	for (i = 0; i < numsSize; ++i)
//	{
//		sum1 += *(nums + i);
//	}
//	//求出没少之前的数字之和
//	for (int i = 0; i <= numsSize; ++i)
//	{
//		sum2 += i;
//	}
//	return sum2 - sum1;
//}




//使用异或解决
# include <stdio.h>
 
int missingNumber(int* nums, int numsSize);
 
int main(void)
{
	int nums[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", nums + i);
	}
	int ret = missingNumber(nums, 9);
	printf("%d\n", ret);
	return 0;
}
//a ^ a = 0,0 ^ a = a, 0 ^ 0 = 1
int missingNumber(int* nums, int numsSize) {
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum ^= i;
		sum ^= *(nums + i);
	}
	sum ^= numsSize;
	return sum;
}