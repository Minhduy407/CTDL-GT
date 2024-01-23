#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct SinhVien{
	char maSV[8];
	char hoTen[50];
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


void ghifile(char name[]){
	FILE *f = fopen(name,"w");
	if(f == NULL){
		printf("Loi mo file!");
		return;
	}
	else{
		printf("\nBat dau nhap danh sach SV. Nhap 0 de dung\n");
		char line[500];
		int flag = 1;
		while(flag){
			fflush(stdin);
			fgets(line,500,stdin);
//			line[strlen(line) - 1] = '\0';
			fwrite(&line,sizeof(line),1,f);
			printf("Nhap 1 de tiep tuc 0 de dung:\n");
			scanf("%d",&flag);
		}
		printf("\n Ket thuc nhap danh sach SV!!");
	}
	fclose(f);
	return;
}

void docfile(char name[],List &L){
	FILE *f = fopen(name,"r");
	if(f == NULL){
		printf("Loi mo file!");
		return;
	}
	else{
		SV x;
		char line[500];
		while(fread(&line,sizeof(line),1,f)){
			line[strlen(line) - 1] = '\0';
			char *w = strtok(line,",");
			if(w != NULL){
				strcpy(x.maSV,w);
			}
			w = strtok(NULL,",");
			if(w != NULL){
				strcpy(x.hoTen,w);
			}
			w = strtok(NULL,",");
			if(w != NULL){
				strcpy(x.lop,w);
			}
			w = strtok(NULL,"");
			if(w != NULL){
				strcpy(x.khoa,w);
			}
			InsertLast(L,x);
		}
	}
	fclose(f);
	return;
}

void inSinhVien(SV s){
	printf("\n%-10s %-20s %8s %8s"
	, s.maSV, s.hoTen,s.khoa, s.lop);
}

void XuatSinhVien(List L){
	Node* p = L.first;
	while(p != NULL){
		inSinhVien(p -> data);
		p = p -> link;
	}
}
int main(){
	List L;
	Init(L);
	char name[50] = "filedslk.txt";
//	ghifile(name);
	docfile(name,L);
	XuatSinhVien(L);
	return 0;
}
