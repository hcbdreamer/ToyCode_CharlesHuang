#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100
#define MAXLINE 1000

/*Reverse the order of characters in an input line*/
void reverse(char s[]);
/*read a line into S[],and output is its length*/
int getline(char line[], int maxline);

int main()
{
	int  len = 0;
	char line[MAXLINE];
	
	/*The part is used to test reverse function*/
	/*char a[100] = "avsdbsfdh";
	reverse(a);
	printf("%s\n", a);*/

	while ((len = getline(line, MAXLINE)) > 0)
	{
			reverse(line);
			printf("%s\n", line);
	}
}

int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}



void reverse(char s[])
{
	int   length = 0;
	char  a[MAXLENGTH];
	for (int i = 0; i < MAXLENGTH-1; ++i)
	{
		a[i] = 0;
	}

	/*Notes:the output of strlen() doesn't contain '\0' */
	length = strlen(s);

	for (int i = 0; i < length; ++i)
	{
		a[i] = s[length -1 - i];
	}
	//a[++i] = '\0';

	for (int i = 0; i < length ; ++i)
	{
		s[i] = a[i];
	}

}



