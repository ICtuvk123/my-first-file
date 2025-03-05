#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
	int key;
	int ltag,rtag;//1:thread 0:side
	struct Node *lchild,*rchild;
}Node;

Node *getnewNode(int key) {
	Node *p=(Node *)malloc(sizeof(Node));
	p->key=key;
	p->ltag=p->rtag=0;
	p->lchild=p->rchild=NULL;
	return p;
}

Node *insert(Node *root,int key) {
	if(root==NULL) return getnewNode(key);
	if(rand()%2) root->lchild=insert(root->lchild,key);
	else root->rchild=insert(root->rchild,key);
	return root;
}

void clear(Node *root) {
	if(root==NULL) return;
	if(root->ltag==0) clear(root->lchild);
	if(root->rtag==0) clear(root->rchild);
	free(root);
	return ;
}

void preorder(Node *root) {
	if (root==NULL) return ;
	printf("%d ",root->key);
	if(root->ltag==0) preorder(root->lchild);
	if(root->rtag==0) preorder(root->rchild);
	return ;
}

void inorder(Node *root) {
	if (root==NULL) return ;
	if(root->ltag==0) inorder(root->lchild);
	printf("%d ",root->key);
	if(root->rtag==0) inorder(root->rchild);
	return ;
}

void postorder(Node *root) {
	if (root==NULL) return ;
	if(root->ltag==0) postorder(root->lchild);
	if(root->rtag==0) postorder(root->rchild);
	printf("%d ",root->key);
	return ;
}

Node *pre_node=NULL,*inorder_root=NULL;
void __build_inorder_thread(Node *root) {
	if (root==NULL) return ;
	if(root->ltag==0) __build_inorder_thread(root->lchild);
	if(inorder_root==NULL) inorder_root=root;
	if(root->lchild==NULL) {
		root->lchild=pre_node;
		root->ltag=1;
	}
	if(pre_node&&pre_node->rchild==NULL) {
		pre_node->rchild=root;
		pre_node->rtag=1;
	}
	pre_node=root;
	if(root->rtag==0) __build_inorder_thread(root->rchild);
	return ;
}

void build_inorder_thread(Node *root) {
	__build_inorder_thread(root);
	pre_node->rchild=NULL;
	pre_node->rtag=1;
	return ;
}

Node *getnext(Node *root) {
	if(root->rtag==1) return root->rchild;
	root=root->rchild;
	while (root->ltag==0&&root->lchild) root=root->lchild;
	return root;
}

int main() {
	srand(time(0));
	Node *root=NULL;
	#define MAX 10
	for (int i=0;i<MAX;i++) {
		root=insert(root,rand()%100);
	}
	pre_node=inorder_root=NULL;
	build_inorder_thread(root);
	preorder(root);printf("\n");
	inorder(root);printf("\n");
	postorder(root);printf("\n");
	//like linklist
	Node *node=inorder_root;
	while(node) {
		printf("%d ",node->key);
		node=getnext(node);
	}
	printf("\n");
	clear(root);
	return 0;
}
