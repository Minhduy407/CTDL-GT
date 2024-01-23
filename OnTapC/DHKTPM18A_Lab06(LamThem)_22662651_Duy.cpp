#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>

struct Node1{
    char data;
    Node1 *link;
};

struct stack1{
    Node1 *top;
};

//Khoi tao stack
void Init1(stack1 &s){
    s.top = NULL;
}

//Kiem tra stack rong
int Empty1(stack1 S) {
	if(S.top == NULL) return 1;
	else return 0;
}

//day 1 phan tu x vao stack
void Push1(stack1 &s , char x){
    Node1 * p = new Node1;
    if(p != NULL){
        p -> data = x;
        p -> link = s.top;
        s.top = p;
    }
}

//Trich thong tin va huy phan tu o top stack
char Pop1(stack1 &s){
    char x;
    if(!Empty1(s)){
        Node1 *p = s.top;
        s.top = p->link;
        x = p->data;
        delete(p);
        return x;
    }
}

//xet do uu tien
int uutien(char z)
{
	int k=0;
	if(z == '(') k=1;
	if(z == '+'||z == '-') k=2;
	if(z == '*'||z == '/') k=3;
	return k;
}

char *trung_hau(stack1 dau,char bieuthuc[]){
	char *bieuthucnew = new char[100];
  	int dem = 0;
	char c,x;
    for(int i = 0;i < strlen(bieuthuc);i++){
    	c = bieuthuc[i];
    	if(c == ' '){
    		i++;
			c = bieuthuc[i];	
		}
		if(isalnum(c)){
			bieuthucnew[dem++] = c;
		}
		else{
			if(c == '(')
				Push1(dau,c);
			else{
				if(c == ')'){
					while((x = Pop1(dau)) != '('){
						bieuthucnew[dem++] = x;
					}
				}
				else{
					while(!Empty1(dau) && uutien(c) <= uutien(dau.top->data)){
						x = Pop1(dau);
						bieuthucnew[dem++] = x;
					}
					Push1(dau,c);
				}
			}
		}
	}
	while(!Empty1(dau)){
		x = Pop1(dau);
		bieuthucnew[dem++] = x;
	}
  	return bieuthucnew;
}

int main(){
 	stack1 s;
  	Init1(s);
    char bieuthuc1[100] = "";
    printf("Nhap bieu thuc vao: \n");
    fflush(stdin);
    gets(bieuthuc1);
    char *bieuthuc2 = new char[100];
	bieuthuc2 = trung_hau(s,bieuthuc1);
    printf("\n%s",bieuthuc2);
    return 0;
}
