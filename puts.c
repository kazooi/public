#include <stdio.h>

int main(void){

	char s[2];
	printf("%d\n",sizeof(s));	// 1byte
	// 
	/*
	この文字数には '\0' も含まれるので、実際に入力できる文字数は「最大文字数 - 1」となる。
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