#include<stdio.h>
#include<string.h>

typedef struct WORD
{
	char Name[256];
	char Meaning[512];
}WORD;

WORD c(WORD tudien[],char x[],int l,int r){
	int m = (l + r) / 2;
	if(l > r) return -1;
	if(strcmp(tudien[m].Name,x) == 0) return tudien[m];
	if(strcmp(tudien[m].Name,x) < 0) return tratudien(tudien,x,l,m - 1);
	if(strcmp(tudien[m].Name,x) > 0) return tratudien(tudien,x,m + 1,r);
}

void DocFile(char filename[],WORD tudien[],int &n){
	FILE *fp = fopen(filename,"rb");
	if(fp == NULL){
		printf("Loi mo file!!!");
		fclose(fp);
		break;
	}
	n = 0;
	while(fread(&tudien[n].Name,sizeof(WORD),1,fp) != NULL){
		n++;
	}
}

int main(){
	WORD tudien[],int n;
	char chon;
	DocFile("FileTuDien.txt",tudien,n);
	char x[50];
	do{
		printf("Nhap vao day tu can tra: ");
	    fgets(&x,50,stdin);
	    x[strlen(x) - 1] = '\0';
	    WORD a = tratudien(tudien,x,0,n - 1);
	    if(a.Name == NULL) 
		    printf("Khong tim thay tu can tra!!! Vui long thu lai!!!");
	    else 
	        printf("%s : %s\n",a.Name,a.Meaning);
	    printf("Tiep tuc (y/n): ");scanf("%c",&chon);    
	}while(chon)
	return 0;
}
