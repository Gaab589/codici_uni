#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//COMMENTI OBBLIGATORI
/*
le differenze più importanti tra allocazione dinamica e statica risiedono in dove e quando vengono inizializzate
le variabili interessate.
durante l'allocazione statica esse vengono riposte nello stack e viene creata durante la compilazione del file
e lo spazio in memoria viene occupato finché non finisce l'esecuziuone del programma
durante l'allocazione dinamica la variabile viene memorizzata nell'heap e viene inizializzata durante l'esecuzione,
inoltre l'utente può decidere quando liberare la memoria utilizzata oppure se modificare la dimensione
dell'area di memoria occupata

malloc() serve per creare da zero un nuovo blocco di memoria mentre realloc() sevre per ridimensionare un blocco
già istanziato in precedenza e lo allarga pure se non c'è uno spazio subito dopo (quindi anche se il blocco non è contiguo)

il doppio puntatore è molto utile durante l'allocaizone dinamica perché ti permette di cambiare l'indirizzo di memoria
iniziale del blocco di memoria se fosse necessario
*/

void flush(){  
    int c;               
    while ((c = getchar()) != '\n' && c != EOF); 
} 

void inserisci_valori(float *, int);
void stampa_valori(float *, int);
float* aggiungi_valori(float*, int*);
float* rimuovi_valori(float*,  int*);
float* inserimento_valore(float*, int*);
float* copia_numeri_pari(float*, int, int*); 

int main(){
    int n;
    int scelta;
    
   
    printf("Inserisci la dimensione iniziale n: ");
    scanf("%d", &n);
    flush();

    float* vettore = (float *) malloc(n * sizeof(float));
    if(vettore == NULL){
        printf("Errore di memoria nell'allocazione dell'array!\n");
        return 1;
    }
    
    //è obbligatorio riempire il vettore inizialmente
    inserisci_valori(vettore, n);

    
    do {
        printf("\n---------------- MENU ----------------\n");
        printf("1) Stampa il vettore corrente\n");
        printf("2) Aggiungi valori al vettore (realloc)\n");
        printf("3) Rimuovi valori in un intervallo\n");
        printf("4) Inserisci numero prima del minimo\n");
        printf("5) Copia e stampa dei numeri pari\n");
        printf("6) Esci\n");
        printf("--------------------------------------\n");
        printf("Scelta: ");
        
        scanf("%d", &scelta);
        flush();

        switch(scelta){
            case 1:
                stampa_valori(vettore, n);
                break;

            case 2:
                vettore = aggiungi_valori(vettore, &n);
                printf("\nOperazione completata.\n");
                break;

            case 3:
                vettore = rimuovi_valori(vettore, &n);
                break;

            case 4:
                vettore = inserimento_valore(vettore, &n);
                break;

            case 5: {
                int dimensione_pari = 0;
                float* vettore_pari = copia_numeri_pari(vettore, n, &dimensione_pari);

                if (vettore_pari != NULL && dimensione_pari > 0) {
                    stampa_valori(vettore_pari, dimensione_pari);
                    free(vettore_pari); 
                } else {
                    printf("Nessun numero pari trovato.\n");
                }
                break;
            }

            case 6:
                printf("Uscita dal programma. Arrivederci!\n");
                break;

            default:
                printf("Scelta non valida! Riprova.\n");
                break;
        }
    } while(scelta != 6);

    
    if (vettore != NULL) {
        free(vettore);
    }
    
    return 0;
}


void inserisci_valori(float* p, int dimensione){
    int i;
    for(i=0; i<dimensione; i++){
        printf("Inserisci il valore numero %d: ", i+1);
        scanf("%f", (p+i));
        flush();
    }
}

void stampa_valori(float* p, int dimensione){
    int i;
    if (dimensione == 0) {
        printf("Vettore vuoto.\n");
        return;
    }
    printf("\nStampa array (Dimensione: %d):\n", dimensione);
    for(i=0; i<dimensione; i++){
        printf("[Pos %d]: %.2f\n", i, *(p+i));
    }
}

