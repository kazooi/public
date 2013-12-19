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
	//ここに書いてください	
	int c = 0;
	int count = 0;
	while((c = getchar()) != EOF)
	{
		// スペースだった場合はスキップ
		if(isspace(c))
		{
			continue;
		}
		// 演算子だった場合の処理
		if(c == '+' || c == '-' || c == '=' )
		{
			buf[count] = c;
			count++;
			if(c == '+')
				return OpPlus;
			if(c == '-')
				return OpMinus;
			if(c == '=')
				return OpEqual;
			
			break;
		}else if(isdigit(c)){ // １０進数の場合
			do{
				buf[count] = c;
				count++;
				
			}while((c = getchar()) && isdigit(c));
			return Number;
			
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
	int i;
	while((tok = gettok(buf, sizeof(buf))) != EndOfFile){
		printf("tok = %d; buf = [%s]\n", tok, buf);
		
		for(i = 0; i < 100; i++){
			buf[i] = 0;
		}	
	}
	
	return 0;
}
