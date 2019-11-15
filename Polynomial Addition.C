#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int coeff;
	int expo;
	struct Node* link;
};
typedef struct Node Node
Node *getnode(int coeff,int expo){
	Node *node=(Node *)malloc(sizeof(Node));
	node->coeff=coeff;
	node->expo=expo;
	node->link=NULL;
	return node;
}
void print(Node *polyhead){
	Node *poly=polyhead->link;
	if(poly!=NULL){
		printf("%dx^%d",poly->coeff,poly->expo);
		poly=poly->link;
	}
	while(poly!=NULL){
		printf(" + %dx^%d",poly->coeff,poly->expo);
		poly=poly->link;
	}
}
void creatpoly(Node *header){
	Node *node=header;
	Node *new;
	int deg,coeff,expo,i;
	printf("Enter the max deg of the polynomial: ");
	scanf("%d",&deg);
	for(i=deg;i>=0;i--){
		printf("Enter the coeff of x^%d: ",i);
		scanf("%d",&coeff);
		new=getnode(coeff,i);
		node->link=new;
		node=new;
	}
}
void polyAdd(Node *poly1,Node *poly2,Node *res){
	Node *p1=poly1->link;
	Node *p2=poly2->link;
	Node*r=res;
	int coeff;
	while(p1!=NULL && p2!=NULL){
		if(p1->expo==p2->expo){
			coeff=p1->coeff+p2->coeff;
			r->link=getnode(coeff,p1->expo);
			r=r->link;
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->expo>p2->expo){
			r->link=getnode(p2->coeff,p2->expo);
			r=r->link;
			p1=p1->link;
		}
		else{
			r->link=getnode(p2->coeff,p2->expo);
			r=r->link;
			p2=p2->link;
		}
	}
	if(p1!=NULL){
		r->link=p1;
	}
	else if(p2!=NULL){
		r->link=p2;}
}
void main(){
	Node *poly1=getnode(0,0);
	Node *poly2=getnode(0,0);
	Node *res=getnode(0,0);
	clrscr();
	creatpoly(poly1);
	creatpoly(poly2);
	polyAdd(poly1,poly2,res);
	printf("( ");
	print(poly1);
	printf(" )+( ");
	print(poly2);
	printf(" )= ");
	print(res);
	getch();
}