float* aggiungi_valori(float* p, int *dimensione){ 
    int k, pos, i;
    int dim_attuale = *dimensione;

    printf("Quanti elementi vuoi aggiungere (k)? ");
    scanf("%d", &k);
    flush();

    printf("A partire da quale posizione? ");
    scanf("%d", &pos);
    flush();

    int dimensione_necessaria = pos + k;
    
    if(dimensione_necessaria > dim_attuale){
        float *temp = (float*) realloc(p, dimensione_necessaria * sizeof(float));
        if (temp == NULL){
            printf("Errore critico: memoria piena!\n");
            return p; 
        }
        p = temp;
        *dimensione = dimensione_necessaria; 
    }

    printf("Inserisci i %d nuovi valori:\n", k);
    for(i=0; i<k; i++){
        printf("Nuovo valore %d: ", i+1);
        scanf("%f", (p + pos + i)); 
        flush();
    }
    
    return p;
}

float* rimuovi_valori(float* p, int* dimensione){
    int a, b;
    int dim_attuale = *dimensione;

    if (dim_attuale == 0) return p;

    do {
        printf("Inserisci l'indice di inizio (a): ");
        scanf("%d", &a);
        flush();

        printf("Inserisci l'indice di fine (b): ");
        scanf("%d", &b);
        flush();

        if (a > b || a < 0 || b >= dim_attuale) {
            printf("Indici non validi.\n");
        }
    } while (a > b || a < 0 || b >= dim_attuale);
    
    int num_rimossi = b - a + 1;
    int i;

    for(i = b + 1; i < dim_attuale; i++) {
        *(p + (i - num_rimossi)) = *(p + i);
    }

    int dimensione_nuova = dim_attuale - num_rimossi;

    if (dimensione_nuova > 0) {
        float *temp = (float*) realloc(p, dimensione_nuova * sizeof(float));
        if (temp != NULL) {
            p = temp; 
        } 
    } else {
        free(p);
        p = NULL;
    }

    *dimensione = dimensione_nuova;
    printf("Rimossi %d elementi\n", num_rimossi);
    return p;
}

float* inserimento_valore(float* p, int* dimensione){
    int dim_attuale = *dimensione;
    
    if (p == NULL || dim_attuale == 0) {
        printf("Vettore vuoto! Impossibile cercare il minimo.\n");
        return p;
    }

    float x;
    int pos_min = 0; 
    float min = FLT_MAX;
    int i;

    printf("Inserisci il valore 'x': ");
    scanf("%f", &x);
    flush();

    for(i=0; i<dim_attuale; i++){
        if(*(p + i) < min){
            min = *(p+i);
            pos_min = i;
        }
    }
    printf("Minimo trovato alla posizione %d\n", pos_min);

    float* temp = (float*) realloc(p, (dim_attuale + 1) * sizeof(float));
    if(temp == NULL){
        printf("Errore realloc\n");
        return p;
    }
    p = temp;

    for(i = dim_attuale; i > pos_min; i--){
        *(p + i) = *(p + i - 1);
    }

    *(p + pos_min) = x;
    *dimensione = dim_attuale + 1;
    
    return p;
}

float* copia_numeri_pari(float* p, int dimensione, int* dim_nuovo_array){
    int i;
    int cont = 0;

    for(i = 0; i < dimensione; i++){
        int valore_intero = (int) *(p + i);
        if(valore_intero % 2 == 0){
            cont++;
        }
    }

    if (cont == 0) {
        *dim_nuovo_array = 0;
        return NULL;
    }

    float* p_nuovo = (float*) malloc(cont * sizeof(float));
    if (p_nuovo == NULL) {
        printf("Errore allocazione nuovo array pari\n");
        return NULL;
    }

    int j = 0; 
    for(i = 0; i < dimensione; i++){
        int valore_intero = (int) *(p + i);
        if(valore_intero % 2 == 0){
            *(p_nuovo + j) = *(p + i);
            j++;
        }
    }

    *dim_nuovo_array = cont;
    return p_nuovo;
}