#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE];
int top=-1;

//function to check if the stack is full.
int isFull()
{
if(top==SIZE)
 {
    return 1;
 }
 return 0;
}

//function to check if the stack is empty.
int isEmpty()
{
if(top==-1)
{
    return 1;
}
return 0;
}

//function for pushing an element into a stack
void push(int item)
{
    if(isFull())
    {
        printf("Stack is full!.Cannot perform push operation.\n");
    }
    else
    {
        stack[++top]=item;
    } 
}


//function for popping an element from the stack
int pop()
{
    if(isEmpty())
    {
        printf("Stack is empty!.Cannot perform pop operation.\n");
    }
    else
    {
        return stack[top--];
    } 
}

//function to peek an element from the stack
void peek()
{
    printf("The top element of the stack is %d\n",stack[top]);
}

//function for display elements from the stack
void display()
{
    int i=0;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}



int main()
{
    int value,choice;
   
    while(1){
    printf("****MENU****\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.display\n5.exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the value\n");
                scanf("%d",&value);
                push(value);
                break;
        case 2: printf("The popped element is %d\n",pop());
                break;
        case 3: peek();
                break;
        case 4: display();
                break;   
        case 5: exit(0);                       
        default:printf("Invalid Choice\n");
                break;
        }
    }
return 0;
}
