#include <stdio.h>
#define  SIZE 5
static int tree1[SIZE], tree2[SIZE], tree3[SIZE];

int pie[20][3];
int sp[3],N;



// テスト
void move(int n,int s,int d)
{
  int i,j;

  pie[sp[d]][d]=pie[sp[s]-1][s];
  sp[d]++;
  sp[s]--;

  printf("\nNo.%d Disk is moved. %c-->%c\n",n,'a'+s,'a'+d);
  for(i=N-1;i>=0;i--) {
    for(j=0;j<3;j++) {
      if(i<sp[j])
	printf("%8d",pie[i][j]);
      else
	printf("        ");
    }
    printf("\n");
  }
  printf("\n       a       b       c\n");
//getchar();
}

void hanoi(int n,int a,int b,int c)
{
  if(n>0) {
    hanoi(n-1,a,c,b);
    move(n,a,b);
    hanoi(n-1,c,b,a);
  }
}


void main(void)
{
  int i;

//printf("Number of Disks ? ");
//scanf("%d",&N);
	N = SIZE;

  for(i=0;i<N;i++)
    pie[i][0]=N-i;
  sp[0]=N; sp[1]=0; sp[2]=0;

  hanoi(N,0,1,2);
}


//////////////////////////////////////////////////////////////////////

/*id init(){
	int i;
	for(i = 0; i < SIZE; i++){
		tree1[i] = 0;
		tree2[i] = 0;
		tree3[i] = 0;
	}
}

// 指定した数のタワーを作る
void h(int* s){

	if(*s == 0){
		return;	
	}
	else{
		//printf("%d", *s);
		tree1[*s] = *s;
	}
	
	*s = *s -1;
	h(s);
	
}

// タワーの移動
void sort(int one[], int two[], int tree[]){
	
	
}

// タワーの中身を見る
void show(char type, int tree[]){
	printf("\n %c ", type);
	int i;
	for(i = 1; i <= SIZE; i++){
		printf("%d", tree[i]);	
	}	
}

int main(void){
{
	// 初期化
	init();
	int s = SIZE;
	
	
	h(&s);
	
	// 結果表示
	show('A', tree1);
	show('B', tree2);
	show('C', tree3);
	
	return 0;
}
*/