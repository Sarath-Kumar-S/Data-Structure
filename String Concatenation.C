#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	int n1,n2,n,i;
	char str1[10],str2[10],str[20]="";
	clrscr();
	printf("Enter the 1st string: ");
	gets(str1);
	n1=strlen(str1);
	printf("Enter the 2nd string: ");
	gets(str2);
	n2=strlen(str2);
	n=(n1+n2);
	for(i=0;i<n1;i++)
		str[i]=str1[i];
	for(i=n1;i<n;i++)
		str[i]=str2[i-n1];
	printf("Concatinated string: ");
	puts(str);
	getch();
}
