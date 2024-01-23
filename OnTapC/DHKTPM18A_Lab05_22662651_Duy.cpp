#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Ngay{
	int ngay,thang,nam;
};

typedef struct SinhVien{
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaysinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
}SV;

struct Node{
	SV data;
	Node* link;
};

struct List{
	Node* first;
	Node* last;
};
//Tao DSLK
void Init(List&L){
	L.first = L.last = NULL;
}
//Tao Node
Node *getNode(SV data){
	Node* new_node = new Node;
	if(new_node == NULL) return NULL;
	new_node -> data = data;
	new_node -> link = NULL;
	return new_node;
}
//Them cuoi
void addLast(List &L,Node *new_ele){
	if(L.last == NULL)
		L.first = L.last = new_ele;
	else{
		L.last -> link = new_ele;
		L.last = new_ele; 
	}
}

void InsertLast(List &L,SV x){
	Node* p = getNode(x);
	if(p == NULL) return;
	addLast(L,p);
}

//them dau
void AddFirst(List &l,Node* new_ele){
	if(l.first == NULL){
		l.first = new_ele;
		l.last = l.first;
	}
	else{
		new_ele->link = l.first;
		l.first = new_ele;
	}
}
void InsertFirst(List &l,SV x){
	Node* new_ele = getNode(x);
	if(new_ele == NULL)
	return;
	AddFirst(l,new_ele);
}

/* Hàm nhap mot sinh viên. Nhap thành công tra ve 1, 
nhap không thành công (MASV = 0) thì tra ve 0 */

int NhapSinhVien(SV &x){
	printf("Ma so sinh vien: ");
	scanf("%s",&x.maSV);
	if(strcmp(x.maSV,"0") == 0)
		return 0;
	fflush(stdin);
	printf("Nhap ho va ten: ");
	gets(x.hoTen);
	fflush(stdin);
	//Nam = 0,Nu = 1;
	printf("Nhap vao gioi tinh(Nam = 0/Nu = 1): ");
	scanf("%d",&x.gioiTinh);
	printf("Nhap vao ngay thang nam sinh: ");
	scanf("%d %d %d",&x.ngaysinh.ngay,&x.ngaysinh.thang, &x.ngaysinh.nam);
 	fflush(stdin);
 	printf("Nhap vao dia chi: ");
 	gets(x.diaChi);
 	fflush(stdin);
 	printf("Nhap vao day lop: ");
 	scanf("%s",&x.lop);
 	fflush(stdin);
 	printf("Nhap vao day khoa: ");
 	scanf("%s",&x.khoa);
 	fflush(stdin);
 	return 1;
}
//Them khong trung
int InsertFirst_KhongTrung(List& L,SV x){
	Node* p = L.first;
	while(p != NULL && strcmp(p->data.maSV,x.maSV) != 0){
		p = p -> link;
	}
	if(p !=  NULL){
		printf("Da ton tai sinh vien co ma nay!!");
		return 0;
	}
	else{
		InsertLast(L,x);
		return 1;
	}
}
//Nhap danh sach sinh vien
void NhapDSSV_KhongTrung1(List &L){
	printf("\nBat dau nhap danh sach SV. Nhap maSV = 0 de dung\n");
	SV x;
	int flag = NhapSinhVien(x);
	while(flag){
		InsertFirst_KhongTrung(L,x);
		flag = NhapSinhVien(x);
	}
	printf("\n Ket thuc nhap danh sach SV!!");
}
void NhapDSSV(List &L){
	printf("\nBat dau nhap danh sach SV. Nhap maSV = 0 de dung\n");
	SV x;
	int flag = NhapSinhVien(x);
	while(flag != 0){
		InsertFirst(L,x);
		flag = NhapSinhVien(x);
	}
	printf("\n Ket thuc nhap danh sach SV!!");
}
//in ra danh sach sinh vien
void inSinhVien(SV s){
	char gt[4];
	if(s.gioiTinh == 0)
		strcpy(gt,"Nam");
	else
		strcpy(gt,"Nu");
	printf("\n%-10s %-20s %5d/%d/%d %5s %40s %8s %8s"
	, s.maSV, s.hoTen, s.ngaysinh.ngay, 
 s.ngaysinh.thang, s.ngaysinh.nam, gt, 
 s.diaChi, s.khoa, s.lop);
}

