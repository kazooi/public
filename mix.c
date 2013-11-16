#include <stdio.h>

FILE* FileOpen(char* fileName){
	FILE *file;
	// �t�@�C���̓ǂݍ���
	file = fopen( fileName, "r" );
	if( file == NULL ){
		printf("file error ");
	}
	return file;
}

void Draw(FILE* file1, FILE* file2){

	int c;
	
	int i;
	for(i = 0; i < c != EOF; i++){
		if(c == EOF) break;
		if(i % 2 == 0){
			c = fgetc( file1 );
			if(c == '\n' || c == EOF) continue;
			printf("%c\n", c);	
		}
		
		if(i % 2 == 1){
			c = fgetc( file2 );
			if(c == '\n') continue;
			printf("%c", c);
		}	
	}
	fclose(file1);
	fclose(file2);	
}

int main(void){
	
	FILE *file1, *file2;	// �e�L�X�g�t�@�C��
	char *a = "a.txt";	// �e�L�X�g�t�@�C����
	char *b = "b.txt";	// �e�L�X�g�t�@�C����
	
	file1 = FileOpen(a);
	file2 = FileOpen(b);
	
	Draw(file1, file2);
	
	return 0;
}