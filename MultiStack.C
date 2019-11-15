#include<stdio.h>
#include<conio.h>
void push1(int st[],int item, int *top1,int top2){
	if(*top1>=top2)
		printf("Overflow");
	else{
		*top1+=1;
		st[*top1]=item;
	}
}
void push2(int st[],int item, int *top2,int top1){
	if(*top2<=top1)
		printf("Overflow");
	else{
		*top2-=1;
		st[*top2]=item;
	}
}

int pop1(int st[],int *top1){
	if(*top1>=0){
		int data=st[*top1];
		*top1=*top1-1;
		return data;
	}
	else
		return -1;
}
int pop2(int st[],int *top2){
	if(*top2>=0){
		int data=st[*top2];
		*top2=*top2+1;
		return data;
	}
	else
		return -1;
}
void disp1(int st[],int top1){
	int i;
	printf("stack is\n __");
	for(i=top1;i>=0;i=i-1)
		printf("\n|%d|",st[i]);
	printf("\n __");
}
void disp2(int st[],int top2){
	int i;
	printf("stack is\n __");
	for(i=top2;i<20;i++)
		printf("\n|%d|",st[i]);
	printf("\n __");
}
void main()
{
	int st[20],cho,top1=-1,top2=20,d,item;
	do{
		clrscr();
		printf("\n\t\t-----Stack 1's Menu___ ");
		printf("\n\t\t\t1.Addition");
		printf("\n\t\t\t2.Deletion");
		printf("\n\t\t\t3.Display");
		printf("\n\n\t\t-----Stack 2's Menu___ ");
		printf("\n\t\t\t4.Addition");
		printf("\n\t\t\t5.Deletion");
		printf("\n\t\t\t6.Display");
		printf("\n\t\t\t7.Exit");
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1: clrscr();
				printf("Enter the item to add: ");
			       scanf("%d",&item);
			       push1(st,item,&top1,top2);
			       disp1(st,top1);
			       getch();
			       break;
			case 2: clrscr();
				d=pop1(st,&top1);
				if(d!=-1)
					printf("popped element is %d",d);
				else
					printf("\n underflow");
				printf("\n");
				disp1(st,top1);
				getch();
				break;
			case 3:
				clrscr();
				disp1(st,top1);
				getch();
				break;
			case 4: clrscr();
				printf("Enter the item to add: ");
			       scanf("%d",&item);
			       push2(st,item,&top2,top1);
			       disp2(st,top2);
			       getch();
			       break;
			case 5: clrscr();
				d=pop2(st,&top2);
				if(d!=-1)
					printf("popped element is %d",d);
				else
					printf("\n underflow");
				printf("\n");
				disp2(st,top2);
				getch();
				break;
			case 6:
				clrscr();
				disp2(st,top2);
				getch();
				break;
			case 7:exit(0);
				break;
			}
	  }while(cho!=7);
}
