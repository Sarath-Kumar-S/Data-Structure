#include<stdio.h>
#include<conio.h>
void main()
{
  int a[10],i,j,temp,n;
  clrscr();
  printf("\n\nEnter limit: ");
  scanf("%d",&n);
  printf("\nEnter array:\n");
  for(i=0;i<n;i++)
  { printf("\t");
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {  for(j=i+1;j<n;j++)
     {  if(a[i]>a[j])
        {  temp=a[i];
           a[i]=a[j];
           a[j]=temp;
        } 
     }
  }
  printf("\nSORTED ARRAY:");
  for(i=0;i<n;i++)
  {  printf("\n%d",a[i]);
  }
  getch();

}
