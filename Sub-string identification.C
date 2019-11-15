#include<stdio.h>
#include<conio.h>

void main()
{
	char str[100],a[10];
	int i=0,j=0,flag=0;
	clrscr();
	printf("Enter the string: ");
	gets(str);
	printf("Enter the string to search: ");
	gets(a);
	while(str[i]!='\0')
	{
		if(str[i]==a[0])
		{
			for(j=0;a[j]!='\0';j++)
			{
				if(a[j]!=str[i+j])
					break;

			}
			if(j>=strlen(a))
			{
				printf("substring found at index %d \n",i+1);
				flag=1;
			}
		}
		i++;
	}
	if(flag==0)
		printf("Substring not found");
	getch();
}
