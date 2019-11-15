#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
	int coeff;
	int expo;
	struct Node* link;
};
typedef struct Node Node;
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
void polyMul(Node *poly1,Node *poly2,Node *res){
	Node *p1=poly1->link;
	Node *p2=poly2->link;
	Node* p;
	Node*r=res;
	int coeff,exp;
	while(p1!=NULL){
		p2=poly2->link;
		while(p2!=NULL){
			coeff=p1->coeff*p2->coeff;
			exp=p1->expo+p2->expo;
			r=res;
			while(r->link!=NULL){
				p=r->link;
				if(p->expo==exp){
					p->coeff=p->coeff+coeff;
					break;
				}
				r=r->link;
			}
			if(r->link==NULL){
				r->link=getnode(coeff,exp);
			}
			p2=p2->link;
		}
		p1=p1->link;
	}
}
void main(){
	Node *poly1=getnode(0,0);
	Node *poly2=getnode(0,0);
	Node *res=getnode(0,0);
	clrscr();
	creatpoly(poly1);
	creatpoly(poly2);
	polyMul(poly1,poly2,res);
	printf("( ");
	print(poly1);
	printf(" )*( ");
	print(poly2);
	printf(" )= ");
	print(res);
	getch();
}
