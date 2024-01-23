#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct NGAY{
	int ngay,thang,nam;
};

typedef struct SinhVien{
	char MaLop[10];
	char MaSV[10];
	char TenSV[255];
	NGAY NgaySinh;
	double GPA;
}SV;

struct TNode{
	SV data;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

struct Node{
	char malop[10];
	Tree data;
	Node *next;
	Node *prev;
};

struct List{
	Node *first;
	Node *last;
};

void InitDSLK(List &L){
	L.first = L.last = NULL;
}

void Insert_Last(List &L,char ma[]){
	if(L.last == NULL){
		Node* tmp = new Node;
		if(tmp == NULL) return;
		tmp -> next = NULL;
		tmp -> prev = NULL;
		strcpy(tmp->malop,ma);
		tmp -> data = NULL;
		L.first = tmp;
		return;
	}
	Node* tmp = new Node;
	if(tmp == NULL) return;
	tmp -> next = NULL;
	tmp -> prev = L.last;
	strcpy(tmp->malop,ma);
	tmp -> data = NULL;
	L.last -> next = tmp;
	L.last = tmp;
	return;
}

void TaoDSLK(List &L){
	int chon;
	char lop[10];
	do{
		printf("Nhap ma lop: ");
		scanf("%s",&lop);
		Insert_Last(L,lop);
		printf("Nhap tiep lop: (1: Tiep tuc/ 0: Dung lai) ---> ");
		scanf("%d",&chon);
		getchar();
	}while(chon != 0);
	return;
}

int ThemSVvaoLop(Tree &T,SV x){
	if(T != NULL){
		if(strcmp(T->data.MaSV,x.MaSV) < 0) 
		return ThemSVvaoLop(T -> right,x);
		if(strcmp(T->data.MaSV,x.MaSV) > 0)
		return ThemSVvaoLop(T->left,x);
		else
			return 0;
	}
	T = new TNode;
	T -> data = x;
	T -> left = T -> right = NULL;
	return 1;
}

void ThemSV(List &L,SV x){
	Node *tmp = L.first;
	while(tmp != NULL){
		if(strcmp(tmp->malop,x.MaLop) == 0){
			int i = ThemSVvaoLop(tmp->data,x);
			return;
		}
		tmp = tmp -> next;
	}
	Insert_Last(L,x.MaLop);
	ThemSV(L,x);
	return;
}

void ThemDSSV(List &L){
	int chon;
	SV x;
	do{
		printf("\nNhap ma lop: ");
		scanf("%s",&x.MaLop);
		getchar();
		printf("\nNhap ma sv: ");
		gets(x.MaSV);
		printf("\nNhap ten sv: ");
		fgets(x.TenSV,255,stdin);
		x.TenSV[strlen(x.TenSV) - 1] = '\0';
		printf("\nNhap ngay thang nam sinh:");
		scanf("%d%d%d",&x.NgaySinh.ngay,&x.NgaySinh.thang,&x.NgaySinh.nam);
		printf("\nNhap diem GPA: ");
		scanf("%lf",&x.GPA);
		ThemSV(L,x);
		printf("\nNhap tiep: (1: Tiep tuc/ 0: Dung lai) ---> ");
		scanf("%d",&chon);
		getchar();
	}while(chon != 0);
}

void inSV(Tree T){
	if(T != NULL){
		printf("\n%-10s%-10s%-20s%10d/%d/%d%5.1lf",T->data.MaLop,T->data.MaSV,T->data.TenSV,T->data.NgaySinh.ngay,
		T->data.NgaySinh.thang,T->data.NgaySinh.nam,T->data.GPA);
		inSV(T -> left);
		inSV(T -> right);
	}
}

void inDSSV(List L,char malop[]){
	Node *tmp = L.first;
	while(tmp != NULL){
		if(strcmp(tmp->malop,malop) == 0){
			printf("\n\t\t====THONG TIN SINH VIEN CUA LOP %s====",malop);
			inSV(tmp->data);
			return;
		}
		tmp = tmp -> next;
	}
	return;
}

int main(){
	List DH;
	InitDSLK(DH);
	TaoDSLK(DH);
	ThemDSSV(DH);
	char malop[10];
	printf("\nNhap ma lop can in danh sach sinh vien: ");
	scanf("%s",&malop);
	inDSSV(DH,malop);
	fflush(stdin);
	return 0;
}
