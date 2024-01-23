#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>

struct Node{
	char data;
	Node *next;
};

struct Stack{
	Node *top;
};

void Init(Stack &s){
	s.top = NULL;
}

int isEmpty(Stack s){
	return s.top == NULL ? 1 : 0;
}

void Push(Stack &s,char x){
	Node *tmp = new Node;
	tmp -> data = x;
	tmp -> next = NULL;
	if(s.top == NULL)
		s.top = tmp;
	else{
		tmp -> next = s.top;
		s.top = tmp;
	}
}

char Pop(Stack &s){
	if(s.top != NULL){
		Node* tmp = s.top;
		char x = tmp -> data;
		s.top = s.top -> next;
		delete tmp;
		return x;
	}
}

int uutien(char z){
	if(z == '*' || z == '/' || z == '^') return 3;
	if(z == '+' || z == '-') return 2;
	if(z == '(') return 1;
	return 0;
}

char *trung_hau(Stack dau,char bieuthuc[]){
	char *newbt = new char[1000];
	int dem = 0;
	char c;
	for(int i = 0;i < strlen(bieuthuc);i++){
		c = bieuthuc[i];
		if(isalnum(c)){
			newbt[dem++] = c;
			newbt[dem++] = ' ';
		}
		else if(c != '#'){		
			if(c == '(')
				Push(dau,c);
			else if(c != ' '){
				if(c == ')'){
					while(dau.top->data != '('){
						newbt[dem++] = Pop(dau);
						newbt[dem++] = ' ';
					}
				}
				else{
					while(!isEmpty && uutien(c) <= uutien(dau.top -> data)){
						char x = Pop(dau);
						newbt[dem++] = x;
						newbt[dem++] = ' ';
					}
					Push(dau,c);
				}
			}
		}
	}
	while(!isEmpty(dau)){
		char x = Pop(dau);
		newbt[dem++] = x;
		newbt[dem++] = ' ';
	}
	newbt[dem++] = '#';
	return newbt;
}


int main(){
	Stack s;
  	Init(s);
    char bieuthuc1[100] = "";
    printf("Nhap bieu thuc vao: \n");
    fflush(stdin);
    gets(bieuthuc1);
    printf("%s",bieuthuc1);
    char *bieuthuc2 = new char[100];
	bieuthuc2 = trung_hau(s,bieuthuc1);
    printf("\n%s",bieuthuc2);
    return 0;
}
