#include<stdio.h>
#include<conio.h>
void main()
{       int a[10],i,j,temp,n;
	clrscr();
        printf("\n\nEnter limit: ");
	scanf("%d",&n);
	printf("\nEnter array:\n");
        for(i=0;i<n;i++)
	{	printf("\t");
		scanf("%d",&a[i]);
	}
        for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
         	{      	if(a[j]>a[j+1])
		        { 	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	printf("\nSorted Array:");
	for(i=0;i<n;i++)
	{	printf("\n\t    %d",a[i]);
	}
        getch();
}
