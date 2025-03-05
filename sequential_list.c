#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int *element;
	int size;
}LIST;

int initlist(LIST *L) {
	L->element=(int *)malloc(sizeof(int)*20);
	if (!L->element) return 0;
	L->size=0;
	return 1;	
}//to create a void list

int insertlist(LIST *L,int i,int e) {
	if (L->size==20) return 0;
	if (i<1||i>L->size+1) return 0;
	for (int k=L->size-1;k>=i-1;k--) {
		L->element[k+1]=L->element[k];
	}
	L->element[i-1]=e;
	L->size++;
	return 1;
}

int deletelist(LIST *L,int i,int *e) {
	if (i<1||i>L->size) return 0;
	*e=L->element[i-1];
	for (int k=i;k<=L->size;k++) {
		L->element[k]=L->element[k+1];
	}
	L->size--;
	return 1;
}

void OUTPUT(LIST *L) {
	for (int i=1;i<=L->size;i++) {
		printf("%d ",L->element[i-1]);
	}
}

int main() {
	srand(time(0));
	LIST *L;
	int e;
	initlist(L);
	for (int i=1;i<=15;i++) {
		insertlist(L,i,rand()%100);
	}
	OUTPUT(L);
	printf("\n");
	insertlist(L,3,660);
	printf("after you insert the third number\n");
	OUTPUT(L);
	printf("\n");
	deletelist(L,4,&e);
	printf("after you delete the fifth number\n");
	OUTPUT(L);
	printf("\n");
	printf("that is uneasy right?");
	return 0;
}