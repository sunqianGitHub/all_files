
#include <stdio.h>
#define N 8

#define DEBUG

void show(int a[]);
void bubblesort(int a[]);
int main(void)
{
	int a[N] = {50,36,66,76,95,12,25,36};

	show(a);
	bubblesort(a);

	return 0;
}

void bubblesort(int a[])
{
	int i,j,t;
#ifdef DEBUG
	int flag;
#endif
	for(i = 0; i < N-1; i++){
#ifdef DEBUG
		flag = 1;
#endif
		for(j = 0; j < N-1-i; j++)
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
#ifdef DEBUG
				flag = 0;
#endif
			}
#ifdef DEBUG
		if(flag == 1)   //记录已经有序，则结束排序
			break;
#endif
		printf("第%d趟:",i+1);
		show(a);
	}
}

void show(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d\t",a[i]);
	printf("\n");
}

