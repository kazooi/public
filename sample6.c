#include <stdio.h>
#define  SIZE 5
static int tree1[SIZE], tree2[SIZE], tree3[SIZE];

int pie[20][3];
int sp[3],N;


/*
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
*/

//////////////////////////////////////////////////////////////////////

void init(){
	int i;
	for(i = 0; i < SIZE; i++){
		tree1[i] = i + 1;
		tree2[i] = 0;
		tree3[i] = 0;
	}
}

// タワーの移動
void move(int n, int it[],int go[]){
	int i,j;
	
	for(i = 0; i < SIZE; i++){
		tree1[i] = 0;
		tree3[i] = i + 1;	
	}
}

void hanoi(int n, int one[], int two[], int three[]){
	if(n < 1) return;
	hanoi(n-1, one, two, three);
	move(n, one, two);
	hanoi(n-1, three, two, one);
}


// タワーの中身を見る
void show(char type, int tree[]){
	printf("\n %c ", type);
	int i;
	for(i = 0; i < SIZE; i++){
		printf("%d", tree[i]);	
	}	
}

void allshow(){
	show('A', tree1);
	show('B', tree2);
	show('C', tree3);
}

int main(void){
	// 初期化
	init();
	
	hanoi(SIZE, tree1, tree2, tree3);
	
	int i;
	for(i = 0; i < SIZE * 100000000; i++){
		
	}
	
	// 結果表示
	allshow();
	
	return 0;
}
