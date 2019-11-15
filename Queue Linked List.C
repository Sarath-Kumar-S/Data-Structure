#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* link;
}*header;
void print();
void Enqueue(int data);
void Dequeue();
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
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter ur choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1:	printf("Enter the no to add: ");
				scanf("%d",&n);
				clrscr();
				Enqueue(n);
				print();
				break;
			case 2: clrscr();
				Dequeue();
				print();
				break;
			case 3: print();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice!!");
			}
	}while(cho!=7);
	getch();
}
void creatlist(int num)
{
	struct Node *ptr,*temp;
	ptr=header;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=num;
	temp->link=NULL;
	ptr->link=temp;
}

void print()
{
	struct Node* ptr;
	ptr=header->link;
	printf("Queue is: ");
	while(ptr!=NULL)
	{
		printf("  %d",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}
void Enqueue(int data){
	struct Node *ptr,*temp;
	ptr=header;
	temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("\nUnderflow!!");
		exit(0);
	}
	else{
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		temp->data=data;
		temp->link=NULL;
		ptr->link=temp;
	}
}

void Dequeue(){
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
