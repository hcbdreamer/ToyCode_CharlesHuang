#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXNUM  100    //maxium of words

void Print_Horizontal_Histogram(int wordlength[], int nw);
void Print_Vertical_Histogram(int wordlength[], int nw);


int main()
{
	/*Print the historgram of the word length in the input */
	int c, nw, m_nw, state;
	int wordlength[MAXNUM];
	state = OUT;
	nw = 0;
	c = m_nw = nw = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
			wordlength[nw - 1] = 0;
		}
		if (state == IN)
		{
			wordlength[nw - 1]++;
		}
	}

	Print_Horizontal_Histogram(wordlength, nw);
	Print_Vertical_Histogram(wordlength, nw);
	return 0;
}

void Print_Horizontal_Histogram(int wordlength[], int nw)
{
	int m_wordlength = 0;
	printf("The horizontal histogram is £º\n");
	for (int i = 0; i < nw; i++)
	{
		m_wordlength = wordlength[i];
		printf("The %d word's length is£º", i + 1);
		for (int j = 0; j < m_wordlength; j++)
		{
			printf("*");
			if (j == (m_wordlength - 1))
				printf("\n");
		}
	}
}

void Print_Vertical_Histogram(int wordlength[], int nw)
{
	int i, j;
	int max_length = 0;
	for (i = 0; i < nw; i++)
	{
		if (wordlength[i] > max_length)
		{
			max_length = wordlength[i];
		}
	}
	for (i = max_length - 1; i >= 0; i--)
	{
		for (j = 0; j < nw; j++)
		{
			if (wordlength[j] >= (i + 1))
			{
				printf("* ");
			}
			else if (wordlength[j] < (i + 1))
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < nw; i++)
	{
		printf("%d", i + 1);
	}
}


