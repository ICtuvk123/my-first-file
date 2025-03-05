#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct PriorityQueue
{
    int *__data,*data;
    int n,size;
}PriorityQueue;

void swap(int *x,int *y) {
    int *n;
    *n=*x;
    *x=*y;
    *y=*n;
    return ;
}

PriorityQueue *Initial_PriorityQueue(int size) {
    PriorityQueue *p=(PriorityQueue *)malloc(sizeof(PriorityQueue));
    p->__data=(int *)malloc(sizeof(int)*size);
    p->data=p->__data-1;
    p->n=0;
    p->size=size;
    return p;
}

int is_empty(PriorityQueue *p) {
    return p->n==0;
}

int is_full(PriorityQueue *p) {
    return p->n==p->size;
}

int top(PriorityQueue *p) {
    if(p==NULL) return 0;
    return p->data[1]; 
}

void up_update(int *data,int n) {
    if (n==1) return ;
    if (data[n]>data[n/2]) {
        swap(&data[n],&data[n/2]);
        up_update(data,n/2);
    }
    return ;
}

int push(PriorityQueue *p,int x) {
    if (is_full(p)) return 0;
    p->n++;
    p->data[p->n]=x;
    up_update(p->data,p->n);
    return 1;
}

void down_update(int *data,int i,int n) {
    int index;
    while ((2*i<=n)) {
        index=i;
        if (data[2*i]>data[i]) index=2*i;
        if ((2*i+1)<=n&&data[2*i+1]>data[index]) index=2*i+1;
        if (index==i) break;
        swap(&data[i],&data[index]);
        i=index;  
    }
    return ;
}

int pop(PriorityQueue *p) {
    if (is_empty(p)) return 0;
    p->data[1]=p->data[p->n];
    p->n--;
    down_update(p->data,1,p->n);
    return 1;
}

void clear_PriorityQueue(PriorityQueue *p) {
    if (p==NULL) return ;
    free(p->__data);
    free(p);
    return ;
}

void output(PriorityQueue *p) {
    printf("PQ(%d):",p->n);
    for (int i=1;i<=p->n;i++) {
        printf("%d ",p->data[i]);
    }
    printf("\n");
    return ;
}

int main() {
    PriorityQueue *p=Initial_PriorityQueue(100);
    int op,x;
    while (~scanf("%d",&op)) {
        if (op==1) {
            scanf("%d",&x);
            printf("insert %d to PriorityQueue :\n",x);
            push(p,x);
            output(p);
        } else {
            printf("top:%d\n",top(p));
            pop(p);
            output(p);
        }
    }
    return 0;
}