#define _CRT_SECURE_NO_WARNINGS

//��ʧ������


////����һ������Ȼ��ѭ�����ҡ�����ʱ�临�Ӷ�ͨ����
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
//	//��ֵ
//	for (int i = 0; i < 9; i++)
//	{
//		scanf("%d", nums + i);
//	}
//	//����
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
//		//�����ƥ�䣬�򷵻�i.������ʧ���Ǹ�����
//		if (*(nums + i) != i)
//		{
//			return i;
//		}
//	}
//}






////�ڶ��ַ���
////��ʧ������ = û��������֮ǰ�ĺ� - ��������֮��ĺ�
//# include <stdio.h>
// 
//int missingNumber(int* nums, int numsSize);
// 
//int main(void)
//{
//	int nums[9] = { 0 };
//	//�����鸳ֵ
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
//	//�����������֮��ĺ�
//	for (i = 0; i < numsSize; ++i)
//	{
//		sum1 += *(nums + i);
//	}
//	//���û��֮ǰ������֮��
//	for (int i = 0; i <= numsSize; ++i)
//	{
//		sum2 += i;
//	}
//	return sum2 - sum1;
//}




//ʹ�������
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