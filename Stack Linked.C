#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
}*header;
void print();
void push(int data1);
void pop();

void initialize()
{
	header=(struct Node*)malloc(sizeof(struct Node));
	header->link=NULL;
	header->data=0;
}
void main()
{
	int i,n,cho,key;
	clrscr();
	initialize();
	do{
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1: printf("Enter the no to add: ");
				scanf("%d",&n);
				push(n);
				print();
				break;
			case 2: clrscr();
				pop();
				print();
				break;
			case 3:clrscr();
				print();
				break;
			case 4:exit(0);
		}

	}while(cho!=4);
	getch();
}

void print()
{
	struct Node* ptr;
	ptr=header->link;
	printf("stack is\n __");
	while(ptr!=NULL)
	{
		printf("\n|%d|",ptr->data);
		ptr=ptr->link;
	}
	printf("\n __");
}
void push(int data1)
{
	struct Node *ptr,*temp;
	ptr=header;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\nUnderflow!!");
		exit(0);
	}
	else{
		temp->data=data1;
		temp->link=header->link;
		ptr->link=temp;
	}
}
void pop(){
		struct Node *ptr;
		ptr=header->link;
		if(ptr==NULL)
		{
			printf("Underflow!!");
			return;
		}
		header->link=ptr->link;
		free(ptr);
}
