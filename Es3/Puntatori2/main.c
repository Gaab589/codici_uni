#include <stdio.h>
#include <stdlib.h>

int main() {
    int var = 20;   
    int *puntatore;
    int **doppio_puntatore;      

    puntatore = &var; 
    doppio_puntatore = &puntatore;   

    printf("Valore della variabile: %d\n", var);
    printf("Indirizzo della variabile: %p\n", &var);
    printf("Indirizzo del primo puntatore: %p\n", &puntatore);
    printf("Valore del doppio puntatore: %p\n", doppio_puntatore);
    printf("Valore a cui punta il doppio puntatore: %p\n", *doppio_puntatore);
    printf("Valore a cui punta il puntatore ottenuto dal doppio puntatore: %d\n", **doppio_puntatore);

    return 0;
}