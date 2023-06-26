#include <assert.h>
#include "conversion.h"
#define EPSILON 0.00001 
//Se define un epsilon (valor muy cercano a cero) para poder hacer la comparación entre float y double en el assert.

int main(){
    assert((fahr(-10)-14.000000)<EPSILON);
    assert((celsius(60)-15.555556)<EPSILON);
    return 0;
}