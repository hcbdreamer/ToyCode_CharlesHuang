#include <stdio.h>
#include <stdlib.h>
char * menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

int getchoice(char * greet, char * choices[])
{
	int chosen = 0;
	int selected;
	char **option;
	do
	{
		printf("Choice:%s\n",greet);	
		option = choices;
		while(*option)
		{
			printf("%s\n",*option);
			option++;
		}
		selected = getchar();
		option = choices;
	}while(!chosen);
	return selected;
}
int main()
{
	int choice = 0;
	
	do
	{
		choice = getchoice("please selet an action",menu);
		printf("you have chose:%c\n",choice);
	}while(choice != 'q');
	exit(0);
}

