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
    int min;
    for(int i = 0;i < n - 1;i++){
        min = i;
        for(int j = i + 1;j < n;j++){
            if(A[min] > A[j]){
                min = j;
            }
        }
        if(min != i){
        int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }    
    }
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
}