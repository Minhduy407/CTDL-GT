#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int data;
	Node *left;
	Node *right;
};

typedef Node *Tree;
Node *TaoNode(int x){
	Node*p = new Node;
	if(p == NULL)
		return NULL;
	p -> data = x;
	p -> right = NULL;
	p -> left = NULL;
	return p;
}

void ThemNodeVaoCay(Tree &T,Node *p){
	if(T == NULL)
		T = p;
	else{
		if(T -> data > p->data) ThemNodeVaoCay(T -> left,p);
		else if(T -> data < p->data) ThemNodeVaoCay(T -> right,p);
		else
			return;
	}
}

void Nhap(Tree &T){
	int chon = 0;
	do{
		int x;
		printf("\nNhap x: ");
		scanf("%d",&x);
		Node *p = TaoNode(x);
		ThemNodeVaoCay(T,p);
		printf("Muon nhap thong tin tiep ko? 1: co, 0: ko ~~>");
		scanf("%d",&chon);
	}while(chon != 0);
}

void Xuat(Tree T){
	if(T != NULL){
		Xuat(T -> left);
		printf("%d ",T -> data);
		Xuat(T -> right);
	}
}

int main(){
	Tree c = NULL;
	Nhap(c);
	printf("Xuat cay LNR (Tang dan): ");
	Xuat(c);
	return 0;
}
