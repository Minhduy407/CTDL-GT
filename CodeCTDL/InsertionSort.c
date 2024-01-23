#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAX 10000

int main(){
    int A[MAX];
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for(int i=0;i< n;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    int pos, x;  
    for(int i = 1;i < n;i++){
        x = A[i];
        pos =  i - 1;
        while(pos >= 0 && A[pos] > x){ 
            A[pos + 1] = A[pos];
            pos--;
        }
        A[pos + 1] = x; 
    }
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
}