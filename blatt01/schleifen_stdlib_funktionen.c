#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void calculateAndPrintSine(double grad){
    double gradSin = sin(grad * (M_PI / 180));
    printf("Winkel: %.0f Grad => Sinus-Funktionswert: %.3f\n", grad, gradSin);
}

void withForLoop(){
    printf("for loop:\n");
    for(double grad = 0; grad <= 360; grad += 10){
        calculateAndPrintSine(grad);
    }
}

void withWhileLoop(){
    printf("while loop\n");
    double grad = 0;
    while(grad <= 360){
        calculateAndPrintSine(grad);
        grad += 10;
    }
}

int main(){
    withForLoop();
    withWhileLoop();

    return EXIT_SUCCESS;
}