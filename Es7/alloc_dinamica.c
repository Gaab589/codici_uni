#include <stdio.h>
#include <stdlib.h>

void flush(){                 
    while (getchar() != '\n'); 
} 

void inserisci_valori(float *, int);
void stampa_valori(float *, int);
float* aggiungi_valori(float*, int*);
float* rimuovi_valori(float*,  int*);

//RICORDA GAB, non perdere il puntatore al primo indirizzo di memoria dell'array allocato dinamicamente
//perché il m omento che devi liberare con free() la memoria, devi passarci il primo indirizzo al suo interno
//altrimenti non liberi totalmente l'area di memoria
int main(){
    int n;
    printf("Inserisci la dimensione n: \n");
    scanf("%d", &n);
    flush();

    float* vettore = (float *) malloc(n*sizeof(float));
    if(vettore== NULL){
        printf("Errore di memoria nell'allocazione dell'array!\n");
    }

    inserisci_valori(vettore, n);
    stampa_valori(vettore, n);
    vettore = aggiungi_valori(vettore, &n);
    vettore = rimuovi_valori(vettore, &n); //arrivato qui, devi implementare la parte3

    free(vettore);
}

void inserisci_valori(float* p, int dimensione){
    int i;
    for(i=0; i<dimensione; i++){
        printf("Inserisci il valore numero %d :", i+1);
        scanf("%f", (p+i));
        flush();
    }
    return;
}

void stampa_valori(float* p, int dimensione){
    int i;
    for(i=0; i<dimensione; i++){
        printf("Posizione numero %d:", i+1);
        printf("%.2f\n", *(p+i));
    }
    return;
}

float* aggiungi_valori(float* p, int *dimensione){
    /*
    int i, k, pos;
    printf("Di quanti valori vuoi espandere l'array?\n");
    scanf("%d", &k);
    flush();
    float* vettore2 = (float*) malloc(k*sizeof(float));
    inserisci_valori(vettore2, k);

    printf("A che posizione del primo vettore vuoi iniziare a inserire i dati?\n");
    scanf("%d", &pos);
    flush();

    int dimensione_necessaria= pos + k;
    if(dimensione_necessaria> dimensione){
        float *temp = realloc(p, dimensione_necessaria*sizeof(float));
        if (temp == NULL){
            printf("Errore di memoria!");
        }
    }

    for (i=0; i<dimensione_necessaria; i++){
        if(i<pos){
            *temp = *p;
        }else{
            *temp = * vettore2;
            pos++;
        }
        p++;
        temp++;
    }

    p=temp;
    dimensione=dimensione_necessaria;

    */

    int k, pos, i;
    int dim_attuale = *dimensione; // Leggo il valore puntato

    printf("Quanti elementi vuoi aggiungere (k)? \n");
    scanf("%d", &k);
    flush();

    printf("A partire da quale posizione? \n");
    scanf("%d", &pos);
    flush();

    // Calcolo nuova dimensione necessaria
    // Se voglio scrivere alla pos 10 e inserire 2 elementi, arrivo a 12.
    int dimensione_necessaria = pos + k;

    // Se la nuova dimensione supera quella attuale, devo espandere
    if(dimensione_necessaria > dim_attuale){
        printf("[DEBUG] Realloc da %d a %d float...\n", dim_attuale, dimensione_necessaria);
        
        float *temp = (float*) realloc(p, dimensione_necessaria * sizeof(float));
        
        if (temp == NULL){
            printf("Errore critico: memoria piena!\n");
            // In caso di errore, ritorno il puntatore vecchio (o gestisci l'uscita)
            return p; 
        }
        
        p = temp; // Aggiorno il puntatore locale
        *dimensione = dimensione_necessaria; // Aggiorno la dimensione nel MAIN
    }

    // Inserimento dei K elementi
    printf("Inserisci i %d nuovi valori:\n", k);
    for(i = 0; i < k; i++){
        printf("Nuovo valore %d: ", i+1);
        
        // LOGICA ARITMETICA PUNTATORI:
        // Base (p) + Offset Iniziale (pos) + Scorrimento corrente (i)
        scanf("%f", (p + pos + i));
        flush();
    }

    // Ritorno il nuovo indirizzo al main
    return p;
}
