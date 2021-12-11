#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sum()
{
    printf("how many operands?: ");
    int operandsCount = 0;
    scanf("%i", &operandsCount);
    int* operands = (int*) malloc(sizeof(int) * operandsCount);
    int i;
    for(i = 0; i < operandsCount; i++)
    {
        printf("\n%ist operand: ", i+1);
        scanf("%i", &operands[i]);
    }
    int sum = 0;
    printf("list of operands: [ ");
    for(i = 0; i < operandsCount; i++)
    {
        sum += operands[i];
        printf("%i, ", operands[i]);
    }
    printf("]\n");
    return sum;
}

int main()
{
    int result = 0;
    int run = 1; 
    while(run)
    {
        printf("choose:\n0: end\n1: sum\n2: print\n");
        int choise = -1;
        scanf("%i", &choise);
        switch (choise)
        {
        case 0:
            run = 0;
            printf("end\n");
            break;
        case 1:
            printf("sum\n");
            result = sum();
            break;
        case 2: 
            printf("print\n");
            printf("the result is: %i\n", result);
            break;
        
        default:
            printf("invalid input\n");
            break;
        }
    }
}