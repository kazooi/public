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

// 読み込んだファイいるの計算
void Calc(FILE* fp){
        
        int i, j;
        int count = 0, total = 0, add = 0;
        int c = 0;
        int s[MAX];
        bool flag = true;
        
	while( (c = fgetc( fp )) != EOF ){
		if(c == ' ') continue;
		printf("%c", c);
		if(c == '+' || c == '-' || c == '='){
			
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
			flag = true;
			if(c == '-'){
				flag = false;
			}
			if(c == '='){
				printf("%d \n", total);
				return;
			}
			count = 0;
                        add = 0;
			continue;
		}
		//　yuniko-do
		s[count] = c - 48;
                count++;
	}
}

int main(int argc, char* argv[]){
        
        
        FILE *fp1;        // テキストファイル
        
        //assert(argc == 3);
        
        fp1 = FileOpen(argv[1]);
        
        Calc(fp1);

        return 0;
}
