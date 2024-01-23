#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 1000

int A[max];

void InterchangeSort(int A[],int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(A[i] > A[j]){
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}

void BubbleSort(int A[],int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = n - 1;j > i;j--){
			if(A[j] < A[j - 1]){
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
		}
	}
}

void InsertionSort(int A[],int n){
	int pos,x;
	for(int i = 1;i < n;i++){
		x = A[i];
		pos = i - 1;
		while(pos >= 0 && A[pos] > x){
			A[pos + 1] = A[pos];
			pos--;
		}
		A[pos + 1] = x;
	}
}

void SelectionSort(int A[],int n){
	int min;
	for(int i = 0;i < n - 1;i++){
		min = i;
		for(int j = i + 1;j < n;j++){
			if(A[min] > A[j])
				min = j;
		}
		if(min != i){
			int tmp = A[i];
			A[i] = A[min];
			A[min] = tmp;	
		}
	}	
}

void QuickSort(int A[],int left,int right){
	int i,j,x;
	x = A[(left + right) / 2];
	i = left;
	j = right;
	do{
		while(A[i] < x) i++;
		while(A[j] > x) j--;
		if(i <= j){
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}while(i <= j);
	if(left < j) QuickSort(A,left,j);
	if(i < right) QuickSort(A,i,right);
}
