#include<stdio.h>
#include<conio.h>
void push(int st[],int item, int *top){
	if(*top>20)
		printf("Overflow");
	else{
		*top+=1;
		st[*top]=item;
	}
}
int pop(int st[],int *top){
	if(*top>=0){
		int data=st[*top];
		*top=*top-1;
		return data;
	}
	else
		return -1;
}
void disp(int st[],int top){
	int i;
	printf("stack is\n __");
	for(i=top;i>=0;i--)
		printf("\n|%d|",st[i]);
	printf("\n __");
}
void main()
{
	int st[20],i,cho,top=-1,d,item;
	do{
		clrscr();
		printf("\n\t\t-----Stack Menu___ ");
		printf("\n\t\t\t1.Addition");
		printf("\n\t\t\t2.Deletion");
		printf("\n\t\t\t3.Display");
		printf("\n\t\t\t4.Exit");
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1: clrscr();
				printf("Enter the item to add: ");
			       scanf("%d",&item);
			       push(st,item,&top);
			       disp(st,top);
			       getch();
			       break;
			case 2: clrscr();
				d=pop(st,&top);
				if(d!=-1)
					printf("popped element is %d",d);
				else
					printf("\n underflow");
				printf("\n");
				disp(st,top);
				getch();
				break;
			case 3:
				clrscr();
				disp(st,top);
				getch();
				break;
			case 4:exit(0);
				break;
			}
	  }while(cho!=4);
}
