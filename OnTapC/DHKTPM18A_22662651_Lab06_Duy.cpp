#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>


struct Node{
    float data;
    Node *link;
};

struct stack{
    Node *top;
};

//Khoi tao stack
void Init(stack &s){
    s.top = NULL;
}

//Kiem tra stack rong
int Empty(stack S) {
	if(S.top == NULL) return 1;
	else return 0;
}

//day 1 phan tu x vao stack
void Push(stack &s , float x){
    Node * p = new Node;
    if(p != NULL){
        p -> data = x;
        p -> link = s.top;
        s.top = p;
    }
}

//Trich thong tin va huy phan tu o top stack

float Pop(stack &s){
    float x;
    if(!Empty(s)){
        Node *p = s.top;
        s.top = p->link;
        x = p->data;
        delete(p);
        return x;
    }
}

//doc tu
void DocTu(char s[], char t[], int &i) {
	for(int dem = 0; dem < strlen(t); dem++) {
		t[dem] = ' ';
	}
	int dem = 0;
	while(s[i] != ' ') {
		t[dem] = s[i];
		i++;
		dem++;
	}
}

//kiem tra toan tu
int LaToanTu(char s[]){
    char c = s[0];
    if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'))
        return 1;
    return 0;
}

//tinh toan
float TinhToan(float toanhang1,float toanhang2,char toantu){
    float kq;
    switch(toantu){
        case '+':{
            kq = toanhang1 + toanhang2;
            break;
        } 
        case '-': {
            kq = toanhang1 - toanhang2;
            break;
        }
        case '*':{
            kq = toanhang1 * toanhang2;
            break;
        } 
        case '/':{
            kq = toanhang1 / toanhang2;
            break;
        }
        case '^':{
        	kq = pow(toanhang1,toanhang2);
			break;
		}
    }
    return kq;
}

//tinh bieu thuc
float TinhBieuThuc(stack &s,char bieuthuc[]){
    float kq;
    char t[10];
    int i = 0;
    do{
        DocTu(bieuthuc,t,i);
        
        if(LaToanTu(t)){
            char toantu = t[0];
            float toanhang1 = Pop(s);
            float toanhang2 = Pop(s);
            kq = TinhToan(toanhang1,toanhang2,toantu);
            Push(s,kq);
        }
        
        else{
            float toanhang = atof(t);
            Push(s,toanhang);
        }
        i++;
    }while(bieuthuc[i] != '#');
    
    return Pop(s);
}

int main(){
    stack s;
    Init(s);
    char bieuthuc[100] = "";
    printf("Nhap bieu thuc vao: \n");
    fflush(stdin);
    gets(bieuthuc);
    float kq;
    kq = TinhBieuThuc(s,bieuthuc);
    printf("\nKet qua bieu thuc: %f",kq);
    return 0;
}

