#include "stdio.h"
#include <stdlib.h>

int c;
int inword = 0;

int main(){	
	while((c = fgetc(stdin)) != EOF){
		
		switch(c){
		
		case ' ':
		case '\n':
		case '\t':
			if(inword){
				printf("]\n");
			}
			inword = 0;
			break;
			
		default:
			if(!inword){
				putchar('[');
			}
			inword = 1;
			putchar(c);
			break;
		}
		
	}
	return 0;
}