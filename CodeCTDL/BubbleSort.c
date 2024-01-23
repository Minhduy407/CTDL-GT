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
    for(int i = 0;i < n - 1;i++){
        for(int j = n - 1;j > i;j--){
            if(A[j] < A[j - 1]){
                int temp = A[j];
                A[j] = A[j -1];
                A[j - 1] = temp;
            }
        }
    }
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
}