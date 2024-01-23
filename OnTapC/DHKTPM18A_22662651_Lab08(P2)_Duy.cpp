#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SinhVien {
	char masv[20];
	char name[20];
	double diem;
};

struct Node {
	SinhVien data;
	Node *left;
	Node *right;
};

typedef struct Node* Tree;

void create_tree(Tree &t) {
	t = NULL;
}

int insert_tree(Tree &T,SinhVien x) {
	if(T) {
		if(strcmp(T -> data.masv,x.masv) == 0) return 0;
		if(strcmp(T -> data.masv,x.masv) > 0) return insert_tree(T -> left,x);
		else return insert_tree(T -> right,x);
	}
	T = new Node;
	if(T == NULL) return -1;
	strcpy(T -> data.masv,x.masv);
	strcpy(T -> data.name,x.name);
	T->data.diem = x.diem;
	T -> right = NULL;
	T -> left = NULL;
	return 1;
}

int remove_tree(Tree &T,char x[]) {
	if(T == NULL) return 0;
	else if(strcmp(T -> data.masv,x) > 0) return remove_tree(T -> left,x);
	else if(strcmp(T -> data.masv,x) < 0) return remove_tree(T -> right,x);
	else {
		Node *p = T;
		if(T -> right == NULL) {
			T = T -> left;
			return 1;
		} else if(T -> left == NULL) {
			T = T -> right;
			return 1;
		} else {
			Node *s = p, *q = p -> left;
			if(q -> right != NULL) {
				while(q -> right != NULL) {
					s = q;
					q = q -> right;
				}
				p -> data = q -> data;
				s -> right = q -> left;
				delete q;
				return 1;
			}
		}
	}
}

void LNR(Tree T) {
	if(T != NULL) {
		LNR(T->left);
		printf("%s %s %lf\n",T->data.masv,T->data.name,T->data.diem);
		LNR(T->right);
	}
}

Node *timsv(Tree T,char x[]){
	if(T) {
		if(strcmp(T -> data.masv,x) == 0) return T;
		if(strcmp(T -> data.masv,x) > 0) return timsv(T -> left,x);
		else return timsv(T -> right,x);
	}
	return T;
}

void nhapdsSV(Tree &T) {
	SinhVien x;
	char chon;
	Node *tmp;
	do {
		do{
			printf("Nhap ma sv: ");
			scanf("%s",&x.masv);
			tmp = timsv(T,x.masv);
			if(tmp != NULL)
				printf("\nDa ton tai sinh vien co ma nay vui long nhap lai!\n");
		}while(tmp != NULL);
		getchar();
		printf("Nhap ten sv: ");
		fgets(x.name,50,stdin);
		x.name[strlen(x.name) - 1] = '\0';
		printf("Nhap diem sv: ");
		scanf("%lf",&x.diem);
		insert_tree(T,x);
		getchar();
		printf("Nhap tiep (y/n): ");
		scanf("%c",&chon);
	} while(chon == 'y' || chon == 'Y');
}

int demsonutla(Tree T) {
	if(T == NULL) return 0;
	if(T -> left == NULL && T -> right == NULL) return 1;
	return demsonutla(T -> right) + demsonutla(T -> left);
}

int tinhchieucaocay(Tree T) {
	if(T == NULL) return 0;
	if(T -> left == NULL && T -> right == NULL) return 1;
	int a = tinhchieucaocay(T -> left);
	int b = tinhchieucaocay(T -> right);
	if(a > b) return 1 + a;
	return 1 + b;
}

void tree_array(Tree T,SinhVien X[],int &i){
	if(T != NULL) {
		tree_array(T->left,X,i);
		X[i++] = T->data;
		tree_array(T->right,X,i);
	}
}

void quicksort(SinhVien X[],int left,int right){
	int l = left,r = right;
	SinhVien mid = X[(l + r) / 2];
	while(l <= r){
		while(strcmp(X[l].masv,mid.masv) < 0) l++;
		while(strcmp(X[r].masv,mid.masv) > 0) r--;
		if(l <= r){
			SinhVien tmp = X[l];
			X[l] = X[r];
			X[r] = tmp;
			r--;
			l++;
		}
	}
	if(l < right) quicksort(X,l,right);
	if(r > left) quicksort(X,left,r);
}

