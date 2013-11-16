#include <stdio.h>

FILE* FileOpen(char* fileName){
	FILE *file;
	// ファイルの読み込み
	file = fopen( fileName, "r" );
	if( file == NULL ){
		printf("file error ");
	}
	return file;
}

void Draw(FILE* file1, FILE* file2){

	int c = 0;
	
	int i;
	for(i = 0; c != EOF; i++){
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
		if(c == EOF) break;
	}
	fclose(file1);
	fclose(file2);	
}

int main(void){
	
	FILE *file1, *file2;	// テキストファイル
	char *a = "a.txt";
	char *b = "b.txt";
	
	file1 = FileOpen(a);
	file2 = FileOpen(b);
	
	Draw(file1, file2);

	return 0;
}