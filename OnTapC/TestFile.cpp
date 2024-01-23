#include<stdio.h>
#include<string.h>

typedef struct WORD{
    char Name[256];
    char Meaning[512];
}WORD;

//void ReadData(char filename[],int n){
//	
//}

int main(){
	WORD W[100];
	int n = 0;
	FILE *fp = fopen("Test.txt","r+");
	char a[100];
	while(fgets(a,50,fp) && n < 100){
		char *w = strtok(a,",");
		if(w != NULL){
			strcpy(W[n].Name,w);
		}
		
		w = strtok(NULL,"\0");
		if(w != NULL){
		strcpy(W[n].Meaning,w);
		n++;
	}
	}
	printf("%s",W[5].Name);
	printf(" %s",W[5].Meaning);
	return 0;
}
