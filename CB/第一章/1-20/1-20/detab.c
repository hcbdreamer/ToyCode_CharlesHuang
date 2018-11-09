#include <stdio.h>

#define TABFREQ 8 //every TABFREQ position is a Tab

/*replace '\t' with space in fixed number*/
void detab();

int main()
{
	detab();

	return 0;
}

void detab()
{
	int c         = 0;
	int Pos       = 1; //character's position
	int Space_Num = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			Space_Num = TABFREQ - (Pos - 1) % TABFREQ;
			while (Space_Num > 0)
			{
				putchar(' ');
				Pos++;
				Space_Num--;
			}
			
		}
		else if (c == '\n')
		{
			putchar(' ');
			Pos = 1;
		}
		else
		{
			putchar(c);
			++Pos;
		}
	}
}
