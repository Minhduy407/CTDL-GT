#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *tmp = new char[100];
	tmp[0] = '1';
	tmp[1] = ' ';
	tmp[2] = '-';
	tmp[3] = ' ';
	tmp[4] = '2';
	tmp[5] = ' ';
	tmp[6] = '#';
	printf("%s",tmp);
	return 0;
}
