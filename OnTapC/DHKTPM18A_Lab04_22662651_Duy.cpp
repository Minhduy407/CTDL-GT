#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node{
	float heSo;
	int soMu;
	Node *link;
};

struct List{
	Node *first,*last;
};

void Init(List &l){
	 l.first = l.last = NULL;
}

Node *GetNode(float heSo,int soMu)
{
	Node *p;
	p = new Node;
	if(p == NULL)
		return NULL;
	p->heSo = heSo;
	p->soMu = soMu;
	p->link = NULL;
	return p;
}

void addLast(List &l,Node *new_ele){
	if(l.first == NULL)
		l.first = l.last = new_ele;
	else{
		l.last->link = new_ele;
		l.last = new_ele;
	}
}

void InsertLast (List &l,float heSo,int soMu){
	Node *p = new Node;
	if(p == NULL){
		printf("Khong du bo nho");
		return;
	}
	p = GetNode(heSo,soMu);
	addLast(l,p);
}

void nhapDathuc(List &L){
	float heSo;
	int soMu;
	printf("\nBat dau nhap da thuc (nhap he so 0 de ket thuc): \n");
 	do{
 		printf("\nNhap he so: ");
 		scanf("%f",&heSo);
 		if(heSo == -0)
 			break;
 		printf("\nNhap so mu:");
 		scanf("%d",&soMu);
 		InsertLast(L,heSo,soMu);
	}while(heSo != 0);
	printf("\nDa nhap da thuc xong: \n");
}

void xuatDaThuc(List L){
	Node *p = L.first;
	printf("%.0f*x^%d ", p->heSo, p->soMu);
	p = p -> link;
	while(p != NULL && p != L.last){
		if(p -> heSo > 0 )
			printf("+ %.0f*x^%d ", p->heSo, p->soMu);
		else
			printf("- %.0f*x^%d ", p->heSo * -1, p->soMu);
		p = p -> link;
	}
	if(p -> soMu == 0){
		if(p -> heSo > 0 )
			printf("+ %.0f", p->heSo);
		else
			printf("- %.0f", p->heSo * -1);
	}
	else{
		if(p -> heSo > 0 )
			printf("+ %.0f*x^%d", p->heSo, p->soMu);
		else
			printf("- %.0f*x^%d", p->heSo * -1, p->soMu);
	}
}

void congDathuc(List &L1,List &L2,List &L3){
	Node *p1 = L1.first;
	Node *p2 = L2.first;
	float tongheSo;
	while(p1 != NULL && p2 != NULL){
		if(p1 -> soMu == p2 -> soMu){
			tongheSo = p1 -> heSo + p2 -> heSo;
			InsertLast(L3,tongheSo,p1 -> soMu);
			p1 = p1 -> link;
			p2 = p2 -> link;
		}
		else if(p1 -> soMu > p2 -> soMu){
			InsertLast(L3,p1 -> heSo,p1 -> soMu);
			p1 = p1 -> link;
		}
		else{
			InsertLast(L3,p2 -> heSo,p2 -> soMu);
			p2 = p2 -> link;
		}
	}
	while(p1 != NULL){
		InsertLast(L3,p1 -> heSo,p1 -> soMu);
		p1 = p1 -> link;
	}
	while(p2 != NULL){
		InsertLast(L3,p2 -> heSo,p2 -> soMu);
		p2 = p2 -> link;
	}
}

void congDathuc(List &L1,List &L2,List &L3){
	Node *p1 = L1.first;
	Node *p2 = L2.first;
	float hieuheSo;
	while(p1 != NULL && p2 != NULL){
		if(p1 -> soMu == p2 -> soMu){
			hieuheSo = p1 -> heSo - p2 -> heSo;
			InsertLast(L3,tongheSo,p1 -> soMu);
			p1 = p1 -> link;
			p2 = p2 -> link;
		}
		else if(p1 -> soMu > p2 -> soMu){
			InsertLast(L3,p1 -> heSo,p1 -> soMu);
			p1 = p1 -> link;
		}
		else{
			InsertLast(L3,(p2 -> heSo) * -1,p2 -> soMu);
			p2 = p2 -> link;
		}
	}
	while(p1 != NULL){
		InsertLast(L3,p1 -> heSo,p1 -> soMu);
		p1 = p1 -> link;
	}
	while(p2 != NULL){
		InsertLast(L3,(p2 -> heSo) * -1,p2 -> soMu);
		p2 = p2 -> link;
	}
}

void InterchangeSort(List &L){
	for(Node*i = L.first;i != L.last;i = i->link){
		for(Node*j = i -> link;j != NULL;j = j->link){
			if(i -> soMu > j -> soMu){
				//doi so mu 
				int somutmp  = i -> soMu;
				i -> soMu = j -> soMu;
				j -> soMu = somutmp;
				//doi he so
				int hesotmp  = i -> heSo;
				i -> heSo = j -> heSo;
				j -> heSo = somutmp;  
			}	
		}											
	}
}

int main(){
	List L1,L2,L3;
	Init(L1);
//	Init(L2);
//	Init(L3);
	printf("Nhap da thuc 1\n");
	nhapDathuc(L1);
//	InterchangeSort(L1);
//	printf("Nhap da thuc 2\n");
//	nhapDathuc(L2);
//	InterchangeSort(L2);
//	congDathuc(L1,L2,L3);
//	printf("Tong 2 da thuc\n");
	xuatDaThuc(L1);
	return 0;
}

