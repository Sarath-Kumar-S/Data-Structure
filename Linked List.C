#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<process.h>

struct node 
{ int DATA;
  struct node *LINK;
} *HEADER,*ptr,*ptr1,*current,*temp;

struct node* createNode(int data)
{   temp = malloc(sizeof(struct node));
	  if(temp == NULL)
    { print("NO MEMORY AVAILABLE");
		  exit(0);
	  }
  	else
    { temp->DATA = data;
	    temp->LINK = NULL;
	  }
	  return temp;
}

void Traverse()
{
  	ptr = HEADER->LINK;
	  printf("\nTRAVERSAL:");
	  printf("\n*HEADER\n");
	  while(ptr!=NULL)
    {
		  printf("%d",ptr->DATA);
		  ptr=ptr->LINK;
	  }
}

void insertFront(struct node* current) 
{
	  current->LINK = HEADER->LINK;
	  HEADER->LINK = current;
}

void main()
{   int ch,x;
	  clrscr();

	  HEADER->DATA = NULL; // Initialize SL
	  HEADER->LINK = NULL;

	while(1) 
  {
	/*
	printf("\nENTER A CHOICE:\n");     //MENU
	printf("\n1 - VIEW LINKED LIST");
	printf("\n2 - INSERT NODE AT FRONT");
	printf("\n3 - INSERT NODE AT END");
	printf("\n4 - INSERT NODE AT KEY");
	printf("\n0 - EXIT");
	printf("\n\n::");
	*/

	scanf("%d",&ch);

	switch(ch)
  {
		case 1:	Traverse();
			break;
		case 2:	printf("ENTER DATA");
			scanf("%d",&x);
			current = createNode(x);
			insertFront(current);
			break;
		case 0:	exit(0);
		default:
			printf("!ERROR: INVALID CHOICE");
			exit(0);
	}

	} // ENDWHILE
	getch();
}
