#include<stdio.h>

int main()
{
	//printf("Hello world!\c");
	/*int a = EOF;
	printf("%d\n", a);*/
	/*int c;
	while ((c = getchar()) != EOF)
		putchar(c);*/
	double count;
	for (count = 0; getchar() != '\n'; ++count)
	{
		;
	}
	printf("%.0f\n", count);

}