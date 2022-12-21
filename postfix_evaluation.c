#include <stdio.h>
#include <stdlib.h>

int stack[20];
int top = -1;

// function for pushing an element into a stack
void push(int item)
{
    stack[++top] = item;
}

// function for popping an element from the stack
int pop()
{
    return stack[top--];
}

// function to evaluate postfix expression.
int evaluate(char *postfix)
{
    int i = 0;
    char ch;
    int operand1, operand2;
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        i++;
        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0');
        }
        else
        {
            // pop the operands.
            operand2 = pop();
            operand1 = pop();
            switch (ch)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            }
        }
    }
    return stack[top];
}

int main()
{
    char postfix[25] = "12+9*";
    printf("%d", evaluate(postfix));

    return 0;
}
