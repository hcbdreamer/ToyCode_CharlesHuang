#include <stdio.h>

int MaxSubSequenceSum(int A[], int N);


int main()
{

}
/*���㷨������������������һ�����Ǹ��ĳ��ϣ�ʱ�临�Ӷ�Ϊ���Ե�O(N)*/
int MaxSubSequenceSum(int A[], int N)
{
	int MaxSum = 0, ThisSum = 0;    //ThisSumΪ��ǰ�����к�
	for (int i = 0; i < N; i++)
	{
		ThisSum += A[i];            //�����ȡ�������
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;       //��ǰ�����к��������������кʹ󣬸���
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;            //��ǰ�����к�С��0���������������У����¿�ʼ�µ�������
		}
	}
	return MaxSum;
}