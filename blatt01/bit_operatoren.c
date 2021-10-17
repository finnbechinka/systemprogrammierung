#include <stdlib.h>
#include <stdio.h>

int setBits(int x, int mask)
{
    return x | mask;
}

int offBits(int x, int mask)
{
    return x & (~mask);
}

int checkForBits(int x, int mask)
{
    return (x & mask) == mask;
}

int main()
{
    int x;
    int mask;
    int badInput = 1;
    do
    {
        printf("\ninput x: ");
        scanf("%d", &x);
        printf("\ninput mask: ");
        scanf("%d", &mask);
        badInput = 0;
    } while (badInput);

    if (checkForBits(x, mask))
    {
        printf("\nbits match");
    }
    else
    {
        printf("\nbits dont match");
    }
    printf("\nsetBits: %d", setBits(x,mask));
    printf("\noffBits: %d", offBits(x,mask));
    return EXIT_SUCCESS;
}