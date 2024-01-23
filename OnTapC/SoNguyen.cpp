#include<stdio.h>
#include<string.h>
#define max 100

void nhap1(int &a){
	printf("Nhap vao day phan tu: ");scanf("%d",&a);
}

void nhap(int A[],int &n){
	printf("Nhap vao day n phan tu: ");scanf("%d",&n);
	for(int i = 0;i < n;i++){
		nhap1(A[i]);
	}
}

void xuat(int A[],int n){
	for(int i = 0;i < n;i++){
		printf("%d ",A[i]);
	}
}


int LinearSearch(int A[],int n,int x){
	for(int i = 0;i < n;i++){
		if(x == A[i])
		return i;
	}
	return -1;
}

int BinarySearch(int A[],int l,int r,int x){
	if(l > r) return -1;
	int mid = (l + r) / 2;
	if(x == A[mid]) return mid;
	if(x < A[mid]) return BinarySearch(A,l,mid - 1,x);
	if(x > A[mid]) return BinarySearch(A,mid + 1,r,x);
}

int binarySearch(int A[],int l,int r,int x){
	int mid = (l + r) / 2;
	while(x != A[mid]){
		if(x < A[mid]) mid = (l + mid - 1) / 2;
	    if(x > A[mid]) mid = (r + mid + 1) / 2;
	}
	if(mid > r || mid < l) return -1;
	return mid;
}

int main(){
	int A[max];
	int n;
	nhap(A,n);
	xuat(A,n);
	int x;
	printf("\nNhap vao so can tim: ");
	scanf("%d",&x);
    int k = binarySearch(A,0,n - 1,x);
    int z = BinarySearch(A,0,n - 1,x);
    if(k == -1)
    printf("Khong tim thay phan tu can tim!!!!\n");
    else{
    	printf("Tim thay phan tu can tim o vi tri %d\n",k + 1);
	}
	if(z == -1)
    printf("Khong tim thay phan tu can tim!!!!\n");
    else{
    	printf("Tim thay phan tu can tim o vi tri %d\n",z + 1);
	}
	return 0;
}
