#include <stdio.h>
#include <stdlib.h>

int main() {
    int var = 20;   
    int *puntatore;      

    puntatore = &var;    

    printf("Valore della variabile: %d\n", var);
    printf("Indirizzo della  variabile: %p\n", &var);
    printf("Valore del puntatore puntatore: %p\n", puntatore);
    printf("Valore a cui punta puntatore: %d\n", *puntatore);

    return 0;
}