#include <iostream>
#include <conio.h>
#include <stdio.h>
#define max 50
struct Stack
{ 
	int a[max];
    int Top;
} S; 
void Push(int n);
int Pop();
void  chuyen_doi(int N );

int main()
{
	int n;
	printf(" Nhap so can chuyen doi ");
	scanf("%d",&n);
	chuyen_doi(n);
	return 0;
}
void Push(int n)
{ 
if(S.Top>=max) printf ("Stack day");
else
	{  
		S.Top++;
		S.a[S.Top]=n;
	}
}
int Pop( )
{ 
if(S.Top == 0) return 0;
else 
	{
		int n = S.a[S.Top];
		S.Top--;
		return n;
	}
}
void  chuyen_doi( int N)
{
	int R; 
	while (N!=0)
	{ 
		R = N % 2;
 	 	Push(R);
  		N = N/2;
	}
	while (S.Top!=0)  printf("%d",Pop());
}

