#include <stdio.h>
#include <assert.h>

#define MAX 1024

FILE* FileOpen(char* fileName){
	FILE *fp;
	// ファイルの読み込み
	fp = fopen( fileName, "r" );
	
	if(fp == NULL){
		fprintf(stderr, "file error\n");
		assert(fp != NULL);
	}
	return fp;
}

void Draw(FILE* fp1, FILE* fp2){

	char str1[MAX], str2[MAX];
	
	while( fgets( str1, MAX, fp1 ) != NULL  && fgets( str2, MAX, fp2 ) != NULL){
		printf("%s", str1);
		printf("%s", str2);
	}
	
	fclose(fp1);
	fclose(fp2);	
}

int main(int argc, char* argv[]){
	
	
	FILE *fp1, *fp2;	// テキストファイル
	
	assert(argc == 3);
	
	fp1 = FileOpen(argv[1]);
	fp2 = FileOpen(argv[2]);
	
	Draw(fp1, fp2);

	return 0;
}