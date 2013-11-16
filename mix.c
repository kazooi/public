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
	
	FILE *file1, *file2;	// テキストファイル
	char *a = "a.txt";	// テキストファイル名
	char *b = "b.txt";	// テキストファイル名
	
	file1 = FileOpen(a);
	file2 = FileOpen(b);
	
	Draw(file1, file2);
	
	return 0;
}