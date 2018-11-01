#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXNUM  100    //最大单词个数

int main()
{
	//打印输入的行数，单词数，字符数
	/*int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
		{
			nl++;
		}
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == 0)
		{
			state = IN;
			nw++;
		}
	}
	printf("%d %d %d\n",nl,nw,nc);*/
	

	//打印输入中单词长度的直方图
	int c, nw, m_nw, state, max_wordnum;
	int wordnum[MAXNUM];
	state = OUT;
	c = m_nw = nw = max_wordnum = 0;

	for (int i = 0; i < MAXNUM; i++)
	{
		wordnum[i] = 0;
	}

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
		}
		if (state == IN)
		{
			wordnum[nw - 1]++;
			if (wordnum[nw - 1] > max_wordnum)
			{
				max_wordnum = wordnum[nw - 1];
			}
		}
	}
    
	//水平方向
	printf("水平方向直方图：\n");
	for (int i = 0; i < nw; i++)
	{
		m_nw = wordnum[i];
		printf("第%d个字母的长度是：", i + 1);
		for (int j = 0; j < m_nw; j++)
		{
			printf("*");
			if (j == (m_nw - 1))
				printf("\n");
		}
	}
	//竖直方向
	printf("竖直方向直方图：\n");
	for (int i = max_wordnum - 1; i >= 0; i--)
	{
		for (int j = 0; j < nw; j++)
		{
			if (wordnum[j] >= (i+1))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < nw; i++)
	{
		printf("%d ", i + 1);
	}
}