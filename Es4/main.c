#include <stdio.h>
#include <stdlib.h>

float calcola_V1(float, float, char);
void calcola_V2(float, float, char, float*);
void calcola_V3(float*, float, char);

int main() {    
    int scelta = 0;

    do
    {
        printf("\n======= MENU CALCOLATRICE =======\n");
        printf("1. Parametri di solo ingresso\n");
        printf("2. Parametri di sola uscita\n");
        printf("3. Parametri di ingresso-uscita\n");
        printf("4. Esci\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);

        switch (scelta)
        {

        case 1:
        {
            float operando1, operando2;
            char operazione;
            printf("\nInserisci il primo operando\n");
            scanf("%f", &operando1);
            printf("Inserisci il secondo operando\n");  
            scanf("%f", &operando2);
            printf("Inserisci l'operazione (+, -, *, /):\n");   
            scanf(" %c", &operazione);
            float risultato = calcola_V1(operando1, operando2, operazione);
            printf("Risultato: %.2f\n", risultato);

            break;
        }

        case 2:
        {
            float operando1, operando2;
            char operazione;
            printf("\nInserisci il primo operando\n");
            scanf("%f", &operando1);
            printf("Inserisci il secondo operando\n");  
            scanf("%f", &operando2);
            printf("Inserisci l'operazione (+, -, *, /):\n");
            scanf(" %c", &operazione);
            float risultato;
            calcola_V2(operando1, operando2, operazione, &risultato);
            printf("Risultato: %.2f\n", risultato);

            break;
        }

        case 3:
        {
            float operando1, operando2;
            char operazione;
            printf("\nInserisci il primo operando\n");
            scanf("%f", &operando1);
            printf("Inserisci il secondo operando\n");  
            scanf("%f", &operando2);
            printf("Inserisci l'operazione (+, -, *, /):\n");
            scanf(" %c", &operazione);

            calcola_V3(&operando1, operando2, operazione);
            printf("Risultato: %.2f\n", operando1);

            break;
        }

        case 4:
            break;

        default:
            printf("Scelta non valida. Riprova.\n");
            break;
        }

    } while (scelta != 4);

    return 0;
}

float calcola_V1(float a, float b, char operazione) {
    switch (operazione) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Errore: Divisione per zero!\n");
                return 0; 
            }
        default:
            printf("Errore: Operazione non valida!\n");
            return 0; 
    }
    return 0;
}

void calcola_V2(float a, float b, char operazione, float* risultato) {
    switch (operazione) {
        case '+':
            *risultato = a + b;
            break;
        case '-':
            *risultato = a - b;
            break;
        case '*':
            *risultato = a * b;
            break;
        case '/':
            if (b != 0) {
                *risultato = a / b;
            } else {
                printf("Errore: Divisione per zero!\n");
                *risultato = 0; 
            }
            break;
        default:
            printf("Errore: Operazione non valida!\n");
            *risultato = 0; 
            break;
    }
    return;
}

void calcola_V3(float* a, float b, char operazione) {
    switch (operazione) {
        case '+':
            *a = *a + b;
            break;
        case '-':
            *a = *a - b;
            break;
        case '*':
            *a = (*a) * b;
            break;
        case '/':
            if (b != 0) {
                *a = (*a) / b;
            } else {
                printf("Errore: Divisione per zero!\n");
                *a = 0; 
            }
            break;
        default:
            printf("Errore: Operazione non valida!\n");
            *a = 0; 
            break;
    }
    return ;
}