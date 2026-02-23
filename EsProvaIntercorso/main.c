#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[MAX];
    char cognome[MAX];
    int tipo;
    int numero_prenotati;
    int data;
} Prenotazione;

// Prototipi
void inserisciPrenotazioni(Prenotazione* p, int dimensione);
void stampaPrenotazioni(Prenotazione* p, int dimensione);

int main() {
    int n;
    printf("Quante prenotazioni vuoi inserire? ");
    scanf("%d", &n);

    Prenotazione* p = (Prenotazione*)malloc(sizeof(Prenotazione) * n);
    
    if (p == NULL) {
        printf("Errore allocazione memoria.\n");
        return 1;
    }

    inserisciPrenotazioni(p, n);
    stampaPrenotazioni(p, n);

    free(p); 
    return 0;
}

void inserisciPrenotazioni(Prenotazione* p, int dimensione) {
    for (int i = 0; i < dimensione; i++) {
        printf("\n--- Inserimento Prenotazione %d ---\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", (p + i)->nome); 
        
        printf("Cognome: ");
        getchar(); // Pulisce il carattere '\n' rimasto nel buffer dallo scanf precedente
        fgets((p + i)->cognome, MAX, stdin);
        (p + i)->cognome[strcspn((p + i)->cognome, "\n")] = 0; // Rimuove lo '\n' finale di fgets

        printf("Tipo (0=Eserc., 1=Esame): ");
        scanf("%d", &((p + i)->tipo)); // Necessaria & per variabili int
        
        printf("Numero prenotati: ");
        scanf("%d", &((p + i)->numero_prenotati));
        
        printf("Data (AAAAMMGG): ");
        scanf("%d", &((p + i)->data));
    }
}