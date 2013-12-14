#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum TokType
{
	OpPlus,	OpMinus, OpEqual,
	Number,
	
	EndOfFile,
};

int gettok(char *buf, int bufsiz)
{
	//Ç±Ç±Ç…èëÇ¢ÇƒÇ≠ÇæÇ≥Ç¢	
	int c;
	int count = 0;
	while((c = getchar()) != EOF)
	{
		if(isspace(c))
		{
			continue;
		}
		if(c == '+' || c == '-' || c == '=' )
		{
			putchar(c);
			
			break;
		}else if(isdigit(c)){
			do{
				putchar(c);
				buf[count] = c;
				count++;
				break;
			}while(isdigit(c));
			
		}else{
			fprintf(stderr, "invalid char '%c'\n", c);
		}
	}
	return EndOfFile;
}

int main()
{
	enum TokType tok;
	char buf[100];
	
	while((tok = gettok(buf, sizeof(buf))) != EndOfFile){
		printf("tok = %d; buf = [%s]\n", tok, buf);
	}
	
	return 0;
}