void newTree(Tree &T,SinhVien X[],int left,int right){
	if(left <= right){
		int mid = (left + right) / 2;
		T = new Node;
		T->data = X[mid];
		T -> right = NULL;
		T -> left = NULL;
		newTree(T->left,X,left,mid - 1);
		newTree(T->right,X,mid + 1,right);
	}
}


int main() {
	Tree T;
	create_tree(T);
	int chon;
	do {
		printf("\n\t\t\t====MENU=====");
		printf("\n1. Nhap du lieu sinh vien");
		printf("\n2. Duyet va xuat du lieu sinh vien");
		printf("\n3. Sap xep cay theo truong du lieu");
		printf("\n4. Dem so nut la cua cay sinh vien");
		printf("\n5. Tinh chieu cao cua cay sinh vien");
		printf("\n6. Chen 1 node sinh vien vao cay");
		printf("\n7. Tim kiem 1 node sinh vien");
		printf("\n8. Xoa mot node sinh vien");
		printf("\n0. Thoat");
		printf("\nChon --> ");
		scanf("%d",&chon);
		switch(chon){
			case 1:{
				printf("\n\t\t==NHAP DANH SACH SINH VIEN===\n");
				nhapdsSV(T);
				break;
			}
			case 2:{
				printf("\n\t\t===DANH SACH SINH VIEN===\n");
				LNR(T);
				break;
			}
			case 3:{
				SinhVien X[100];
				int i = 0;
				printf("\n\t\t==DANH SACH SINH VIEN DUOC SAP XEP THEO TRUONG DU LIEU===\n");
				tree_array(T,X,i);
				quicksort(X,0,i - 1);
				newTree(T,X,0,i - 1);
				LNR(T);
				break;
			}
			case 4:{
				printf("\n\t\t===SO NUT LA CUA CAY===\nSo nut la: %d",demsonutla(T));
				break;
			}
			case 5:{
				printf("\n\t\t===CHIEU CAO CUA CAY===\nChieu cao cua cay: %d",tinhchieucaocay(T));
				break;
			}
			case 6:{
				printf("\n\t\t===CHEN 1 SINH VIEN VAO===\n");
				SinhVien x;
				Node *tmp;
				do{
					printf("Nhap ma sv: ");
					scanf("%s",&x.masv);
					tmp = timsv(T,x.masv);
					getchar();
					if(tmp != NULL)
						printf("\nDa ton tai sinh vien co ma nay vui long nhap lai!\n");
				}while(tmp != NULL);
				printf("Nhap ten sv: ");
				fgets(x.name,50,stdin);
				x.name[strlen(x.name) - 1] = '\0';
				printf("Nhap diem sv: ");
				scanf("%lf",&x.diem);
				insert_tree(T,x);
				break;
			}
			case 7:{
				char x[20];
				printf("\n\t\t===TIM KIEM SINH VIEN===\n");
				printf("Nhap ma sv: ");
				scanf("%s",&x);
				Node *tmp = timsv(T,x);
				if(tmp == NULL)
					printf("\nKhong tim thay sinh vien can tim!!");
				else{
					printf("\nDa tim thay sinh vien can tim!!");
					int chon = 0;
					printf("\nBan co muon xem thong tin cua sinh vien nay(1:co | 0:khong) -> ");
					scanf("%d",&chon);
					if(chon){
						printf("\n\t\t===THONG TIN CUA SINH VIEN===\n");
						printf("%s %s %lf\n",tmp->data.masv,tmp->data.name,tmp->data.diem);
					}
				}
				break;
			}
			case 8:{
				char x[20];
				printf("\n\t\t\t===XOA SINH VIEN===\n");
				printf("Nhap ma sv: ");
				scanf("%s",&x);
				int i = remove_tree(T,x);
				if(i)
					printf("\nDa xoa sinh vien thanh cong!");
				else
					printf("\nKhong tim duoc sinh vien can xoa!");
				break;
			}
		}
	} while(chon != 0);
	printf("\n\t\t====KET THUC CHUONG TRINH====\n");
	return 0;
}
