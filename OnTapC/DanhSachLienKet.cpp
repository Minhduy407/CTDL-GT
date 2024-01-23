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

void PrintList1(List l){
	Node *p;
	p = l.first;
	while(p != NULL){
		printf("%10d",p->data);
		p = p->link;
	}
}

void PrintList2(List l){
	Node *p;
	p = l.first;
	while(p != NULL){
		printf("%x ",p);
		p = p->link;
	}
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

void AddLast(List &l,Node* new_ele){
	if(l.last == NULL){
		l.last = l.first = new_ele;
	}
	else{
		l.last->link = new_ele;
		l.last = new_ele;
	}
}

void AddAfter(List &l,Node* q,Node* new_ele){
	if(q != NULL){
		new_ele->link = q->link;
		q->link = new_ele;
		if(q == l.last) l.last = new_ele;
	}
	else AddFirst(l,new_ele);
}

void InsertFirst(List &l,int x){
	Node* new_ele = GetNode(x);
	if(new_ele == NULL)
	return;
	AddFirst(l,new_ele);
}

void InsertLast(List &l,int x){
	Node* new_ele = GetNode(x);
	if(new_ele == NULL)
	return;
	AddLast(l,new_ele);
}

void InsertAfter(List &l,int x,Node*q){
	Node* new_ele = GetNode(x);
	if(new_ele == NULL)
	return;
	AddAfter(l,new_ele,q);
}

void CreateListFirst(List &l){
	printf("\nThem Node vao dau danh sach:\n");
	int x;
	do{
		printf("\nBat dau nhap danh sach cac so nguyen,nhap -1 de ket thuc: \n");
		scanf("%d",&x);
		if(x == -1)
		break;
		InsertFirst(l,x);
		system("cls");
	}while(x != -1);
	printf("\nDa nhap du lieu xong: \n");
}

void CreateListLast(List &l){
	int x;
	printf("\nThem Node vao cuoi danh sach:\n");
	do{
		printf("\nBat dau nhap danh sach cac so nguyen,nhap -1 de ket thuc: \n");
		scanf("%d",&x);
		if(x == -1)
		break;
		InsertLast(l,x);
		system("cls");
	}while(x != -1);
	printf("\nDa nhap du lieu xong: \n");
}	

void CreateListAfter(List &l){
	int x,moc;
	PrintList1(l);
	printf("\nNhap node can lam moc de them cac so nguyen vao: \n");
	scanf("%d",&moc);
	Node* q = GetNode(moc);
	do{
		system("cls");
		printf("\nNhap danh sach cac so nguyen,nhap -1 de ket thuc: \n");
		scanf("%d",&x);
		if(x == -1)
		break;
		InsertAfter(l,x,q);
	}while(x != -1);
	printf("\nDa nhap du lieu xong: \n");
}

long SumEvenNumber (List l){
	long sum = 0;
	Node *p = l.first;
	while(p != NULL){
		if(p->data % 2 == 0){
			sum += p->data;
			p = p->link;
		}
		else
			p = p->link;
	}
	return sum;
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

void SListAppend(List &l, List &l2)
{
	if (l2.first == NULL) return;
	if (l.first == NULL) 
		l = l2;
	else {
		l.last->link = l2.first;
		l.last = l2.last;
	} 
	Init(l2);
}

void SListQSort(List &l) {
	Node *X, *p;
	List l1, l2;
	if (l.first == l.last) return;
		Init(l1); Init(l2);
		X = l.first; l.first= l.first -> link;
		X -> link= NULL;
	while(l.first != NULL){
		p = l.first;
		l.first= l.first -> link;
		p -> link = NULL;
		if (p->data <= X->data) InsertFirst(l1, p->data);
		else InsertFirst(l2, p->data);
	}
	SListQSort(l1); 
	SListQSort(l2);
	if(l1.first != NULL){
		l.first = l1.first;
		l1.last->link = X;
	}
	else{
		l.first = X;
		X -> link = l2.first;
	}
	if(l2.first != NULL){
		l.last = l2.last;
	}	
	else l.last = X;
}

int main(){
	List l;
	Init(l);
	CreateListFirst(l);
	SListQSort(l);
	PrintList1(l);
	printf("\nIn ra dia chi cua tung Node:\n");
	PrintList2(l);
	long x = SumEvenNumber(l);
	printf("\nSUM = %ld\n",x);
	List l1;
	Init(l1);
	CreateListLast(l1);
	PrintList1(l1);
	int k;
	SListAppend(l,l1);
	PrintList1(l);
	printf("\nNhap vao day phan tu can tim: ");
	scanf("%d",&k);
	Node* a = Search(l,k);
	if(a != NULL)
	printf("Node can tim nam o vi tri co dia chi la %x\n",a);
	else printf("Khong tim thay node can tim!\n");
	return 0;
}
