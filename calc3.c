#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum TokType
{
	OpPlus,	OpMinus, OpEqual,
	Number,
};

int main()
{
	
	int c;
	FILE *fp;
	fp = fopen("b.txt", "r");
	if(fp == NULL)
	{
		printf("file error");
		return 1;
	}
	int count = 0;
	while((c = getc(fp)) != EOF)
	{
		if(isspace(c))
		{
			continue;
		}
		if(c == '+' || c == '-' || c == '=' )
		{
			putchar(c);
			
			// •¶š‚ğ®”‚É•Ï‚¦‚éŠÖ”
		//	atoi(c);
			break;
		}else if(isdigit(c)){
			do{
				putchar(c);
				
				break;
			}while((c = getc(fp)) != EOF && isdigit(c));
			
		}else{
			fprintf(stderr, "invalid char '%c'\n", c);
		}
	}
	return 0;
}
