//Este programa SOLO reconoce los caracteres del alfabeto {0,1,2,3,4,5,6,7,8,9,+,-,*,/,(,)} usados para formar expresiones aritméticas 
#include <stdio.h>
#include <string.h>

struct unknownchar { //Para almacenar el carácter desconocido, la línea y columna
    char character;
    int line;
    int column;
};

int Tabla(int caracter);
void printTabla(char palabra[]);
void limpiarString(char palabra[]);
int esNumero(int caracter);
int esOperador(int caracter);

int main(int argc, char **argv) {
    int x, estado_actual = 0; char palabra[50];
    printf("Ingrese una expresion valida\n");
    while ( ( x=getchar() ) > 0) {

        if (x == '\n' || x == '\r') { //Cuando llega a End of line
            if (estado_actual == 0) { //Si acaba en un estado terminal la palabra fue aceptada
                printf("ACEPTADA\n");
                //printTabla(palabra);
            } else {
                printf("RECHAZADA\n");
                //limpiarString(palabra);
            }
            estado_actual = 0; //Se reinicia
            printf("Ingrese una expresion valida\n");
            continue;
        }
        
        estado_actual = Tabla(x);
        
        if (estado_actual == -1) {
            printf("RECHAZADA\n");
            printf("Ingrese una expresion valida\n");
            estado_actual = 0; //Se reinicia
        }
    }
    return 0;
}

void printTabla(char palabra[]){
    printf("|| En el código ||    Token   ||");
    for(int i=0;i<strlen(palabra);i++){
        if(esNumero(palabra[i])){
            printf("||\t%c\t|| Const Num ||", palabra[i]);        
        }else{
            if(esOperador(palabra[i])){
                printf("||\t%c\t|| Operador ||", palabra[i]);
            }else{ //Entonces es caracter no reconocido por el lenguaje
                //Logica para imprimir los caracteres invalidos
            }
        }
    }
    
}

void limpiarString(char palabra[]){
    palabra[0]='\0';
}

int Tabla(int caracter){
    static int tabla[18] = {0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,0,0};
    if(esNumero(caracter)||esOperador(caracter)){
        return tabla[caracter-40];
    }else{
        return -1;
    }
}

int esNumero(int caracter){
    int a = caracter-47; //Restando 47 se acotan inferiormente los 10 numeros en tabla ascii
    if(a > 0 && a<=10){
        return 1;
    }else{
        return 0;
    }
}

int esOperador(int caracter){
    int a = caracter-40; //Restando 40, si queda 4 o 6 sería ',' y '.' respectivamente
    if(a>=0 && a<=7&& a!=4 && a!=6){ //debe ser menor o igual a 7 porque luego están los números
        return 1;
    }else{
        return 0;
    }
}