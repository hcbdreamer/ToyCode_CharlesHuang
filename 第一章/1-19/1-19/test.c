#include <stdio.h>
#include <string.h>
#define MAXLENGTH 100
#define MAXLINE 1000

/*Print the longest input line*/

/*read a line into S[],and output is its length */
/*int getline(char line[], int maxline);
//copy content of from[] to to[];
void copy(char to[], char from[]);


int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
	{
		printf("%s", longest);
	}
	return 0;
}

int getline(char line[], int maxline)
{
	int c, i;
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
		if (c == '\n')
		{
			line[i] = c;
			++i;
		}
		line[i] = '\0';
		return i;
}
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] == from[i]) != '\0')
	{
		++i;
	}
}*/


//Reverse the order of characters in an input line 
void reverse(char s[]);
//read a line into S[],and output is its length
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



