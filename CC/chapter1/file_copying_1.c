#include <stdio.h>

void test1()
{
	int c;
	c = getchar();
	while (c != EOF){
		putchar(c);
		fflush(stdout);
		c = getchar();
	}
}
void test2()
{
	int c;
	c = getchar();
	printf("[0]c is %d\n",c);
	c = getchar();
	printf("[1]c is %d\n",c);
}
main()
{    
	test2();
}
