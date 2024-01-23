#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>

struct Node{
    int data;
    Node *link;
};

struct queue{
    Node *front,*rear;
};

//Khoi tao stack
void Init(queue &q){
    q.front = NULL;
}

//Kiem tra stack rong
int Empty(queue s){
    return s.front == NULL ? 1 : 0;
}

//them 1 phan tu
void EnQueue(queue &q,int x){
	Node * p = new Node;
	p -> data = x;
	p -> link = NULL;
	if(Empty(q)){
		q.front = q.rear = p; 
	}
	else{
		q.rear -> link = p;
		q.rear = p;
	}
}

// trich thong tin va huy phan tu o dinh Queue
int DeQueue(queue &q){
	if(Empty(q)){
		return 1;
	}
	Node *p = q.front;
	q.front = q.front -> link;
	if(Empty(q))
		q.rear = NULL;
	int x = p->data;
	p -> link = NULL;
	delete(p);
	return x;
}

//xem phan tu dau Queue
int Front(queue q){
	if(Empty(q)) return 1;
	return q.front -> data;
}

int main(){
	int k;
	queue q;
	Init(q);
	printf("\nNhap cac phan tu vao Queue (-1 de ket thuc): ");
	do{
		scanf("%d",&k);
		if(k != -1)
			EnQueue(q,k);
	}while(k != -1);
	printf("\n\nLay cac phan tu ra khoi Queue: ");
	while(!Empty(q)){
		k = DeQueue(q);
		printf("%d ",k);
	}
}
