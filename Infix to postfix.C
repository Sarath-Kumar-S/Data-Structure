#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item)
{
 if(top>=SIZE-1)
 {
  printf("\n Stack Overflow");
 }
 else
 {
  top=top+1;
  stack[top]=item;
 }
}
char pop()
{
 char item;
 if(top<0)
 {
  printf("\n Stack overflow");
  getchar();
  exit(1);
 }
 else
 {
  item=stack[top];
  top=top-1;
  return(item);
 }
}
int isoperator(char symbol)
{
 if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
 {
  return 1;
 }
 else
 {
  return 0;
 }
}
int precedence(char symbol)
{
 if(symbol=='^')
 {
  return(3);
 }
 else if(symbol=='*'||symbol=='/')
 {
  return(2);
 }
 else if(symbol=='+'||symbol=='-')
 {
  return(1);
 }
 else
 {
  return(0);
 }
}
void infixtopostfix(char infixexp[],char postfixexp[])
{
 int i,j;
 char item;
 char x;
 push('(');
 strcat(infixexp,")");
 i=0;
 j=0;
 item=infixexp[i];
 while(item!='\0')
 {
  if(item=='(')
  {
   push(item);
  }
  else if(isdigit(item)||isalpha(item))
  {
   postfixexp[j]=item;
   j++;
  }
  else if(isoperator(item)==1)
  {
   x=pop();
   while(isoperator(x)==1 && precedence(x)>=precedence(item))
   {
    postfixexp[j]=x;
    j++;
    x=pop();
   }
   push(x);
   push(item);
  }
  else if(item==')')
  {
   x=pop();
   while(x!='(')
   {
    postfixexp[j]=x;
    j++;
    x=pop();
   }
  }
  else
  {
   printf("\nInvalid exp");
   getchar();
   exit(1);
  }
  i++;
  item=infixexp[i];
 }
 if(top>0)
 {
  printf("\nInvalid exp");
  getchar();
  exit(1);
 }
 postfixexp[j]='\0';
}
int main()
{
 char infix[SIZE],postfix[SIZE];
 clrscr();
 printf("\nEnter Infix exp:-\t");
 gets(infix);
 infixtopostfix(infix,postfix);
 printf("\nPostfix exp is:-\t");
 puts(postfix);
 getch();
 return 0;
}
