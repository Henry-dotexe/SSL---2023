#include <stdio.h>
#include "conversion.h"

float fahr(float celsius){
    return ((9.0/5.0)*celsius) +32;
};

float celsius(float fahr){
    return (5.0/9.0) * (fahr-32);
};

void printTablas(){
    printTablaFahr();
    printTablaCelsius();
}
void printTablaFahr(){
    printf("Fahrenheit a Celcius\n");
    printFilas(LOWER_F,UPPER_F,STEP_F,celsius);
}
void printTablaCelsius(){
    printf("\nCelsius a Fahrenheit\n");
    printFilas(LOWER_C,UPPER_C,STEP_C,fahr);
}

void printFilas(int base,int top,int inc,float funcion(float)){
    for(int i = base; i <= top; i = i + inc){
        printFila(i,funcion(i));
    }
}
void printFila(float deg,float degConverted){
    printf("%3.0f %6.1f\n", deg, degConverted);
}