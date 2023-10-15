/**
 * Ejemplo de autómata finito determinístico que 
 * reconoce el lenguaje aa|aba*
*/
#include <stdio.h>

int T(int q, int x);

int main(int argc, char **argv) {
    int x;
    int estado_actual = 0;

    while ( ( x=getchar() ) > 0) {
        if (x == '\n' || x == '\r') {
            if (estado_actual == 2 || estado_actual == 3) {
                printf("ACEPTADA\n");
            } else {
                printf("RECHAZADA\n");
            }
            estado_actual = 0;
            continue;
        }

        printf("%d -> %c -> ", estado_actual, x);
        estado_actual = T(estado_actual, x);
        printf("%d\n", estado_actual);
        
        if (estado_actual == -1) {
            printf("RECHAZADA\n");
            estado_actual = 0;
        }
    }

    return 0;
}

int T(int q, int x) {
    static int tabla[4][2] = {
        { 1, -1},
        { 1,  2},
        { 3,  2},
        {-1, -1}
    };
   return tabla[q][x-97];
}