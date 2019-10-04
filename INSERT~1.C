#include<stdio.h>
#include<conio.h>
void main()
{ int arr[10],i,j,k,n;
  clrscr();
  printf("Enter array size:");
  scanf("%d",&n);
  printf("Enter elements:");
  for(i=0;i<n;i++)
  {  scanf("%d",&arr[i]);
  }
  for(i=1;i<n;i++)
  {  k=arr[i];
     j=i-1;
     while(j>=0 && arr[j]>k)
     {  arr[j+1]=arr[j];
        j=j-1;
     }
	arr[j+1]=k;
  } 
     printf("Sorted array: \n");
     for(i=0;i<n;i++)
     {  printf("%d\n",arr[i]);
     }
     getch();
}
