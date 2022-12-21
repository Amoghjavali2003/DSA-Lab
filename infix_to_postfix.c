#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100;

char stack[100];
int top = -1;

// function for pushing an element into a stack
void push(char item)
{
    stack[++top] = item;
}

// function for popping an element from the stack
char pop()
{
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
    case ')':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

// returns precedence of operators
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 4;
        break;
    case '/':
    case '*':
        return 3;
        break;
    case '+':
    case '-':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

// converts infix expression to postfix expression.
void InfixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char symbol;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            if (symbol == '(')
            {
                push(symbol);
            }
            else
            {
                if (symbol == ')')
                {
                    while (stack[top] != '(')
                    {
                        postfix[j] = pop(); // operators sent to postfix.
                        j++;
                    }
                    pop(); // pop out '('
                }
                else
                {
                    if (precedence(symbol) > precedence(stack[top]))
                    {
                        push(symbol);
                    }
                    else
                    {
                        while (precedence(symbol) < precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(symbol); // push the symbol.
                    }
                }
            }
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0'; // null terminate string.
}

int main()
{
    char infix[25] = "2*(1+2)", postfix[25];
    InfixToPostfix(infix, postfix);
    printf("The inifx expression is %s\n", infix);
    printf("The postfix expression is %s\n", postfix);
    return 0;
}
