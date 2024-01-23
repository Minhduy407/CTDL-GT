#include<stdio.h>
#include<iostream>
#include <conio.h>

struct Node
{
	int data;
	Node *pNext;
};

struct Stack
{
	Node *top;
};

void Initialize(Stack &S)
{
	S.top = NULL;
}

int  isEmpty (Stack S)
{ 
	return  S.top == NULL ? 1 : 0; 
}

void  Push (Stack &S,  int  x)
{
	Node *p = new Node;
	if (p==NULL)  { 
		printf("Khong du bo nho"); 
		return; 
	}
	p->data = x;
	p->pNext= NULL;	
	if (S.top==NULL)  	// Stack rong 
		S.top = p;
	else{	
		p->pNext = S.top; //chèn lên dinh Stack 
		S.top = p;	
	}
}

int Pop (Stack &S)
{	
	if (S.top==NULL){
		printf("Stack rong");
		return -1;
	}
	int x;
	Node *p = S.top;
	S.top = p->pNext;
	p->pNext = NULL;
	x = p->data;
	delete p;	
	return x;		
}

void chuyen_doi(Stack &s,int x){
	int r;
	while(x != 0){
		r = x % 2;
		Push(s,r);
		x = x / 2;
	}
	while(s.top != NULL){
		printf("%d",Pop(s));
	}
}

int main(){
//	int min = minOperation(67);
//	printf("%d",min);
	int i = 100;
	Stack s;
	Initialize(s);
	chuyen_doi(s,i);
	return 0;
}


