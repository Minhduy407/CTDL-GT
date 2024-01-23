#include<stdio.h>
#include<string.h>
#define max 50

typedef struct{
    char ho[30];
    char ten[10];
    char mssv[10];
    char malop[10];
    float d1,d2,d3,dtb;
}SV;

void nhap(SV &A){
    printf("Nhap ho va ten lot: ");
    gets(A.ho);
    fflush(stdin);
    printf("Nhap ten: ");
    scanf("%s",&A.ten);
    fflush(stdin);
    printf("Nhap mssv: ");
    scanf("%s",&A.mssv);
    fflush(stdin);
    printf("Nhap ma lop: ");
    scanf("%s",&A.malop);
    fflush(stdin);
    printf("Nhap diem 1: ");
    scanf("%f",&A.d1);
    fflush(stdin);
    printf("Nhap diem 2: ");
    scanf("%f",&A.d2);
    fflush(stdin);
    printf("Nhap diem 3: ");
    scanf("%f",&A.d3);
}

void xuat(SV A){
    A.dtb = (A.d1 + A.d2 + A.d3)/3;
    printf("%-30s %-15s %-15s %-10s %5.2f %5.2f %5.2f %5.2f\n",A.ho,A.ten,A.mssv,A.malop,A.d1,A.d2,A.d3,A.dtb);
}

void outputSV(SV A[],int n){
    for(int i=0;i<n;i++){
        xuat(A[i]);
    }
}

void InputFile(char filename[50]){
    FILE *p = fopen(filename,"wb");
    if(p == NULL){
        printf("Error!");
        fclose(p);
    }
    char c;
    SV A;
    do{
    	getchar();
        nhap(A);
        fwrite(&A,sizeof(SV),1,p);
        fflush(stdin);
        printf("Tiep tuc (y/n): ");
        scanf("%c",&c);
    }while(c == 'y' || c == 'Y');
    fclose(p);
}

void OutputFile(char filename[50],SV A[],int &n){
    FILE *p = fopen(filename,"rb");
    if(p == NULL){
        printf("Error!");
        fclose(p);
    }
    n = 0;
    while(fread(&A[n],sizeof(SV),1,p) != 0){
        n++;
    }
    fclose(p);
}
