#include <stdio.h>
#include <stdlib.h> // Questa libreria (o stdio.h) definisce NULL

int main() {
    
    // === Preparazione ===
    // Abbiamo bisogno di un indirizzo VALIDO a cui puntare dopo.
    int variabile_valida = 10;
    
    // === Direttiva 1: Dichiarare i puntatori ===

    // 1. Puntatore Nullo
    // NULL è una macro (spesso (void*)0) che significa "non punta a nulla".
    int *p_nullo = NULL;

    // 2. Puntatore Invalido (non nullo)
    // Assegniamo un indirizzo arbitrario (spazzatura).
    // Dobbiamo usare un "cast" (int *) per forzare il numero 
    // a essere trattato come un indirizzo.
    int *p_invalido = (int *)0x12345; 

    
    printf("--- 1. CONTROLLO PUNTATORE NULLO ---\n");
    
    // === Direttiva 2: Verificare il puntatore NULLO ===
    if (p_nullo == NULL) {
        // Il codice entra qui, perché la condizione è VERA.
        printf("OK: p_nullo e' NULL. Non posso usarlo (deferenziarlo).\n");
    } else {
        printf("ERRORE: Questo non dovrebbe accadere.\n");
        // Se provassimo a usarlo (es. printf("%d", *p_nullo);)
        // il programma andrebbe in CRASH (Segmentation Fault).
    }


    printf("\n--- 2. CONTROLLO PUNTATORE INVALIDO ---\n");

    // === Direttiva 2: Verificare il puntatore INVALIDO ===
    // Questo è il punto chiave dell'esercizio:
    if (p_invalido == NULL) {
        printf("OK: p_invalido e' NULL.\n");
    } else {
        // Il codice entra qui, perché (0x12345 != NULL)
        printf("ATTENZIONE: p_invalido NON e' NULL. (Indirizzo: %p)\n", (void*)p_invalido);
        printf("Il programma 'crede' che sia valido, ma non lo e'!\n");
        // Se provassimo a usarlo (es. printf("%d", *p_invalido);)
        // il programma andrebbe in CRASH (Segmentation Fault).
    }


    printf("\n--- 3. ASSEGNAZIONE VALIDA ---\n");

    // === Direttiva 3: Assegnare un indirizzo valido ===
    // Inizializziamo un puntatore (è buona norma inizializzarlo a NULL)
    int *p_valido = NULL;
    
    // Ora lo facciamo puntare all'indirizzo della nostra variabile
    p_valido = &variabile_valida;
    
    printf("Ora p_valido punta a un indirizzo reale: %p\n", (void*)p_valido);

    // Eseguiamo di nuovo lo stesso controllo di sicurezza
    if (p_valido == NULL) {
        printf("ERRORE: Questo non dovrebbe accadere.\n");
    } else {
        // Il codice entra qui (p_valido NON è NULL)
        printf("OK: p_valido non e' NULL. Posso usarlo in sicurezza.\n");
        
        // Ora possiamo "deferenziare" (usare '*')
        printf("Valore puntato: %d\n", *p_valido); // Stampa 10
    }

    return 0;
}