#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100;

char stack[100];
int top=-1;

// function for pushing an element into a stack
void push(char item){
    stack[++top]=item;
}

// function for popping an element from the stack
char pop(){
    return stack[top--];
}

// checks whether the symbol is an operator
int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(': 
   case ')':return 1; 
        break;
    default: return 0;
        break;
    }
}

// returns precedence of operators
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':return 4;
        break;
    case '/':    
    case '*':return 3;
        break;
    case '+':        
    case '-':return 2;
        break;
    default: return 0;
        break;    
    }    
}

//reverses the string
void reverse(char *str){
    int i=0;
    int n=strlen(str);
    char temp;
    for(i=0;i<n/2;i++)
    {
     temp=str[i];
     str[i]=str[n-i-1];
     str[n-i-1]=temp;
    }
}

// converts infix expression to prefix expression
void InfixToPrefix(char infix[],char prefix[])
{   
    reverse(infix); //flag
    int i=0,j=0;
    char symbol;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(isOperator(symbol)==0)
        {
         prefix[j]=symbol;
         j++;
        }
        else
        {
            if(symbol==')')
            {
                push(symbol);
            }
            else
            {
                if(symbol=='(')
                {
                    while(stack[top]!=')') 
                    {
                        prefix[j]=pop();
                        j++;
                    }
                    pop(); //pop out ')'
                }
                else
                {
                   if(precedence(symbol)>precedence(stack[top]))
                   {
                    push(symbol);
                   }
                   else
                   {
                    while(precedence(symbol)<precedence(stack[top])){
                       prefix[j]=pop();
                       j++;
                    }
                    push(symbol); //push the symbol.
                   } 
                }
            }

        }
    }
 while(top!=-1)
 {
     prefix[j]=pop();
     j++;
    }
    prefix[j]='\0'; // null terminate string.
    reverse(prefix); //reverse the string.
}

int main(){
    char infix[25]="2*(1+2)",prefix[25];
    printf("The inifx expression is %s\n",infix);
    InfixToPrefix(infix,prefix);
    printf("The prefix expression is %s\n",prefix);
    return 0;
}
