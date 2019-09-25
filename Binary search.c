#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],n,i,j,key,ll=0,ul,mid,n,temp,flag=0;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ul=n-1;
    printf("Enter the key to be searched for:");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {     if(a[i]>a[j])
              {   temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
              }
        }
    }
    while(ll<=ul)
    {   mid=(ll+ul)/2;
        if(key==a[mid])
        {   printf("Key found at position %d \n",mid);
            flag=1;  }
        else if(key<a[mid])
        {   ul=mid-1;  }
        else
        {  ll=mid-1;   }
    }
    if(flag==0)
    {
        printf("Key not found \n");
    }  
    getch();
}
