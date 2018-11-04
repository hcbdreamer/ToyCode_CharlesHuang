#include <stdio.h>
#include <stdlib.h>

#define IN_WORD 	(1)
#define OUT_WORD 	(0)
#define MAX_WORD	(100)

int is_letter(int c)
{
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
void print_histogram(int length[], int word_cnt)
{
	int i,j;
	for (i = 0; i <= word_cnt; i++)
	{
		printf("word[%02d]:",i+1);
		for (j = 0; j < length[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void print_gistogram_vertical(int length[], int word_cnt)
{
	int i,j;
	int longest = 0;
	for (i = 0; i <= word_cnt; i++)
	{
		if (longest < length[i])
		{
			longest = length[i];
		}
	}
	printf("longest:%d\n",longest);
	for (i = longest; i > 0; i--)
	{
		for (j = 0; j <= word_cnt; j++)
		{
			if (length[j] >= i)
			{
				printf("  *  ");
			}
			else
			{
				printf("     ");
			}
		}
		printf("\n");
	}
	for (i = 0; i <= word_cnt; i++)
	{
		printf("[%02d] ",i);
	}
	printf("\n");
}

main()
{
	int in_word_status = OUT_WORD;
	int c;
	int length[MAX_WORD];
	int word_cnt = -1;

	while((c = getchar()) != EOF)
	{
		if (is_letter(c))
		{
			if (in_word_status == OUT_WORD)
			{
				in_word_status = IN_WORD;
				++word_cnt;
				length[word_cnt] = 0;
			}
			++length[word_cnt];
		}
		else
		{
			in_word_status = OUT_WORD;
		}
		if (c == '\n'){
			print_histogram(length,word_cnt);
			print_gistogram_vertical(length,word_cnt);
			word_cnt = -1;
		}
	}
	exit(0);
}


