#include "stdio.h"
#include <stdlib.h>

int c;
int inword = 0;

int main(){	
	while((c = fgetc(stdin)) != EOF){
		
		// �X�y�[�X�̓R���e�B�j���[
		if(c == '\t' || c == '\n' || c == ' '){
			if(inword){
				printf("]\n");
			}
			inword = 0;
			continue;
		}
		
		if(!inword){
			putchar('[');
		}
		inword = 1;
		putchar(c);
		
	}
	return 0;
}