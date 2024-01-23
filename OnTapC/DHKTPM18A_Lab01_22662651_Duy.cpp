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

void OutputFile(char filename[],int A[],int &n){
	FILE *fp = fopen(filename,"rb");
	if(fp == NULL){
		printf("Can not open file");
		fclose(fp);
	}
	int i = 0;
	while(!feof(fp)){
		fscanf(fp,"%d",&A[i]);
		i++;
	}
	n = i - 1;
	fclose(fp);
}

void InputFile(char filename[],int A[],int n){
	FILE *fp = fopen(filename,"wb");
	if(fp == NULL){
		printf("Can not open file");
		fclose(fp);
	}
	for(int i = 0;i < n;i++){
		fprintf(fp,"%d\n",A[i]);
	}
	fclose(fp);
}

int LinearSearch(int A[],int n,int x){
	for(int i = 0;i < n;i++){
		if(x == A[i])
		return i;
	}
	return -1;
}

int main(){
	int A[max];
	int n;
	char name[50];
	printf("Nhap vao day ten file: ");fgets(name,50,stdin);
	name[strlen(name) - 1] = '\0';
	int chon;
	do{
		printf("MENU\n");
		printf("1.Nhap du lieu vao file\n");
		printf("2.Doc du lieu file va xuat ra\n");
		printf("3.Tim kiem phan tu trong mang\n");
		printf("4.Thoat\n");
		printf("Chon = ");
		scanf("%d",&chon);
		switch(chon){
			case 1:{
				nhap(A,n);
	            InputFile(name,A,n);
	            printf("\n");
				break;
			}
			case 2:{
				OutputFile(name,A,n);
	            xuat(A,n);
	            printf("\n");
				break;
			}
			case 3:{
				int x;
	            printf("Nhap vao phan tu can tim: ");scanf("%d",&x);
	            int k = LinearSearch(A,n,x);
	            if(k == -1)
            	printf("Khong tim thay phan tu x!!\n");
              	else{
             	    printf("Tim thay phan tu x o vi tri %d.\n",k);
             	}
				break;
	   		}
			case 4:{
				printf("Ket thuc chuong trinh\n");
				break;
			}
		}
	}while(chon != 4);
	return 0;
}
