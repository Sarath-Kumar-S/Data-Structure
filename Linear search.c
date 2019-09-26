#include<stdio.h>
#include<conio.h>
void main()
{       int a[10],i,n,key,flag=0;
        printf("Enter no. of elements in the array:");
        scanf("%d",&n);
        printf("Enter the elements:");
        for(i=0;i<n;i++)
        {    scanf("%d",&a[i]);
        }
        printf("Enter the key to be searched for:");
        scanf("%d",&key");
        for(i=0;i<n;i++)
        {    if(key==a[i])
             {      printf("Key found at position %d\n",i);
                    flag=1;
             }
        }
        if(flag==0)
        {      printf("Key not found \n);     
        }
        getch();
}
       
