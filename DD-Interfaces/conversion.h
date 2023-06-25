#define LOWER_F 0 /* límite inferior de fahr*/
#define UPPER_F 300 /* límite superior de fahr*/
#define STEP_F 20 /*incremento de fahr*/

#define LOWER_C -10 /*límite inferior de celsius*/
#define UPPER_C 150 /*límite superior de celsius*/
#define STEP_C 10 /*incremento de celsius*/

float fahr(float celsius);
float celsius(float farh);
void printTablas();
void printTablaCelsius();
void printTablaFahr();
void printFilas(int base,int top,int inc,float funcion(float));
void printFila(float deg,float degConverted);