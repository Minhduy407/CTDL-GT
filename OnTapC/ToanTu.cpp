#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//struct Node
//{
//	int data;
//	Node *pNext;
//};
//
//struct Stack
//{
//	Node *top;
//};
//
//void Initialize(Stack &S)
//{
//	S.top = NULL;
//}
//
//void  Push (Stack &S,  int  x)
//{
//	Node *p = new Node;
//	if (p==NULL)  { 
//		printf("Khong du bo nho"); 
//		return; 
//	}
//	p->data = x;
//	p->pNext= NULL;	
//	if (S.top==NULL)  	// Stack rong 
//		S.top = p;
//	else{	
//		p->pNext = S.top; //chèn lên dinh Stack 
//		S.top = p;	
//	}
//}
//
//int Pop (Stack &S)
//{	
//	if (S.top==NULL){
//		printf("Stack rong");
//		return -1;
//	}
//	int x;
//	Node *p = S.top;
//	p->pNext = NULL;
//	x = p->data;
//	S.top = S.top->pNext;
//	delete p;	
//	return x;		
//}

typedef char xau[10];
xau z,e[20],e1[20],s[20];
int i,j,n,top;
int uutien(xau z)
{
	int k=0;
	if(strcmp(z,"$")==0) k=1;
	if(strcmp(z,"(")==0) k=2;
	if(strcmp(z,"+")==0||strcmp(z,"-")==0) k=3;
	if(strcmp(z,"*")==0||strcmp(z,"/")==0) k=4;
	return k;
}

void taobtbalan()
{
	strcpy(s[1],"$"); 
	top=1;j=0;
	strcpy(z,e[1]); i=1;
	while (strcmp(z,"#") !=0)
	{
		if (strcmp (z,"(")==0) { 
			top++; 
			strcpy(s[top],z);
		}
		else {
			if (strcmp(z,")")==0)
			{
				while (strcmp(s[top],"(") !=0)
				{
					j++; strcpy(e1[j],s[top]);
					strcpy(s[top],"");top--;
				}
				strcpy(s[top],""); top--;
			}
			else {
				if (strcmp(z,"+")==0 || strcmp(z,"-")==0 || strcmp(z,"*")==0 || strcmp(z,"/")==0)
					{
						while (uutien(s[top])>= uutien(z))
						{
							j++;
							strcpy(e1[j],s[top]);
							strcpy(s[top],""); top--; 
						}
						top++;
						strcpy(s[top],z);
					}
				else {
					j++;
					strcpy(e1[j],z); 
				}	
			}
		}
	i++;strcpy(z,e[i]);
	}/*cuoi while */
	while (strcmp(s[top],"$") !=0)
	{
		j++;strcpy(e1[j],s[top]);
		strcpy(s[top],""); top--;}
		j++;
		strcpy(e1[j],"#");
	}
float giatri()
	{ 
	xau u,v,w; 
	float x,y,r;
	j=1; 
	strcpy(z,e1[j]); top=0;
	while (strcmp(z,"#") !=0)
	{
		printf("\nj= %d, z= %s",j,z);
		if (strcmp(z,"+")==0||strcmp(z,"-")==0 || strcmp(z,"*")==0 || strcmp(z,"/")==0 || strcmp(z,"(")==0 ||strcmp(z,")")==0)
		{ 
			strcpy(v,s[top]); 
			top--; 
			strcpy(u,s[top]); 
			top--;
			x=atof(u); 
			y= atof(v);
			if(strcmp(z,"+")==0) r = x + y;
			if(strcmp(z,"-")==0) r = x - y;
			if(strcmp(z,"*")==0) r = x * y;
			if(strcmp(z,"/")==0) r = x / y;
			sprintf(w,"%f",r); 
			top++;
			printf("\nx = %0.2f, y = %0.2f, w = %s",x,y,w); getch();
			strcpy(s[top],w);
		}
		else 
		{ 
		top++; 
		strcpy(s[top],z); };
		j++; 
		strcpy(z,e1[j]);
	}
	return atof(s[top]);
}

int main()
{ 	
	float gt; 
	printf("\nHay nhap so va dau + - * / () # : \n");
	i=1;
	do{
		gets(z); 
		strcpy(e[i],z); 
		i++; 
	}while (strcmp(z,"#") !=0);
	printf("\nbieu thuc so hoc goc :"); 
	n = i-1;
	for (i=1; i<=n;i++) 
	printf("%s ",e[i]); 
	printf("\n");
	taobtbalan();
	printf("\nBieu thuc toan hoc ba lan : "); j=1;

	do { 
		printf("%s ",e1[j]); strcpy(z,e1[j]); j++;
  	}while (strcmp(z,"#") !=0) ;
  	
	printf("\nTinh gia tri bieu thuc : "); gt = giatri();
	printf("\nGia tri bieu thuc la : %0.2f",gt) ;
	getch();
	return 0;
}
