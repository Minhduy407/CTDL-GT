#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef int DataType;

struct DNode{
    DataType data;
    DNode* pPrev; 
    DNode* pNext;
};

struct DList{
    DNode* pHead;
    DNode* pTail;
};

void Init(DList &DL){
    DL.pHead = DL.pTail = NULL;
}

DNode *GetNode(int x){
    DNode *p = new DNode;
    p -> data = x;
    p -> pPrev = NULL;
    p -> pNext = NULL;
    return p;
}

void add(DList &DL,DNode *tmp){
    if(DL.pTail == NULL){
        DL.pHead = DL.pTail = tmp;
    }
    tmp -> pPrev = DL.pTail;
    DL.pTail -> pNext = tmp;
    DL.pTail = tmp;                      
}

void them(DList &DL,int x){
    DNode *p = GetNode(x);
    add(DL,p);
}

void DListAppend (DList &DL,int Arr[],int n){
    for(int i = 0;i < n;i++){
        them(DL,Arr[i]);
    }
}

int RemoveTail(DList &DL){
    if(DL.pTail != NULL){
        DNode *p = DL.pTail;
        DL.pTail = DL.pTail -> pPrev; 
        DL.pTail -> pNext = NULL;
        p -> pPrev = NULL;
        delete(p);
        return 1;
    }
    return -1;
}

void DListShowTails(DList DL,int x){
    DNode *p = DL.pTail;
    while(p != DL.pHead){
        printf("%d ",p -> data);
        p = p-> pPrev;
    }
    printf("%d ",p -> data);
}

int main(){
	DList DL;
	Init(DL);
	int n = 5, h = 5;
	DataType Arr[] = {1, 2, 3, 4, 5};
	DListAppend(DL,Arr,n);
	int res = RemoveTail(DL);
	res = RemoveTail(DL);
	res = RemoveTail(DL);
	res = RemoveTail(DL);
	res = RemoveTail(DL);
	res = RemoveTail(DL);
	cout << res << endl;
	DListShowTails(DL,h);
}
