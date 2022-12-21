#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stack[25];
int top=-1;

// function for pushing an element into a stack
void push(int item)
{
 stack[++top]=item;
}

// function for popping an element from the stack
int pop()
{
    return stack[top--];
}

//function to reverse expression.
void reverse(char* str)
{
    int i;
    int n=strlen(str);
    char temp;
    for(i=0;i<n/2;i++)
    {
     temp=str[i];
     str[i]=str[n-i-1];
     str[n-1-i]=temp;
    }
}

// function to evaluate prefix expression.
int evaluate(char *prefix)
{
    reverse(prefix);
    int i=0,operand1,operand2;
    char ch;
    while(prefix[i]!='\0')
    {
        ch=prefix[i];
        i++;
         if (ch >= '0' && ch <= '9')
        {
            push(ch-'0');
        }
        else
        {
            operand1=pop();
            operand2=pop();

            switch (ch)
            {
                case '+':push(operand1+operand2);
                        break;
                case '-':push(operand1-operand2);
                        break;
                case '*':push(operand1*operand2);
                        break;
                case '/':push(operand1/operand2);
                        break;  
                default:break;                                             
            }
        }
    }
return stack[top];
}

int main()
{
    char prefix[]="*5+12";
    printf("%d",evaluate(prefix));
    return 0;
}
