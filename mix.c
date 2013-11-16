#include <stdio.h>
#include <assert.h>

#define MAX 1024

FILE* FileOpen(char* fileName){
	FILE *file;
	// ファイルの読み込み
	file = fopen( fileName, "r" );
	if( file == NULL ){
		printf("file error ");
	}
	// assert(file != NULL);
	return file;
}

void Draw(FILE* file1, FILE* file2){

	char str1[MAX], str2[MAX];
	
	while( fgets( str1, MAX, file1 ) != NULL  && fgets( str2, MAX, file2 ) != NULL){
		printf("%s", str1);
		printf("%s", str2);
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