#include <stdio.h>
#include <time.h>
#include <windows.h>

//While循环内部执行两次测试
int midfind(int a[], int x, int n);

//While循环内部执行一次测试
int midfind2(int a[], int x, int n);

int main()
{
	int a[]       = { 2, 5, 7, 9, 10, 12};
	int x         = 5;
	int location  = 0;
	int location2 = 0;
	clock_t start, end, end2;
	start = clock();
	location      = midfind(a, x, 6);
	Sleep(1);
	end = clock();
	location2     = midfind2(a, x, 6);
	Sleep(1);
	end2 = clock();
	printf("The Location is %d,Time is %f\n", location, (double)(end - start) / CLK_TCK);
	printf("The Location2 is %d,Time2 is %f\n", location2, (double)(end2 - end) / CLK_TCK);
}


int midfind(int a[], int x, int n)
{
	int low, high, mid;
	low = mid = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] < x)
		{
			low = mid + 1;
		}
		else if (a[mid] > x)
		{
			high = mid - 1;
		}
		else
			return mid;
	}
		return -1;
}

int midfind2(int a[], int x, int n)
{
	int low, mid, high;
	low = mid = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (a[mid] < x)
			low = mid + 1;
		else
			high = high - 1;
	}
	if (low == high)
	{
		return low;
	}
	else
	{
		return -1;
	}
}