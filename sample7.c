#include <stdio.h>
#define MAX 5

int a[] = {1,2,3,4,5};
static int l = 0;

void s(int card[]){
	
	if(l < 1) return;
	
	int b[MAX] = {0,0,0,0,0}, c[MAX] = {0,0,0,0,0};
	int i, x, y;
	
	x = y = 0;
	for(i = 0; i < MAX; i++){
		if(i % 2 == 0){
			b[x] = a[i];
			x++;	
		}else{
			c[y] = a[i];	
			y++;
		}
	}
	
	x = y = 0;
	for(i = 0; i < MAX; i++){
		a[i] = c[x];
		if(a[i] == 0){
			a[i] = b[y];
			y++;
		}
		x++;
	}
	l--;
	s(a);
}

int main(void){

	printf("0 ~  \n");
	
	while(l <= 0){
		scanf("%d", &l);
	}
	
	s(a);
	int i;
	// 結果の表示
	for(i = 0; i < MAX; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
// 世界のナベアツアルゴリズムのプログラムをやってくる