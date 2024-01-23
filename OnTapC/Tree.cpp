#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int data;
	Node *left,*right;
};

typedef struct Node* Tree;

void create_tree(Tree &r){
	r = NULL;
}

int insert_tree(Tree &T,int X){
	if (T) {
		if(T->data == X) return 0; 
		if(T->data > X)
			return insert_tree(T->left, X);
		else
			return insert_tree(T->right, X);
	}
	T = new Node;
	if (T == NULL) return -1; 
	T->data = X;
	T->left = T->right = NULL;
	return 1;
}

int remove_node1(Tree &T,int X){
	if(T == NULL)
		return 0;
	else if(T -> data > X) return remove_node1(T-> left,X);
	else if(T -> data < X) return remove_node1(T-> right,X);
	else{
		Node *p = T;
		if(T -> left == NULL){
			T = T-> right; return 1;
		}
		else if(T -> right == NULL){
			T = T-> left; return 1;
		}
		else{
			Node *s = p, *q = p-> left;
			if(q -> right != NULL){
				while(q -> right != NULL){
					s = q; q= q-> right;
				}
				p-> data = q-> data;s -> right = q -> left;
				delete q;
				return 1;		
			}
			else{
				p-> data = q->data;p -> left = q-> left;
				delete q;return 1;
			}
		}
	}
}

int remove_node2(Tree &T,int X){
	if(T == NULL)
		return 0;
	else if(T -> data > X) return remove_node2(T-> left,X);
	else if(T -> data < X) return remove_node2(T-> right,X);
	else{
		Node *p = T;
			Node *s = p, *q = p-> left;
			if(q -> right != NULL){
				while(q -> right != NULL){
					s = q; q= q-> right;
				}
				p-> data = q-> data;s -> right = q -> left;
				delete q;
				return 1;		
			}
			else{
				p-> data = q->data;p -> left = q-> left;
				delete q;return 1;
			}
		}
}

void LNR(Tree t)
{
	if (t != NULL)
	{
		LNR(t->left);
		printf("%d ",t -> data);
		LNR(t->right);
	}
}

void NLR(Tree t)
{
	if (t != NULL)
	{
		printf("%d ",t -> data);
		NLR(t->left);
		NLR(t->right);
	}
}

void LRN(Tree t)
{
	if (t != NULL)
	{
		LRN(t->left);
		LRN(t->right);
		printf("%d ",t -> data);
	}
}

int main(){
	Tree r;
	create_tree(r);
	insert_tree(r,67);
	insert_tree(r,23);
	insert_tree(r,12);
	insert_tree(r,90);
	insert_tree(r,56);
	insert_tree(r,100);
	insert_tree(r,33);
	insert_tree(r,98);
	insert_tree(r,45);
	insert_tree(r,78);
	insert_tree(r,20);
	
	remove_node2(r,56);

	NLR(r);
}

