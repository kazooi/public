#include <stdio.h>
#include <stdbool.h>
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

// 読み込んだファイいるの計算
void Calc(FILE* fp){
	
	int i, j;
	int count = 0, total = 0, add = 0;
	int c = 0;
	int s[MAX];
	bool flag = true;
	
	while( (c = fgetc( fp )) != EOF ){
		switch(c){
			case '+':
			add = count;
			for(i = 0; i < add; i++){
				for(j = 1; j < count; j++){
					s[i] *= 10;
				}
				count--;
			}
			
			if(flag){
				for(i = 0; i < add; i++){
					total += s[i];
				}
			}else{	
				for(i = 0; i < add; i++){
					total -= s[i];
				}
			}
			count = 0;
			add = 0;
			flag = true;
			break;
			
			case '-':
			add = count;
			for(i = 0; i < add; i++){
				for(j = 1; j < count; j++){
					s[i] *= 10;
				}
				count--;
			}
			
			if(flag){
				for(i = 0; i < add; i++){
					total += s[i];
				}
			}else{	// すでに保存している場合
				for(i = 0; i < add; i++){
					total -= s[i];
				}
			}
			printf("%d 00 \n", total);
			count = 0;
			add = 0;
			flag = false;
			break;
			
			case '=':
			add = count;
			for(i = 0; i < add; i++){
				for(j = 1; j < count; j++){
					s[i] *= 10;
				}
				count--;
			}
			
			
			
			if(flag){
				for(i = 0; i < add; i++){
					total += s[i];
				}
			}else{
				for(i = 0; i < add; i++){
					total -= s[i];
				}
			}
			return;
			break;
			
			case ' ':
			break;
			
			case '\n':
			break;
			
			default:
			s[count] = c - 48;
			//printf("%d\n", s[count]);
			count++;
			break;
		}
	}
}

int main(int argc, char* argv[]){
	
	
	FILE *fp1, *fp2;	// テキストファイル
	
	//assert(argc == 3);
	
	fp1 = FileOpen(argv[1]);
	
	Calc(fp1);

	return 0;
}