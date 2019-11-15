#include<stdio.h>
#include<conio.h>
void enqueue(int arr[],int item, int *rear){
	if(*rear>20)
		printf("Overflow");
	else{
		*rear+=1;
		arr[*rear]=item;
	}
}
void dequeue(int arr[],int *rear){
	int i;
	if(*rear>-1){
		for(i=0;i<*rear;i++)
			arr[i]=arr[i+1];
		*rear-=1;
	}
	else
	      printf("Underflow!!");
}
void disp(int arr[],int rear){
	int i;
	printf("Queue is: \n\t|");
	for(i=0;i<=rear;i++)
		printf(" %d |",arr[i]);
}
void main()
{
	int arr[20],i,cho,rear=-1,item;
	do{
		clrscr();
		printf("\n\t\t-----Queue Menu___ ");
		printf("\n\t\t\t1.Enqueue");
		printf("\n\t\t\t2.Dequeue");
		printf("\n\t\t\t3.Display");
		printf("\n\t\t\t4.Exit");
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1: clrscr();
				printf("Enter the item to add: ");
			       scanf("%d",&item);
			       enqueue(arr,item,&rear);
			       disp(arr,rear);
			       getch();
			       break;
			case 2: clrscr();
				dequeue(arr,&rear);
				disp(arr,rear);
				getch();
				break;
			case 3:
				clrscr();
				disp(arr,rear);
				getch();
				break;
			case 4:exit(0);
			}
	  }while(cho!=4);
}
