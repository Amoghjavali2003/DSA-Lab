#include <stdio.h>

// Tower Of Hanoi
// TOH(A,B,C)-->TOH(source,using,destination)
void TOH(int n, char from_rod, char aux_rod, char to_rod)
{
    if (n > 0)
    {
        TOH(n - 1, from_rod, to_rod, aux_rod);
        printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
        TOH(n - 1, aux_rod, from_rod, to_rod);
    }
}
int main()
{
    int n = 4;
    // Function Call.
    TOH(n, 'A', 'B', 'C');
    return 0;
}
