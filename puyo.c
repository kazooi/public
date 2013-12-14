#include <stdio.h>

int main(void){

	printf("0~4 \n 0:red 1:blue 2:green 3:yellow 4:purple\n");
	
	int n = 0;
	scanf("%d", &n);
	
	int i;
	for(i = 0; i < 48; i+=2){
		if(n % 5 == 0)
			printf("red    : %d~%d\n", i % 24, (i % 24 + 2));
		if(n % 5 == 1)
			printf("blue   : %d~%d\n", i % 24, (i % 24 + 2));
		if(n % 5 == 2)
			printf("green  : %d~%d\n", i % 24, (i % 24 + 2));
		if(n % 5 == 3)
			printf("yellow : %d~%d\n", i % 24, (i % 24 + 2));
		if(n % 5 == 4)
			printf("purple : %d~%d\n", i % 24, (i % 24 + 2));
		n++;
	}
	return 0;
}