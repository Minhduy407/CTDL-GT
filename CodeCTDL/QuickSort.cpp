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
/* Hàm thực hiện giải thuật partition */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    quickSort(A,0,n - 1);
    for(int i=0;i< n;i++){
        printf("%d ",A[i]);
    }
}