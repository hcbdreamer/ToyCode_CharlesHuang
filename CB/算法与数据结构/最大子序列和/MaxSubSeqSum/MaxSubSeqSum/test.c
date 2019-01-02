#include <stdio.h>

int MaxSubSequenceSum(int A[], int N);


int main()
{

}
/*该算法适用于序列中至少有一个数非负的场合，时间复杂度为线性的O(N)*/
int MaxSubSequenceSum(int A[], int N)
{
	int MaxSum = 0, ThisSum = 0;    //ThisSum为当前子序列和
	for (int i = 0; i < N; i++)
	{
		ThisSum += A[i];            //逐个读取，逐个加
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;       //当前子序列和如果比最大子序列和大，更新
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;            //当前子序列和小于0，即舍弃该子序列，重新开始新的子序列
		}
	}
	return MaxSum;
}