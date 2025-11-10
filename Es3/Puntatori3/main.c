#include <stdio.h>
#include <stdlib.h>

int main(){
    int var1=10, var2=20, var3=30, i=0; 
    int *p= &var1;
    for (i = 0; i < 3; i++)
    {
        printf("Valore della variabile %d: %d\n", i+1, *p);  
        p++;
    }
    /*
    La differenza tra indirizzi di memoria dipende dal tipo di dato a cui punta il puntatore,
    quindi la distanza tra 2 indirizzi consecutivi per un tipo int è di 4 byte ed incrementando il puntatore di 1 esso si sposta di 4 byte
    SE LA STAMPA NON RISULTA CORRETTA E' PERCHE' IL COMPILATORE NON GARANTISCE CHE LE VARIABILI SIANO ALLOCATE IN ORDINE CONTIGUO IN MEMORIA
    */
        p--;
    for (i = 0; i < 3; i++)
    {
        printf("Valore della variabile %d: %d\n", i+1, *p);     
        p--;
    }
    p++;

    printf("Inserisci un valore intero: ");
    scanf("%d", p);
    printf("Valore inserito: %d\n", var1);
    return 0;
}