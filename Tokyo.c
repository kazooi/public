#include "stdio.h"
#include <stdlib.h>

int c;
int inword = 0;

int main(){	
	while((c = fgetc(stdin)) != EOF){
		
		// �X�y�[�X �^�u ���s �Ŏ��̒P��Ɉڍs
		if(c == '\t' || c == '\n' || c == ' '){
			if(inword){
				printf("]\n");
			}
			inword = 0;
			continue;
		}
		
		// �ŏ��̈�񂾂�
		if(!inword){
			putchar('[');
		}
		inword = 1;
		putchar(c);
		
	}
	return 0;
}