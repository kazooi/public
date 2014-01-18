#include "stdio.h"
#include <stdlib.h>

int c;
int inword = 0;

int main(){	
	while((c = fgetc(stdin)) != EOF){
		
		// スペース タブ 改行 で次の単語に移行
		if(c == '\t' || c == '\n' || c == ' '){
			if(inword){
				printf("]\n");
			}
			inword = 0;
			continue;
		}
		
		// 最初の一回だけ
		if(!inword){
			putchar('[');
		}
		inword = 1;
		putchar(c);
		
	}
	return 0;
}