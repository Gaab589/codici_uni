#include <stdio.h>

void riempiArray(int array[], int dimensione);
void stampaArray(int array[], int dimensione);
void riempiArrayP(int *array, int dimensione);
void stampaArrayP(int *array, int dimensione);

int trovaMin(int array[], int dimensione);
int trovaMax(int array[], int dimensione);
float calcolaMedia(int array[], int dimensione);

int trovaMinP(int *array, int dimensione);
int trovaMaxP(int *array, int dimensione);
float calcolaMediaP(int *array, int dimensione);

int main() {
    int max_dim = 100;
    
    int numero = 10;
    int *puntatore = &numero;

    printf("Valore della variabile: %d\n", numero);
    printf("Indirizzo della variabile: %p\n", (void*)&numero);
    printf("Indirizzo memorizzato nel puntatore: %p\n", (void*)puntatore);
    printf("Valore puntato dal puntatore: %d\n", *puntatore);

    *puntatore = 99;
    printf("Nuovo valore della variabile: %d\n\n", numero);

    int myData[100]; 
    int n;

    do {
        printf("Inserisci la dimensione dell'array (max %d): ", max_dim);
        scanf("%d", &n);
    } while(n <= 0 || n > max_dim);

    riempiArray(myData, n);

    printf("\nStampa (Versione Array):\n");
    stampaArray(myData, n);
    
    printf("\nStampa (Versione Puntatore):\n");
    stampaArrayP(myData, n);

    int minA = trovaMin(myData, n);
    int maxA = trovaMax(myData, n);
    float mediaA = calcolaMedia(myData, n);

    int minB = trovaMinP(myData, n);
    int maxB = trovaMaxP(myData, n);
    float mediaB = calcolaMediaP(myData, n);

    printf("\nRisultati Versione A (Indici): Min %d, Max %d, Media %.2f\n", minA, maxA, mediaA);
    printf("Risultati Versione B (Puntatori): Min %d, Max %d, Media %.2f\n", minB, maxB, mediaB);

    return 0;
}

void riempiArray(int array[], int dimensione) {
    for(int i = 0; i < dimensione; i++) {
        printf("Inserisci elemento [%d]: ", i);
        scanf("%d", &array[i]);
    }
}

void stampaArray(int array[], int dimensione) {
    printf("[ ");
    for(int i = 0; i < dimensione; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void riempiArrayP(int *array, int dimensione) {
    for(int i = 0; i < dimensione; i++) {
        printf("Inserisci elemento [%d]: ", i);
        scanf("%d", (array + i)); 
    }
}

void stampaArrayP(int *array, int dimensione) {
    printf("[ ");
    for(int i = 0; i < dimensione; i++) {
        printf("%d ", *(array + i));
    }
    printf("]\n");
}

int trovaMin(int array[], int dimensione) {
    int min = array[0];
    for(int i = 1; i < dimensione; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int trovaMax(int array[], int dimensione) {
    int max = array[0];
    for(int i = 1; i < dimensione; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

float calcolaMedia(int array[], int dimensione) {
    int somma = 0;
    for(int i = 0; i < dimensione; i++) {
        somma += array[i];
    }
    return (float)somma / dimensione;
}

int trovaMinP(int *array, int dimensione) {
    int min = *array;
    for(int i = 1; i < dimensione; i++) {
        if(*(array + i) < min) {
            min = *(array + i);
        }
    }
    return min;
}

int trovaMaxP(int *array, int dimensione) {
    int max = *array;
    for(int i = 1; i < dimensione; i++) {
        if(*(array + i) > max) {
            max = *(array + i);
        }
    }
    return max;
}

float calcolaMediaP(int *array, int dimensione) {
    int somma = 0;
    for(int i = 0; i < dimensione; i++) {
        somma += *(array + i);
    }
    return (float)somma / dimensione;
}