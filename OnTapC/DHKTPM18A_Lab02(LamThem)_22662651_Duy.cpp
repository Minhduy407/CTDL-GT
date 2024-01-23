#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50

typedef struct SINHVIEN{
	char MSSV[10];
	char hovaten[50];
	char gioitinh[4];
	char diachi[100];
	float diemtrungbinh;
}SV;

void nhap(SV &a){
	printf("Nhap vao day ma so sinh vien: ");
	scanf("%s",&a.MSSV);
	fflush(stdin);
	printf("Nhap vao day ho va ten sinh vien: ");
	fgets(a.hovaten,50,stdin);
	a.hovaten[strlen(a.hovaten) - 1] = '\0';
	printf("Nhap gioi tinh sinh vien(Nam/Nu): ");
	scanf("%s",&a.gioitinh);
	fflush(stdin);
	printf("Nhap vao day dia chi cua sinh vien: ");
	fgets(a.diachi,100,stdin);
	fflush(stdin);
	printf("Nhap vao day diem trung binh cua sinh vien: ");
	scanf("%f",&a.diemtrungbinh);
	fflush(stdin);
}

void nhapds(SV a[],int &n){
	printf("Nhap vao day so sinh vien can nhap vao danh sach: ");
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		printf("Sinh vien %d\n",i + 1);
		nhap(a[i]);
		printf("\n");
	}
}

void xuat(SV a){
	printf("%-8s %-20s %-4s %5.1f %30s\n",a.MSSV,a.hovaten,a.gioitinh,a.diemtrungbinh,a.diachi);
}

void xuatds(SV a[],int n){
	char b[8] = "MSSV",c[20] = "Ho va Ten",d[10] = "GT",k[5] = "DTB",z[30] = "Dia Chi";
	printf("-----------------------THONG TIN DANH SACH SINH VIEN-----------------------\n");
	printf("%-8s %-20s %-4s %5s %20s\n",b,c,d,k,z);
	for(int i = 0;i < n;i++){
		xuat(a[i]);
	}
}

void timSV(SV a[],int n,char x[]){
	int tmp = 0;
	for(int i = 0;i < n;i++){
		if(strcmp(a[i].MSSV,x) == 0){
			tmp = 1;
			printf("Thong Tin Sinh Vien Can Tim Theo Ma %s\n",x);
			char b[8] = "MSSV",c[20] = "Ho va Ten",d[10] = "GT",k[5] = "DTB",z[30] = "Dia Chi";
			printf("%-8s %-20s %-4s %5s %20s\n",b,c,d,k,z);
			xuat(a[i]);
		}
	}
	if(tmp == 1){
		printf("Khong tim thay sinh vien co ma %s!!!!!!\n",x);
	}
}

void sapxep1(SV a[],int l,int r){
	int mid = (l + r) / 2;
	int i = l,j = r;
	while(i <= j){
		while(a[i].diemtrungbinh < a[mid].diemtrungbinh) i++;
		while(a[j].diemtrungbinh > a[mid].diemtrungbinh) j--;
		if(i <= j){
			SV tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++,j--;
		}
	}
	if(l < j) sapxep1(a,l,j);
	if(i < r) sapxep1(a,i,r);	
}

void sapxep2(SV a[],int l,int r){
	int mid = (l + r) / 2;
	int i = l,j = r;
	while(i <= j){
		while(strcmp(a[i].hovaten,a[mid].hovaten) < 0) i++;
		while(strcmp(a[j].hovaten,a[mid].hovaten) > 0) j--;
		if(i <= j){
			SV tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++,j--;
		}
	}
	if(l < j) sapxep2(a,l,j);
	if(i < r) sapxep2(a,i,r);	
}

int main(){
	SV a[max];
	int n;
	int chon;
	do{
		printf("------MENU------\n");
		printf("1. Nhap cac sinh vien vao danh sach\n");
		printf("2. In ra danh sach sinh vien\n");
		printf("3. Xuat thong tin cua sinh vien co ma X\n");
		printf("4. Sap xep sinh vien tang dan theo diem DTB\n");
		printf("5. Sap xep sinh vien tang dan theo ho va ten\n");
		printf("6. Thoat\n");
		printf("Chon: ");
		scanf("%d",&chon);
		fflush(stdin);
		switch(chon){
			case 1:{
				nhapds(a,n);
				break;
			}
			case 2:{
				xuatds(a,n);
				break;
			}
			case 3:{
				char x[10];
				printf("Nhap vao ma sinh vien can tim thong tin: ");
				scanf("%s",&x);
				timSV(a,n,x);
				break;
			}
			case 4:{
				sapxep1(a,0,n - 1);
				break;
			}
			case 5:{
				sapxep2(a,0,n - 1);
				break;
			}
			case 6:{
				printf("Ket thuc chuong trinh!!!!\n");
				return 0;
			}
		}
	}while(chon < 7);
}
