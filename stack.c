#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack {
	int *data;
	int size,top;
}Stack;

Stack *initStack(int n) {
	Stack *s=(Stack *)malloc(sizeof(Stack));
	s->data=(int *)malloc(sizeof(int)*n);
	s->size=n;
	s->top=-1;
	return s;
}//create a initial stack

int empty(Stack *s) {
	return s->top==-1;
}//to avoid the stack has no elements

int top(Stack *s) {
	if (empty(s)) return 0;
	return s->data[s->top];
}//to find the top element

int push(Stack *s,int n){
	if (s->top+1==s->size) return 0;
	s->top+=1;
	s->data[s->top]=n;
	return 1;
}//push an element

int pop(Stack *s) {
	if (empty(s)) return 0;
	s->top-=1;
	return 1;
}//to pop out an element

void clearStack(Stack *s){
	if (empty(s)) return ;
	free(s->data);
	free(s);
	return ;
}//free the memory

void outputStack(Stack *s) {
	printf("Stack: ");
	for (int i=s->top;i>=0;--i) {
		printf("%4d",s->data[i]);
	}
	printf("\n");
	return ;
}//out out the result

int main() {
	srand(time(0));
	Stack *s=initStack(5);
	for (int i=0;i<10;i++) {
		int op=rand()%3,val=rand()%100;
		switch (op) {
			case 0:
				printf("pop stack,item=%d\n",top(s));
				printf("\n");
				pop(s);
				break;
			case 1:
			case 2:
				printf("push stack,item=%d\n",val);
				printf("\n");
				push(s,val);
				break;
		}
		outputStack(s);
	}
	return 0;
}