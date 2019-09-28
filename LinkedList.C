#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *link;
} *header, *ptr, *ptr1, *ptr2, *new;

void traverse();
void insertfront(int);
void insertend(int);
void insertpos(int,int);
void deletefront();
void deleteend();
void deletepos(int);

void main()
{  int ch=1,data,key;
   clrscr();
   header->data = NULL;
   header->link = NULL;

   while(ch=1)
   {   printf("1. Traverse linked list.\n");
       printf("2. Insert an element at the beginning of linked list.\n");
       printf("3. Insert an element at the end of linked list.\n");
       printf("4. Insert after key.\n");
       printf("5. Delete an element from the beginning.\n");
       printf("6. Delete an element from the end.\n");
       printf("7. Delete at key.\n");
       printf("0. Exit\n");
       
       scanf("%d",&ch);
       
       switch(ch)
       {      case 1: traverse();
                      break;
              case 2: printf("Enter value of element\n");
                      scanf("%d",&data);
                      insertfront(data);
                      break;
              case 3: printf("Enter value of element\n");
                      scanf("%d",&data);
                      insertend(data);
                      break;
              case 4: printf("Enter key:");
                      scanf("%d",&key);
                      insertpos(data,key);
                      break;
              case 5: deletefront();
                      break;
              case 6: deleteend();
                      break;
              case 7: printf("Enter key:");
                      scanf("%d",&key);
                      deletepos(key);
                      break;
              case 0: exit(0);
                      break;
              default:
		        printf("ERROR!! INVALID CHOICE");
                        ch = 0;
	                break; 
       }
   }
   getch();
}

void traverse()
{
 ptr = header;
 if(ptr->link==NULL)
 {
      printf("\nERROR!! LIST EMPTY\n");
 }
 else
 {
      printf("\nHEADER \n");
      while(ptr->link != NULL)
      {
          ptr = ptr->link;
	  printf("%d \n",ptr->data);
      }
 }
}
void insertfront(int x)
{
      new = (struct node*) malloc(sizeof(struct node));
      new->link = header->link;	
      header->link = new;
      new->data = x;
}
void insertend(int x)
{
      new = (struct node*) malloc(sizeof(struct node));
      ptr = header;
      while(ptr->link != NULL)
      {
	  ptr=ptr->link;
      }
      new->link=NULL;
      new->data=x;
      ptr->link=new;
}
void insertpos(int x,int key);
{
    ptr = header;
    while(ptr->data!= key && ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    if(ptr->data == key)
    {				
	new = (struct node*) malloc(sizeof(struct node));
	new->link = ptr->link;
	ptr->link = new;
	new->data = x;
    }
    else
    {
	printf("ERROR!! KEY NOT FOUND \n");
    }
}
void deletefront()
{
    if(header->link == NULL)
    {      
	printf("ERROR!! LIST EMPTY\n");
    }
    else 
    {
	ptr=header->link;
	header->link=ptr->link;
	free(ptr);
	printf("\nNODE DELETED \n");
    }
}                
void deleteend()
{
    if(header->link == NULL)
    {
	printf("ERROR!! LIST EMPTY \n");
    }
    else
    {
	ptr2 = header;
	ptr1 = ptr2->link;
	while(ptr1->link!=NULL)
	{
            ptr2 = ptr1;
	    ptr1 = ptr1->link;
	}
	    ptr2->link = NULL;
	    free(ptr1);
	    printf("\n NODE DELETED\n");
    }
}
void deletepos(int key);
{
      if(header->link == NULL)
      {
	    printf("ERROR!! LIST EMPTY\n");
      }
      else
      {
	    ptr2 = header;
	    ptr1 = header->link;
	    while(ptr1->data!= key && ptr1->link!= NULL)
	    {
		  ptr2 = ptr1;
		  ptr1 = ptr1->link;
	    }
	    if(ptr1->data == key)
            {
	        ptr2->link = ptr1->link;
		free(ptr1);
		printf("\nNODE DELETED\n");
	    }
	    else 
	    {
		printf("ERROR!! KEY NOT FOUND\n");
	    }
      }
}
        
       
       
       
