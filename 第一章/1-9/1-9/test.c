#include<stdio.h>

int main()
{
	int c,count=0;
	while ((c = getchar()) != EOF)
	{
		if ( c != ' ')
		{
			putchar(c);
			count = 0;
		}
		else
		{
			count++;
			if (count <= 1)
			{
				putchar(c);
			}
		}
	}
	/*int c;
	c = getchar();
	putchar(c);*/
	 
	return 0;
}