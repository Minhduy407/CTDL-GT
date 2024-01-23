#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SinhVien{
	int masv;
	char name[50];
};

struct Node{
	SinhVien data;
	Node *left;
	Node *right;
};

typedef struct Node* Tree;

void create_tree(Tree &t){
	t = NULL;
}

int insert_tree(Tree &T,SinhVien x){
	if(T){
		if(T -> data.masv == x.masv) return 0;
		if(T -> data.masv > x.masv) return insert_tree(T -> left,x);
		else return insert_tree(T -> right,x);
	}
	T = new Node;
	if(T == NULL) return -1;
	T -> data.masv = x.masv;
	strcpy(T -> data.name,x.name);
	T -> right = T -> left = NULL;
	return 1;
}

int remove_tree(Tree &T,int x){
	if(T == NULL) return 0;
	else if(T -> data.masv > x) return remove_tree(T -> left,x);
	else if(T -> data.masv < x) return remove_tree(T -> right,x);
	else{
		Node *p = T;
		if(T -> right == NULL){
			T = T -> left; return 1;
		}
		else if(T -> left == NULL){
			T = T -> right; return 1;
		}
		else{
			Node *s = p, *q = p -> left;
			if(q -> right != NULL){
				while(q -> right != NULL){
					s = q;q = q -> right;
				}
				p -> data = q -> data;s -> right = q -> left;
				delete q;
				return 1;
			}
		}
	}
}

void NLR(Tree T){
	if(T != NULL){
		printf("%d %s\n",T->data.masv,T->data.name);
		NLR(T->left);
		NLR(T->right);
	}
}

void nhapdsSV(Tree &T){
	SinhVien x;
	char chon;
	do{
		printf("Nhap ma sv: ");
		scanf("%d",&x.masv);
		getchar();
		printf("Nhap ten sv: ");
		fgets(x.name,50,stdin);
		x.name[strlen(x.name) - 1] = '\0';
		insert_tree(T,x);
		printf("Nhap tiep (y/n): ");
		scanf("%c",&chon);	
	}while(chon == 'y' || chon == 'Y');
}

void doc_file(char filename[],Tree &T){
	FILE *f = fopen(filename,"r");
	if(f == NULL){
		return;
	}
	SinhVien x;
	char string[50];
	while(fgets(string,sizeof(string),f)){
		string[strlen(string) - 1] = '\0';
		char *word = strtok(string,",");
		if(word != NULL)
			x.masv = atoi(word);	
		word = strtok(NULL,"");
		if(word != NULL)
			strcpy(x.name,word);
		insert_tree(T,x);
	}
	fclose(f);
}

int main(){
	Tree T;
	create_tree(T);
	char filename[50] = "tree.txt";
	doc_file(filename,T);
	remove_tree(T,342);
	NLR(T);
	return 0;
}
