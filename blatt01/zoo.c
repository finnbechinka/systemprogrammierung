#include <stdlib.h>
#include <stdio.h>

#define ANIMALCOUNT 10

typedef enum viech
{
    MAMMAL = 110,
    FISH = 104,
    BIRD = 101,
    AMPHIBIAN = 102,
    REPTILE = 100
} Viech;

typedef struct animal
{
    Viech species;
    char name[25];
    unsigned int age;
    float food_weight;
} Animal;

Animal zoo[ANIMALCOUNT] = {{.species = MAMMAL, .name = 'a', .age = 3, .food_weight = 5},
                           {.species = FISH, .name = 'b', .age = 4, .food_weight = 6},
                           {.species = BIRD, .name = 'c', .age = 5, .food_weight = 7},
                           {.species = REPTILE, .name = 'd', .age = 6, .food_weight = 8}};

float calculate_average_age()
{
    float sum;
    int count;
    int i;
    for (i = 0; i < ANIMALCOUNT; i++)
    {
        char x;
        if (zoo[i].name[0] != x)
        {
            sum += zoo[i].age;
            count++;
        }
    }
    printf("%f , %d\n", sum, count);
    return sum / count;
}

void more_food()
{
    int i;
    for (i = 0; i < ANIMALCOUNT; i++)
    {
        char x;
        if (zoo[i].name[0] != x)
        {
            printf("%.2f\n", zoo[i].food_weight);
            zoo[i].food_weight = zoo[i].food_weight * ((float)zoo[i].species / 100);
            printf("%.2f\n", zoo[i].food_weight);
        }
    }
}

void print_animal(int index)
{
    printf("\nAnimal      : %d", index);
    printf("\nSpecies     : %d", zoo[index].species);
    printf("\nAge         : %d", zoo[index].age);
    printf("\nFood weight : %.2f", zoo[index].food_weight);
}

void print_zoo()
{
    printf("\nprint_zoo:\n------------");
    int i;
    for (i = 0; i < ANIMALCOUNT; i++)
    {
        char x;
        if (zoo[i].name[0] != x)
        {
            print_animal(i);
            printf("\n------------");
        }
    }
}

int main()
{
    print_zoo();
    
    return EXIT_SUCCESS;
}