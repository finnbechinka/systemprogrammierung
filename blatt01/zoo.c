#include <stdlib.h>
#include <stdio.h>

#define ANIMALCOUNT 10

typedef enum viech
{
    MAMMAL,
    FISH,
    BIRD,
    AMPHIBIAN,
    REPTILE
} Viech;

typedef struct animal
{
    Viech species;
    char name[25];
    unsigned int age;
    float food_weight;
} Animal;

Animal zoo[ANIMALCOUNT] = {{MAMMAL, 'a', 3, 5},
                           {FISH, 'b', 4, 6},
                           {BIRD, 'c', 5, 7},
                           {AMPHIBIAN, 'd', 6, 8}};

int main()
{
    
    return EXIT_SUCCESS;
}