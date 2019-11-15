#include<stdio.h>
#include<conio.h>
void main()
{  int i=0,n=0;
   char str[20];
   clrscr();
   printf("Enter a string:");
   gets(str);
   while(str[i]!='\0')
   {  n++;
      i++;
   }
   printf("Reverse of the string is \n");
   for(i=n-1;i>=0;i--)
   {  printf(" %c",str[i]);   }
   printf("\n");
   getch();
}
