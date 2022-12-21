#include <stdio.h>

// function to calculate factorial of a number.
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        // function call.
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number to calculate factorial\n");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n", n, fact(n));
    return 0;
}
