//conversion of infix expression to postfix expression
//A+B->AB+
#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
void post(char infix[]);
void push(char);
char pop();

void main() //enter an infix expression
{
    char infix[25];
    printf("\nEnter the infix expression : ");
    gets(infix);
    post(infix);
    getch();
}

void push(char symb)
{
    if(top>=49)  //check overflow condition
    {
          printf("\nStack Overflow");  
         getch();
         return;
    }
    else   //to enter a symbol
    {
          top=top+1;
         stack[top]=symb;
    }
}
char pop()
{
     char item;  //check stack is empty or not
     if(top==-1)
     {
            printf("\nStack is empty");
            getch();
            return(0);
      }
      else   //to delete symbol
     {
            item=stack[top];
            top--;
     }
     return(item);
}
int preced(char ch)  //check precedence
{
      if(ch==47)
      {
             return(5);
      }
      else if(ch==42)
      {
            return(4);
      }
      else if(ch==43)
      {
             return(3);
      }
      else
      return(2);
}
void post(char infix[])  //conversion into postfix
{
      int l;
      int index=0,pos=0;
      char symbol,temp;
      char postfix[40];
      l=strlen(infix);
      push('#');
      while(index<l)
      {
             symbol=infix[index];
             switch(symbol)  //poping according to precedence of the symbol
             {
                    case '(': push(symbol);
                    break;
                    case ')': temp=pop();
                    while(temp!='(')
                    {
                            postfix[pos]=temp;
                            pos++;
                            temp=pop();
                    }
                    break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                    while(preced(stack[top])>=preced(symbol))
                    {
                            temp=pop();
                            postfix[pos]=temp;
                            pos++;
                    }
                    push(symbol);
                    break;
                    default: postfix[pos++]=symbol;
                    break;
            }
            index++;
      }
      while(top>0)
      {
               temp=pop();
               postfix[pos++]=temp;
      }
       postfix[pos++]='\0';
       puts(postfix);
       return;
}
