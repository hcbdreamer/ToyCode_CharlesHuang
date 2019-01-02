#include<stdio.h>

int main()
{
	int a[2][2] = { { 1, 2 }, { 3, 4 } };
	int(*p)[2];
	p = &a;
	printf("%d %d",*(*(p + 1)+1), *(*(p + 1)));

}