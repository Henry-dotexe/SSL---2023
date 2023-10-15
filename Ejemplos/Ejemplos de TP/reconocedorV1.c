//Este programa reconoce expresiones aritméticas válidas formadas por el alfabeto {0,1,2,3,4,5,6,7,8,9,+,-,*,/,(,)}
//Ademas respeta ciertas reglas sintácticas debido al autómata que se uso como base

#include <stdio.h>

int Tabla(int estado,int caracter);
int esNumero(int caracter);
int esOperador(int caracter);

int main(int argc, char **argv) {
    int x, estado_actual = 0;
    printf("Ingrese una expresion valida\n");
    while ( ( x=getchar() ) > 0) {

        if (x == '\n' || x == '\r') { //si End of line
            if (estado_actual == 1 || estado_actual == 4) {
                printf("ACEPTADA\n");
            } else {
                printf("RECHAZADA\n");
            }
            estado_actual = 0; //Se reinicia
            printf("Ingrese una expresion valida\n");
            continue;
        }

        estado_actual = Tabla(estado_actual, x);
        
        if (estado_actual == -1) {
            printf("RECHAZADA\n");
            printf("Ingrese una expresion valida\n");
            estado_actual = 0; //Se reinicia
        }
    }
    return 0;
}

int Tabla(int estado,int caracter){
    static int tabla[5][18] = {
        {2,-1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,1,1},
        {-1,-1,0,0,-1,0,-1,0,1,1,1,1,1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1,-1,-1,3,3,3,3,3,3,3,3,3,3},
        {-1,4,2,2,-1,2,-1,2,3,3,3,3,3,3,3,3,3,3},
        {-1,-1,0,0,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
    };
    if(esNumero(caracter)||esOperador(caracter)){
        return tabla[estado][caracter-40];
    }else{
        return -1;
    }
}

int esNumero(int caracter){
    int a = caracter-47; //Restando 47 se acotan inferiormente los numeros en tabla ascii
    if(a > 0 && a<=10){
        return 1;
    }else{
        return 0;
    }
}

int esOperador(int caracter){
    int a = caracter-40;
    if(a>=0 && a<=7&& a!=4 && a!=6){ //Restando 40, si queda 4 o 6 sería ',' y '.' respectivamente
        return 1;
    }else{
        return 0;
    }
}