void XuatSinhVien(List L){
	Node* p = L.first;
	while(p != NULL){
		inSinhVien(p -> data);
		p = p -> link;
	}
}
//Xoa sinh vien dau danh sach
void RemoveFirst(List &L){
	Node*p = L.first;
	L.first = p->link;
	p->link = NULL;
	delete(p);
}
//Tim sinh vien de xoa
Node* TimXoa(List L,char x[]){
	Node *p = L.first;
	while(p != NULL && strcmp(p->link->data.maSV,x) != 0){
		p = p-> link;
	}
	if (p != L.last)
		return p;
	return NULL;  
}
//Xoa sinh vien sau 1 sinh vien
void RemoveAfter(List &L, Node *tmp){
	if(tmp = L.first) {
		RemoveFirst(L);
		return;
	}

	Node * p = tmp -> link;
	tmp -> link = p -> link;
	p -> link = NULL;
	delete(p); 
}

//Sap xep sinh vien InterchangeSort
void InterchangeSort(List &L){
	for(Node*i = L.first;i != L.last;i = i->link){
		for(Node* j = i;j != NULL;j = j->link){
			if(strcmp(i -> data.hoTen , j -> data.hoTen) > 0){
				SV tmp = i -> data;
				i -> data = j -> data;
				j -> data = tmp;
			}
		}
	}
}
//noi 2 danh sach lien ket
void SListAppend(List &l, List &l2)
{
	if (l2.first == NULL) return;
	if (l.first == NULL) 
		l = l2;
	else {
		l.last->link = l2.first;
		l.last = l2.last;
	} 
	Init(l2);
}
//quicksort
void SListQSort(List &l) {
	Node *X, *p;
	List l1, l2;
	if (l.first == l.last) return;
		Init(l1); Init(l2);
		X = l.first; l.first= l.first -> link;
		X -> link= NULL;
	while(l.first != NULL){
		p = l.first;
		l.first= l.first -> link;
		p -> link = NULL;
		if (strcmp(p->data.hoTen , X->data.hoTen) < 0)InsertFirst(l1, p->data);
		else InsertFirst(l2, p->data);
	}
	SListQSort(l1); 
	SListQSort(l2);
	if(l1.first != NULL){
		l.first = l1.first;
		l1.last->link = X;
	}
	else{
		l.first = X;
		X -> link = l2.first;
	}
	if(l2.first != NULL){
		l.last = l2.last;
	}	
	else l.last = X;
}
//Tim de them sinh vien vao danh sach
Node* Timthem(List L,char x[]){
	Node *p = L.first;
	while(p != NULL && strcmp(p->link->data.maSV,x) < 0){
		p = p-> link;
	}
	if (p != L.last)
		return p;  
}
//Them sau sinh vien x
void addAfter(List &L,Node* tmp,SV x){
	if(tmp == L.first)
		InsertFirst(L,x);
	else{
		Node*p = getNode(x);
		p -> link = tmp -> link;
		tmp -> link = p;
	}
}
//Them co thu tu
void ThemCoThuTu(List &L,SV x){
	if(strcmp(x.maSV,L.first->data.maSV) < 0) 
		InsertFirst(L,x);
	else{
		Node*tmp = Timthem(L,x.maSV);
		addAfter(L,tmp,x);
	}
}
//Them co thu tu khong trung
void ThemCoThuTu_KhongTrungMa(List &L,SV x){
	if(strcmp(x.maSV,L.first->data.maSV) == 0){
		printf("Da ton tai sinh vien co ma nay!!");
		return;
	}
	if(strcmp(x.maSV,L.first->data.maSV) < 0) 
		InsertFirst(L,x);
	else{
		Node*tmp = Timthem(L,x.maSV);
		if(strcmp(x.maSV,tmp->link ->data.maSV) == 0)
		{
			printf("Da ton tai sinh vien co ma nay!!");
			return;
		}
		addAfter(L,tmp,x);
	}
}
//Them sinh vien vao danh sach theo thu tu
void NhapDSSV_theothutu(List &L){
	printf("\nBat dau nhap danh sach SV. Nhap maSV = 0 de dung\n");
	SV x;
	int flag = NhapSinhVien(x);
	while(flag){
		ThemCoThuTu(L,x);
		flag = NhapSinhVien(x);
	}
	printf("\n Ket thuc nhap danh sach SV!!");
}
void NhapDSSV_theothutu_khongtrungma(List &L){
	printf("\nBat dau nhap danh sach SV. Nhap maSV = 0 de dung\n");
	SV x;
	int flag = NhapSinhVien(x);
	while(flag){
		ThemCoThuTu_KhongTrungMa(L,x);
		flag = NhapSinhVien(x);
	}
	printf("\n Ket thuc nhap danh sach SV!!");
}


int main(){
	List L;
	Init(L);
	NhapDSSV_theothutu(L);
	SListQSort(L);
	char x[50];
	printf("Nhap vao day ma sinh vien can xoa");
	Node*p = TimXoa(L,x);
	if(p != NULL)
		RemoveAfter(L,p);
	else
		printf("Khong tim thay nhan vien can xoa!!");
	XuatSinhVien(L);
	return 0;
}
