#include<stdio.h>
#include<stdlib.h>

struct Node
{ 
 	int balFactor;
 	Node* pLeft; 
 	Node* pRight; 
 	int idata; 
}; 
typedef Node* Tree;

Node* TaoNode(int X) 
{ 
 	Node* p = new Node; 
 	if(p == NULL) 
 		return NULL; 
 	p->pLeft = NULL; 
 	p->pRight = NULL; 
 	p->idata=X; 
 	return p; 
} 

void Xuat(Tree c)  
{  
    if(c!=NULL)  
    {  
        if(c->pLeft != NULL)              
			Xuat(c->pLeft);          
		printf("%4d", c->idata);      
        if(c->pRight != NULL)  
            Xuat(c->pRight);  
    }  
}  

void rotateLL(Tree &T){
	Node* T1 = T -> pLeft;
	T ->pLeft = T1 ->pRight;
	T1 ->pRight = T;
	switch(T1 ->balFactor){
		case -1:{
			T ->balFactor = 0;
			T1 ->balFactor = 0;
			break;
		}
		case 0:{
			T ->balFactor = -1;
			T1 ->balFactor = 1;
			break;
		}
	}
	T = T1;
}

void rotateLR(Tree &T){
	Node* T1 = T -> pLeft;
	Node* T2 = T -> pRight;
	T ->pLeft = T2 ->pRight;
	T2 ->pRight = T;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch(T2 ->balFactor){
		case -1:{
			T ->balFactor = 1;
			T1 ->balFactor = 0;
			break;
		}
		case 0:{
			T ->balFactor = 0;
			T1 ->balFactor = 0;
			break;
		}
		case 1:{
			T ->balFactor = 0;
			T1 ->balFactor = -1;
			break;
		}
	}
	T2->balFactor = 0;  
	T = T2;
}

int balanceLeft(Tree &T){
	Node* T1 = T -> pLeft;
	switch(T1->balFactor){
		case -1:{
			rotateLL(T);
			return 2;
			break;
		}
		case 0:{
			rotateLL(T);
			return 1;
			break;
		}
		case 1:{
			rotateLR(T);
			return 2;
			break;
		}
	}
	return 0;
}

void rotateRR(Tree &T){
	Node* T1 = T -> pRight;
	T ->pRight = T1 ->pLeft;
	T1 ->pLeft = T;
	switch(T1 ->balFactor){
		case 1:{
			T ->balFactor = 0;
			T1 ->balFactor = 0;
			break;
		}
		case 0:{
			T ->balFactor = 1;
			T1 ->balFactor = -1;
			break;
		}
	}
	T = T1;
}

void rotateRL(Tree &T){
	Node* T1 = T -> pRight;
	Node* T2 = T -> pLeft;
	T ->pRight = T2 ->pLeft;
	T2 ->pLeft = T;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	switch(T2 ->balFactor){
		case 1:{
			T ->balFactor = -1;
			T1 ->balFactor = 0;
			break;
		}
		case 0:{
			T ->balFactor = 0;
			T1 ->balFactor = 0;
			break;
		}
		case -1:{
			T ->balFactor = 0;
			T1 ->balFactor = 1;
			break;
		}
	}
	T2->balFactor = 0;  
	T = T2;
}

int balanceRight(Tree &T){
	Node* T1 = T -> pLeft;
	switch(T1->balFactor){
		case -1:{
			rotateRL(T);
			return 2;
			break;
		}
		case 0:{
			rotateRR(T);
			return 1;
			break;
		}
		case 1:{
			rotateRR(T);
			return 2;
			break;
		}
	}
	return 0;
}

int insertNode(Tree &T,int x){
	int res;
	if(T){
		if(T->idata == x) return 0;
		if(T->idata > x){
			res = insertNode(T->pLeft,x);
			if(res < 2) return res;
			switch(T->balFactor){
				case 1:{
					T -> balFactor = 0;return 1;
					break;
				}
				case 0:{
					T -> balFactor = -1; return 2;
					break;
				}
				case -1:{
					balanceLeft(T);
					return 1;
					break;
				}
			}
		}
		else{
			res = insertNode(T->pRight,x);
			if(res < 2) return res;
			switch(T -> balFactor){
				case -1:{
					T -> balFactor = 0;
					return 1;
					break;
				}
				case 0:{
					T -> balFactor = 1; return 2;
					break;
				}
				case 1:{
					balanceRight(T);
					return 1;
					break;
				}
			}
		}
	}
	T = new Node;
	if(T == NULL) return -1;
	T -> idata = x;
	T -> balFactor = 0;
	T -> pLeft = T -> pRight = NULL;
	return 2;
}

void Nhap(Tree &c)  {   
 	int chon = 0;      
	do  
    {   int x;  
        printf("\nNhap x: ");   
		scanf("%d",&x);     
		insertNode(c,x);          
		printf("Muon nhap thong tin tiep ko? 1: co, 0: ko ~~>"); 
		scanf("%d",&chon);  
    }while(chon);  
} 

int demsonodela(Tree T){
	if(T == NULL) return 0;
	if(T -> pLeft == NULL && T -> pRight == NULL)
		return 1;
	return demsonodela(T -> pLeft) + demsonodela(T -> pRight);
} 

int tinhchieucao(Tree T){
	if(T == NULL) return 0;
	if(T -> pLeft == NULL && T -> pRight == NULL)
		return 1;
	int a = tinhchieucao(T -> pLeft);
	int b = tinhchieucao(T -> pRight);
	if(a > b) return 1 + a;
	return 1 + b;
}

Node *timx(Tree T,int x){
	if(T) {
		if(T -> idata == x) return T;
		if(T -> idata > x) return timx(T -> left,x);
		else return timx(T -> right,x);
	}
	return T;
}

int main(){
	Tree T = NULL;
	Nhap(T);
	Xuat(T);
	printf("\nSo node la trong cay: %d",demsonodela(T));
	printf("\nChieu cao cay: %d",tinhchieucao(T));
	return 0;
}


