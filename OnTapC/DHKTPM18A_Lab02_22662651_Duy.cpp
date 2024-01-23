#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 50

void swap(int &a,int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void SelectionSort(int A[],int n){
	int min;
    for(int i = 0;i < n - 1;i++){
        min = i;
        for(int j = i + 1;j < n;j++){
            if(A[min] > A[j]){
                min = j;
            }
        }
        if(min != i){
        swap(A[i],A[min]);
        }    
    }
}

void InsertionSort(int A[],int n){
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
}

void InterchangeSort(int A[],int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(A[i] > A[j])
			swap(A[i],A[j]);
		}
	}
}

void BubbleSort(int A[],int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = n - 1;j > i;j--){
			if(A[j] < A[j - 1])
			swap(A[j],A[j - 1]);
		}
	}
}

void QuickSort(int A[],int left,int right){
	int mid = A[(left + right) / 2];
	int l = left,r = right;
	while(l <= r){
		while(A[l] < mid) l++;
		while(A[r] > mid) r--;
		if(l <= r){
			swap(A[l],A[r]);
		    l++,r--;
		}
	}
	if(left < r) QuickSort(A,left,r);
	if(l < right) QuickSort(A,l,right);
}


void randommang(int A[],int &n){
	srand(time(NULL));
	printf("Nhap vao day so phan tu can random: ");
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		A[i] = rand() % 100;
	}
}

void xuat(int A[],int n){
	for(int i = 0;i < n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

clock_t start,end;

int main(){
	int A[max],n;
	double t1,t2,t3,t4,t5;
	int chon;
	do{
		printf("\n----Menu----\n");
		printf("1. SelectionSort\n");
		printf("2. InsertionSort\n");
		printf("3. InterchangeSort\n");
		printf("4. BubbleSort\n");
		printf("5. QuickSort\n");
		printf("6. So sanh 5 thuat toan\n");
		printf("7. Exit\n");
		printf("Chon = ");
		scanf("%d",&chon);
		switch(chon){
		case 1:{
			randommang(A,n);
			xuat(A,n);
			start = clock();
			SelectionSort(A,n);
			end = clock();
			t1 = end - start;
			xuat(A,n);
			break;
		}
		case 2:{
			randommang(A,n);
			xuat(A,n);
			start = clock();
			InsertionSort(A,n);
			end = clock();
			t2 = end - start;
			xuat(A,n);
			break;
		}
		case 3:{
			randommang(A,n);
			xuat(A,n);
			start = clock();
			InterchangeSort(A,n);
			end = clock();
			t3 = end - start;
			xuat(A,n);
			break;
		}
		case 4:{
			randommang(A,n);
			xuat(A,n);
			start = clock();
			BubbleSort(A,n);
			end = clock();
			t4 = end - start;
			xuat(A,n);
			break;
		}
		case 5:{
			randommang(A,n);
			xuat(A,n);
			QuickSort(A,0,n - 1);
			end = clock();
			t5 = end - start;
			xuat(A,n);
			break;
		}
		case 6:{
			printf("SelectionSort = %lf\n",t1);
			printf("InsertionSort = %lf\n",t2);
			printf("InterchangeSort = %lf\n",t3);
			printf("BubbleSort = %lf\n",t4);
			printf("QuickSort = %lf\n",t5);
			break;
		}
		case 7:{
			printf("-----The End-----\n");
			return 0;
			break;
		}
	}
	}while(chon < 8);
}
