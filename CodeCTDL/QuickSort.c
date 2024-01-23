#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX 10000
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


void quicksort (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(left <= right){
        while(arr[left] < pivot){
            left++;
        }
        while(arr[right] > pivot){
            right--;
        }
        if(left <= right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    if(left < high){
        quicksort(arr,left,high);
    }
    if(right > low){
        quicksort(arr,low,right);
    }
}


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
    quicksort(A,0,n - 1);
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
}