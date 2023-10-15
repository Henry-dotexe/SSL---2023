#include <stdio.h>
#include <ctype.h>
#include <stdbool.h> // Incluimos la biblioteca bool

bool esOperador(char caracter); 

int Tabla(int caracter){
    static int tabla[18] = {0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,0,0,0,0}; //Tabla de transiciones del automata sin restricciones
    if(isdigit(caracter)||esOperador(caracter)){
        return tabla[caracter-40];
    }else{
        return -1;
    }
}

int esExpresionValida(char expresion[]) {
   int i=0,estado_actual=0;
    while(i < 100){ //Recorremos la palabra caracter a caracter hasta el ultimo elemento del string (100 es el tamaño del string)
        
        if(i!=0){ //Para descartar expresion vacía
            if(expresion[i]=='\0' || expresion[i]=='\n'){
                if(estado_actual==0){ //estado_actual==estado_final
                    return true; //Retornamos true
                }else{
                    return false; //Retornamos false
                }
            }
        }
        
        estado_actual=Tabla(expresion[i]);
        if(estado_actual==-1){ //Hubo transición por un caracter inválido
            return false; //Retornamos false
        }
        i++;
    }

}

void analizarExpresion() {
    // Esta función realiza el análisis de una expresión aritmética ingresada por el usuario
    char expresion[100];
    while(expresion[0]!='x'){
        printf("Ingrese una expresion aritmetica: ");
        fgets(expresion,sizeof(expresion),stdin);
        //scanf("%99s", expresion); // Limitamos la entrada a 99 caracteres para evitar desbordamientos

        if (esExpresionValida(expresion)) {
            // Si la expresión es válida, realizamos el análisis y mostramos los resultados
            printf("Analisis de la expresion:\n");
            printf("Caracter  |  Token\n");
            printf("-----------------\n");

            int i = 0;
            while (expresion[i] != '\0' && expresion[i]!='\n') {
                if (isdigit(expresion[i])) {
                    // Si el carácter es un dígito, se procesa como un número
                    int j = i;
                    while (isdigit(expresion[j])) {
                        j++;
                    }
                    printf("   ");
                    while (i < j) {
                        printf("%c", expresion[i]);
                        i++;
                    }
                    printf("  |  Numero\n");
                } else if (esOperador(expresion[i])) {
                    // Si el carácter es un operador, se procesa como tal
                    printf("   %c     |  Operador\n", expresion[i]);
                    i++;
                } 
            }
            printf("\n");
        } else {
            // Si la expresión no es válida, mostramos caracteres no reconocidos
            for (int i = 0; expresion[i] != '\0'; i++) {
                char c = expresion[i];
                if (!isdigit(c) && !esOperador(c) && c!='\n') {
                    printf("Caracter: %c, Ubicacion: %d\n", c, i + 1);
                }
            }
            printf("\n");
        }
    }
}

bool esOperador(char caracter) {
    // Esta función verifica si un carácter es un operador válido
    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/' || caracter == '(' || caracter == ')') { 
        return true;
    } else {
        return false; // Si no es un operador válido, retornamos falso
    }
}

int main() {
    // Función principal que llama a analizarExpresion
    
    analizarExpresion();
    return 0;
}

