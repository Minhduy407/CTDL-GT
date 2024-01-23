#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node{
	int data;
	Node *link;
};

struct List{
	Node *first,*last;
};

void Init(List &l){
	l.first = l.last = NULL;
}

Node *GetNode(int x){
	Node *p;
	p = new Node;
	if(p == NULL)
	return NULL;
	p->data = x;
	p->link = NULL;
	return p;	
}

Node* Search(List l, int x){
	Node *p = l.first;
	while(p != NULL){
		if(p->data == x){
			return p;
		}
		p = p->link;
	}
	return NULL;
}

void PrintList(List l){
	Node *p;
	p = l.first;
	while(p != NULL){
		printf("%10d",p->data);
		p = p->link;
	}
}

void AddFirst(List &l,Node* new_ele){
	if(l.first == NULL){
		l.first = new_ele;
		l.last = l.first;
	}
	else{
		new_ele->link = l.first;
		l.first = new_ele;
	}
}

void InsertFirst(List &l,int x){
	Node* new_ele = GetNode(x);
	if(new_ele == NULL)
	return;
	AddFirst(l,new_ele);
}

void CreateListFirst(List &l){
	printf("\nThem Node vao dau danh sach:\n");
	int x;
	do{
		printf("\nBat dau nhap danh sach cac so nguyen,nhap -1 de ket thuc: \n");
		scanf("%d",&x);
		if(x == -1)
		break;
		if(Search(l,x) == NULL){
			InsertFirst(l,x);
		}
		system("cls");
	}while(x != -1);
	printf("\nDa nhap du lieu xong: \n");
}

void AddLast(List &l,Node* new_ele){
	if(l.last == NULL){
		l.last = l.first = new_ele;
	}
	else{
		l.last->link = new_ele;
		l.last = new_ele;
	}
}


void Separating_List(List &L, List &L1, int x){
	List L2;
	Init(L2);
	
	Node *p = L.first;
	Node *a;
	Node *b;

	while(p != NULL){
		if(p->data > x){
			a = GetNode(p->data);
			AddLast(L1,a);
			p = p->link;
		}
		else{
			b = GetNode(p->data);
			AddLast(L2,b);
			p = p->link;
		}
	}
	L = L2;
}

void Sort(List &L){
	for(Node*i = L.first;i != L.last;i = i->link){
		for(Node*j = i->link;j != NULL;j = j->link){
			if(j->data < i->data){
				int x = i->data;
				i->data = j->data;
				j->data = x;
			}
		}
	}
}

int main(){
	List l;
	Init(l);
	CreateListFirst(l);
	PrintList(l);
	
	Sort(l);
	
	List l1;
	Init(l1);
	
	int x;
	printf("\nNhap vao day so lam moc de chia danh sach lien ket: ");
	scanf("%d",&x);
	
	Separating_List(l,l1,x);
	
	printf("\nDanh sach nho hon %d\n",x);
	PrintList(l);
	
	printf("\nDanh sach lon hon %d\n",x);
	PrintList(l1);
	return 0;
}
