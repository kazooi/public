#include <stdio.h>

int main(void){

	char s[2];
	printf("%d\n",sizeof(s));	// 1byte
	// 
	/*
	���̕������ɂ� '\0' ���܂܂��̂ŁA���ۂɓ��͂ł��镶�����́u�ő啶���� - 1�v�ƂȂ�B
	*/
	
	if(fgets(s, sizeof(s), stdin) == NULL) printf("Yahoo\n");
	
	while(fgets(s, sizeof(s), stdin) != NULL){
		printf("size = %d\n",sizeof(s));
		
		fputs(s,stdout);
		printf("%d\n", s);
		printf("Hello SoGaBe\n");
	}
	
	return 0;
}