#include <stdio.h>
#include <stdlib.h>

int main()
{
    int scelta = 0;

    do
    {
        printf("\n======= MENU ESERCIZI PUNTATORI =======\n");
        printf("1. Esercizio Puntatori 1 (Puntatore Semplice)\n");
        printf("2. Esercizio Puntatori 2 (Puntatore Doppio)\n");
        printf("3. Esercizio Puntatori 3 (Aritmetica Puntatori)\n");
        printf("4. Esercizio Puntatori 4 (Puntatori NULL e Invalidi)\n");
        printf("5. Esci\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);

        switch (scelta)
        {

        case 1:
        {
            int var = 20;
            int *puntatore;
            puntatore = &var;

            printf("Valore della variabile: %d\n", var);
            // OSSERVA: Stampa il valore (20)

            printf("Indirizzo della variabile: %p\n", (void *)&var);
            // OSSERVA: Stampa l'indirizzo di memoria di var

            printf("Valore del puntatore puntatore: %p\n", (void *)puntatore);
            // OSSERVA: Stampa l'indirizzo di var

            printf("Valore a cui punta puntatore: %d\n", *puntatore);
            // OSSERVA: Stampa il valore (20)

            break;
        }

        case 2:
        {
            int var = 20;
            int *puntatore;
            int **doppio_puntatore;

            puntatore = &var;
            doppio_puntatore = &puntatore;

            printf("Valore della variabile: %d\n", var);
            // OSSERVA: Stampa il valore (20)

            printf("Indirizzo della variabile: %p\n", (void *)&var);
            // OSSERVA: Stampa l'indirizzo di var

            printf("Indirizzo del primo puntatore: %p\n", (void *)&puntatore);
            // OSSERVA: Stampa l'indirizzo di puntatore

            printf("Valore del doppio puntatore: %p\n", (void *)doppio_puntatore);
            // OSSERVA: Stampa l'indirizzo di puntatore

            printf("Valore a cui punta il doppio puntatore: %p\n", (void *)*doppio_puntatore);
            // OSSERVA: Stampa l'indirizzo di var

            printf("Valore a cui punta il puntatore ottenuto dal doppio puntatore: %d\n", **doppio_puntatore);
            // OSSERVA: Stampa il valore (20)

            break;
        }

        case 3:
        {

            int var1 = 10, var2 = 20, var3 = 30, i = 0;
            int *p = &var1;

            for (i = 0; i < 3; i++)
            {
                printf("Valore della variabile %d: %d\n", i + 1, *p);
                // OSSERVA: Stampa var1, var2, var3 in sequenza
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
                printf("Valore della variabile %d: %d\n", i + 1, *p);
                // OSSERVA: Stampa i valori in ordine inverso
                p--;
            }

            p++;

            printf("Inserisci un valore intero: ");
            scanf("%d", p);
            // OSSERVA: scanf usa l'indirizzo in p per modificare var1

            printf("Valore inserito: %d\n", var1);
            // OSSERVA: Stampa il nuovo valore di var1 inserito dall'utente

            break;
        }

        case 4:
        {

            printf("\n--- Esecuzione Esercizio 4 ---\n");

            int variabile_valida = 10;

            //Puntatore Nullo
            int *p_nullo = NULL;

            //Puntatore Invalido
            int *p_invalido = (int *)0x12345;

            if (p_nullo == NULL)
            {
                printf("OK: p_nullo e' NULL. Non posso usarlo.\n");
            }
            else
            {
                printf("ERRORE: Questo non dovrebbe accadere.\n");
            }
            // OSSERVA: Il controllo (p_nullo == NULL) è ture

            if (p_invalido == NULL)
            {
                printf("OK: p_invalido e' NULL.\n");
            }
            else
            {
                printf("ATTENZIONE: p_invalido NON e' NULL. (Indirizzo: %p)\n", (void *)p_invalido);
            }
            // OSSERVA: Il controllo (p_invalido == NULL) è false

            int *p_valido = NULL;
            p_valido = &variabile_valida;

            printf("Ora p_valido punta a: %p\n", (void *)p_valido);
            // OSSERVA: Stampa l'indirizzo di variabile_valida

            if (p_valido != NULL)
            {
                // OK, p_valido non è NULL, posso usarlo
                printf("OK: p_valido non e' NULL. Valore puntato: %d\n", *p_valido);
            }
            // OSSERVA: Il controllo (p_valido != NULL) è true, stampa il valore (10).
            // Il programma stampa il valore 10.

            break;
        }

        case 5:
            break;

        default:
            printf("Scelta non valida. Riprova.\n");
            break;
        }

    } while (scelta != 5);

    return 0;
}