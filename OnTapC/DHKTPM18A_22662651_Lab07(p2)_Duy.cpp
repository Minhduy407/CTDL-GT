#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>

//Van de 2

typedef struct mathang{
	int mamh;
	char tenmh[12];
}mathang;

struct Node{
	mathang data;
	Node *next;
};

struct queue{
	Node* front;
	Node* rear;
};

void Initialize(queue &pq){
	pq.front = pq.rear = NULL; 
}

int Empty(queue pq){
	return (pq.front == NULL) ? 1 : 0;
}

void Insert(queue &pq,mathang x){
	Node * them = new Node{x,NULL};
	if(pq.front == NULL)
		pq.front = pq.rear = them;
	else{
		pq.rear -> next = them;
		pq.rear = them;
	} 
}

mathang Remove(queue &pq){
	if(!Empty(pq)){
		Node *p = pq.front;
		mathang x = p->data;
		pq.front = p->next;
		delete(p);
		return x;
	}
}

void Traverse(queue pq){
	Node *chay = pq.front;
	while(chay != NULL){
		printf("\n%11d%15s", chay->data.mamh, chay->data.tenmh);
		chay = chay -> next;
	}
}

int main(){
	queue q;
	mathang mh;
	Initialize(q);
	int chon;
	do{
		printf("\n\n\t\t\tCHUONG TRINH QUAN LY KHO");
		printf("\n\t\t\t(NHAP TRUOC - XUAT TRUOC)");
		printf("\n\nCac chuc nang cua chuong trinh:\n");
		printf("1: Nhap mot mat hang\n");
 	    printf("2: Xuat mot mat hang\n");
		printf("3: Xem mat hang chuan bi xuat\n");
		printf("4: Xem mat hang moi nhap\n");
 		printf("5: Xem cac mat hang co trong kho\n");
 		printf("6: Xuat toan bo kho hang\n");
 		printf("0: Ket thuc chuong trinh\n");
 		printf("Chuc nang ban chon: ");
 		scanf("%d", &chon);
 		switch(chon){
 			case 1:{
 				printf("\nMa mat hang: ");
 				scanf("%d", &mh.mamh);
 				getchar();
 				printf("Ten mat hang: ");
 				scanf("%s", &mh.tenmh);
 				Insert(q, mh);
				break;
			}
			case 2:{
				if(!Empty(q)){
					mh = Remove(q);
					printf("\nMat hang xuat:\nMa:%d\nTen:%s",mh.mamh, mh.tenmh);
				}
				break;
			}
			case 3:{
				Node*tmp = q.front;
				printf("\nMat hang chuan bi xuat:\nMa:%d\nTen:%s", tmp->next->data.mamh, tmp->next->data.tenmh);
				break;
			}
			case 4:{
				printf("\nMat hang moi nhap:\nMa:%d\nTen:%s",q.rear -> data.mamh,q.rear -> data.tenmh);
				break;
			}
			case 5:{
				printf("\nCac mat hang co trong kho:");
				printf("\n%11s%15s", "MA MAT HANG", "TEN MAT HANG");
				Traverse(q);
				break;
			}
			case 6:{
				char c;
				printf("\nBan co chac khong (c/k): ");
				fflush(stdin);
				scanf("%c",&c);
				if(c == 'c' || c == 'C')
					Initialize(q);
				break;
			}
		}
	}while(chon != 0);
	printf("\n\n\t\t\tCHUONG TRINH QUAN LY KHO");
	printf("\n\t\t\tKET THUC!!!");
	return 0;
}
