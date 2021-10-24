#include <stdio.h>
#include <stdlib.h>

void sterneReihe(int n)
{
    printf("\n%d Sterne in einer Reihe:\n", n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");
}

void pyramideLinks(int n)
{
    printf("\nlinksbuendige Pyramide:\n");
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void pyramideZentriert(int n)
{
    if (n % 2 != 0)
    {
        printf("\nZentrierte Pyramide:\n");
        int spacing = n / 2;
        int i,j,k;
        for (i = 0; i < n; i = i + 2)
        {
            for (j = 0; j < spacing; j++)
            {
                printf(" ");
            }
            for (k = 0; k <= i; k++)
            {
                printf("*");
            }
            printf("\n");
            spacing--;
        }
    }
    else
    {
        printf("\nKann keine zentrierte Pyramide bauen: n ist gerade");
    }
}

int main()
{
    while (1)
    {
        int n = 0;
        printf("\ninput n (<1 to exit): ");
        scanf("%d", &n);

        if (n < 1)
        {
            break;
        }

        sterneReihe(n);
        pyramideLinks(n);
        pyramideZentriert(n);
    }

    return EXIT_SUCCESS;
}